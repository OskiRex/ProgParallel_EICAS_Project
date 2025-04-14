#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QHBoxLayout>
#include "FCTL_EICAS.h"
#include "airsystemwindow.h"
#include "EICAS_Alertas.h"
#include "EICAS_DataReader.h"
#include "airsystem_hybrid.cpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // === VENTANA 1 ===
    QMainWindow *ventana1 = new QMainWindow();
    Ui::FormEICAS uiEICAS_FCTL;
    uiEICAS_FCTL.setupUi(ventana1);
    ventana1->setWindowTitle("Ventana 1 - EICAS FCTL");

    // === VENTANA 2 ===
    QMainWindow *ventana2 = new QMainWindow();
    Ui::AirSystemWindow interfaz;
    interfaz.setupUi(ventana2);  // Cargar interfaz al widget
    ventana2->setWindowTitle("Ventana 2 - Air System");

    // === VENTANA 3 ===
    QMainWindow *ventana3 = new QMainWindow();
    Ui::EICAS_Alertas uiEICAS_Alertas;
    uiEICAS_Alertas.setupUi(ventana3);
    ventana3->setWindowTitle("Ventana 3 - Alerts");

    // Mostrar las tres ventanas
    ventana1->move(0, 0);   // Posición en pantalla
    ventana2->move(810, 0);  // Ajusta para que no se sobrepongan
    ventana3->move(810, 500); // Posición tercera ventana

    ventana1->show();
    ventana2->show();
    ventana3->show();

    // Lógica de datos
    EICAS_DataReader reader;
    reader.cargarCSV("AM2460_39a8cda3.csv");

    return app.exec();
}