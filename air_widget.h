#ifndef AIR_WIDGET_H
#define AIR_WIDGET_H

#include <QWidget>


#include <QLabel>
#include <QTimer>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui {
class AIR_Widget;
}
QT_END_NAMESPACE

class AIR_Widget : public QWidget
{
    Q_OBJECT

public:
    AIR_Widget(QWidget *parent = nullptr);
    ~AIR_Widget();

private:
    Ui::AIR_Widget *ui;

    // Variables para la lectura del archivo AIR
    QTimer *timerAIR;
    QFile archivoAIR;
    QTextStream streamAIR;

    // Declaración para permitir que otros archivos (como main_AIR.cpp) la vean
    void procesarAIRSlave(int rankAIR);


    // Función que leerá cada línea del archivo cada 24ms
    void leerSiguienteLineaAIR();

    int contadorFilasAIR = 0; // Cuenta cuántas filas se han leído

    QLabel *alertaAIR;

    // Labels de temperatura real
    QLabel *fltDeckReal;
    QLabel *zoneAReal;
    QLabel *zoneBReal;
    QLabel *zoneCReal;
    QLabel *zoneDReal;
    QLabel *fwdTemp;
    QLabel *aftTemp;
    QLabel *bulkTemp;
};
#endif // AIR_WIDGET_H
