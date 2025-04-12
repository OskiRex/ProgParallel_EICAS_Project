/*#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include "EICAS_Alertas.h"
#include "EICAS_DataReader.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    Ui::EICAS_Alertas interfaz;

    interfaz.setupUi(&window);

    window.show();

    EICAS_DataReader reader;

    /*QObject::connect(&reader, &EICAS_DataReader::alertaActivada,
                     &interfaz, &EICAS_Alertas::mostrarAlerta);

    QObject::connect(&reader, &EICAS_DataReader::alertaDesactivada,
                     &interfaz, &EICAS_Alertas::desactivarAlerta);*/


    /*reader.cargarCSV("AM2460_39a8cda3.csv");

    return app.exec();
}
*/

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStackedWidget>

// Interfaz de Usuario 1 (diseñada directamente en código)
class Interfaz1 : public QWidget {
public:
    Interfaz1(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *label = new QLabel("Esta es la Interfaz 1");
        QPushButton *botonIrA2 = new QPushButton("Ir a Interfaz 2");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(botonIrA2);
        setLayout(layout);

        connect(botonIrA2, &QPushButton::clicked, this, [this]() {
            QStackedWidget *stackedWidget = qobject_cast<QStackedWidget *>(parentWidget());
            if (stackedWidget) {
                stackedWidget->setCurrentIndex(1); // Cambiar al índice de Interfaz 2
            }
        });
    }
};

// Interfaz de Usuario 2 (diseñada directamente en código)
class Interfaz2 : public QWidget {
public:
    Interfaz2(QWidget *parent = nullptr) : QWidget(parent) {
        QLabel *label = new QLabel("¡Has llegado a la Interfaz 2!");
        QPushButton *botonIrA1 = new QPushButton("Volver a Interfaz 1");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(label);
        layout->addWidget(botonIrA1);
        setLayout(layout);

        connect(botonIrA1, &QPushButton::clicked, this, [this]() {
            QStackedWidget *stackedWidget = qobject_cast<QStackedWidget *>(parentWidget());
            if (stackedWidget) {
                stackedWidget->setCurrentIndex(0); // Cambiar al índice de Interfaz 1
            }
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget mainWindow;
    QVBoxLayout *mainLayout = new QVBoxLayout(&mainWindow);
    QStackedWidget *stackedWidget = new QStackedWidget();

    Interfaz1 *interfaz1 = new Interfaz1();
    Interfaz2 *interfaz2 = new Interfaz2();

    stackedWidget->addWidget(interfaz1); // Índice 0
    stackedWidget->addWidget(interfaz2); // Índice 1

    // Interfaz de control (botones para cambiar)
    QWidget *controlWidget = new QWidget();
    QHBoxLayout *controlLayout = new QHBoxLayout(controlWidget);
    QPushButton *botonMostrar1 = new QPushButton("Mostrar Interfaz 1");
    QPushButton *botonMostrar2 = new QPushButton("Mostrar Interfaz 2");
    controlLayout->addWidget(botonMostrar1);
    controlLayout->addWidget(botonMostrar2);

    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(controlWidget);

    QObject::connect(botonMostrar1, &QPushButton::clicked, stackedWidget, [stackedWidget]() {
        stackedWidget->setCurrentIndex(0);
    });

    QObject::connect(botonMostrar2, &QPushButton::clicked, stackedWidget, [stackedWidget]() {
        stackedWidget->setCurrentIndex(1);
    });

    mainWindow.setWindowTitle("Cambio de Interfaces");
    mainWindow.show();

    return app.exec();
}
