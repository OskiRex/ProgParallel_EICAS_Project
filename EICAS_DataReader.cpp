#include "EICAS_DataReader.h"
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>

EICAS_DataReader::EICAS_DataReader(QObject *parent)
    : QObject(parent),
      indiceActual(0),
      tiempoVirtual(0)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &EICAS_DataReader::leerLinea);
    timer->start(24); // leer datos cada 24 ms

    condiciones = {
        {"TAXI SPEED EXCEEDED", "Warning", "red", false,
         [](const VueloData &d, const VueloData &) {
             return d.altitude == 0 && d.speed > 15;
         }},

        {"UNSTABLE CLIMB", "Caution", "orange", true,
         [](const VueloData &a, const VueloData &b) {
             return a.altitude > b.altitude && a.speed < b.speed;
         }},

        {"CRUISE SPEED LOW", "Caution", "orange", true,
         [](const VueloData &a, const VueloData &) {
             return a.altitude > 10000 && a.speed < 400;
         }},

        {"UNEXPECTED HEADING CHANGE", "Caution", "orange", true,
         [](const VueloData &a, const VueloData &b) {
             return qAbs(a.direction - b.direction) > 30;
         }},

        {"CLIMB INTERRUPTION", "Caution", "orange", true,
         [](const VueloData &a, const VueloData &b) {
             return a.altitude <= b.altitude;
         }},

        {"RAPID DESCENT", "Warning", "red", false,
         [](const VueloData &a, const VueloData &b) {
             return (b.altitude - a.altitude) > 2000;
         }},

        {"AUTOPILOT DISENGAGED", "Advisory", "orange", true,
         [](const VueloData &a, const VueloData &) {
             return a.altitude > 500 && a.speed < 200;
         }},

        {"TCAS OFF", "Advisory", "orange", true,
         [](const VueloData &a, const VueloData &) {
             return a.speed > 300 && a.direction > 270;
         }},

        {" •ATC", "communication", "white", false,
         [](const VueloData &a, const VueloData &) {
             return a.callsign.isEmpty(); // Simula pérdida de comunicación
         }},

        {"APU RUNNING", "memo", "white", true,
         [](const VueloData &a, const VueloData &) {
             return a.altitude > 1000 && a.speed < 100; // Ejemplo
         }},

        {"RECALL", "RECALLindication", "white", true,
         [](const VueloData &, const VueloData &) {
             return false; // Control manual
         }},
    };
}

void EICAS_DataReader::cargarCSV(const QString &nombreArchivo)
{
    QFile archivo(nombreArchivo);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&archivo);
    QString header = in.readLine();

    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList partes = linea.split(',');

        if (partes.size() >= 7) {
            VueloData data;
            data.timestamp = partes[0].trimmed();
            data.utc = partes[1].trimmed();
            data.callsign = partes[2].trimmed();
            data.position = partes[3].trimmed();
            data.altitude = partes[4].trimmed().toInt();
            data.speed = partes[5].trimmed().toInt();
            data.direction = partes[6].trimmed().toInt();
            datos.append(data);
        }
    }
}

void EICAS_DataReader::leerLinea()
{
    if (indiceActual >= datos.size()) return;

    const VueloData &actual = datos[indiceActual];
    const VueloData &previo = datos[qMax(0, indiceActual - 1)];

    #pragma omp parallel for
    for (int i = 0; i < condiciones.size(); ++i) {
        const CondicionAlerta &condicion = condiciones[i];
        bool activa = condicion.condicion(actual, previo);

        #pragma omp critical
        {
            if (activa && !alertasActivadas.contains(condicion.nombre)) {
                alertasActivadas.insert(condicion.nombre);
                emit alertaActivada(condicion.nombre, condicion.tipo, condicion.color, tiempoVirtual);
            } else if (!activa && alertasActivadas.contains(condicion.nombre) && !condicion.cancelable) {
                alertasActivadas.remove(condicion.nombre);
                emit alertaDesactivada(condicion.nombre);
            }
        }
    }

    indiceActual++;
    tiempoVirtual += 24;
}
