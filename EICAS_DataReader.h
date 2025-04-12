#ifndef EICAS_DATAREADER_H
#define EICAS_DATAREADER_H

#include <QObject>
#include <QVector>
#include <QSet>
#include <QString>
#include <functional>

// Estructura que representa cada fila del archivo de datos
struct VueloData {
    QString timestamp;
    QString utc;
    QString callsign;
    QString position;
    int altitude;
    int speed;
    int direction;
};

// Estructura que representa una condición de alerta
struct CondicionAlerta {
    QString nombre;   // Texto de la alerta
    QString tipo;     // Tipo (Warning, Caution, Advisory, etc.)
    QString color;    // Color asociado
    bool cancelable;  // Si puede cancelarse con el botón
    std::function<bool(const VueloData&, const VueloData&)> condicion; // Lógica para activación
};

class EICAS_DataReader : public QObject {
    Q_OBJECT

public:
    explicit EICAS_DataReader(QObject *parent = nullptr);
    void cargarCSV(const QString &nombreArchivo); // Carga los datos del archivo CSV

signals:
    void alertaActivada(const QString &mensaje, const QString &tipo, const QString &color, int tiempoVirtual);
    void alertaDesactivada(const QString &mensaje);

private slots:
    void leerLinea(); // Llamado cada 24 ms para leer y evaluar condiciones

private:
    QVector<VueloData> datos;            // Todas las filas del CSV
    QVector<CondicionAlerta> condiciones; // Lista de condiciones configuradas
    QSet<QString> alertasActivadas;      // Alertas actualmente visibles
    QSet<QString> alertasCanceladas;     // Alertas que han sido canceladas
    int indiceActual;                    // Posición actual en el archivo CSV
    quint64 tiempoVirtual;              // Tiempo simulado en ms (para propósitos de sincronización)

    // Puedes agregar esta función si deseas modularizar la evaluación
    // void procesarCondiciones(const VueloData &actual, const VueloData &previo);
};

#endif // EICAS_DATAREADER_H
