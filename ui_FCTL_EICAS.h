/********************************************************************************
** Form generated from reading UI file 'FCTL_EICAS.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCTL_EICAS_H
#define UI_FCTL_EICAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEICAS
{
public:
    QSlider *SliderB;
    QSlider *SliderA;
    QSlider *Slider_C;
    QSlider *Slider_D;
    QSlider *Slider_E;
    QSlider *Slider_F;
    QSlider *Slider_ha;
    QSlider *Slider_hb;
    QSlider *Slider_G;
    QLCDNumber *lcdNumber_a;
    QLCDNumber *lcdNumber_b;
    QPushButton *pushButton_FCTL;
    QPushButton *pushButton_FUEL;
    QPushButton *pushButton_FIRE;
    QLabel *label_R;
    QLabel *label_RF;
    QLabel *label_LF;
    QLabel *label_RA;
    QLabel *label_LA;
    QLabel *label_RT;
    QLabel *label_LE;
    QLabel *label_RE;

    void setupUi(QWidget *FormEICAS)
    {
        if (FormEICAS->objectName().isEmpty())
            FormEICAS->setObjectName(QString::fromUtf8("FormEICAS"));
        FormEICAS->resize(800, 600);
        FormEICAS->setStyleSheet(QString::fromUtf8("background-image: url(:/~/Documents/ProgParallel_Projectva/images/FCTL_EICAS.jpg);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"background-size: contain;"));
        SliderB = new QSlider(FormEICAS);
        SliderB->setObjectName(QString::fromUtf8("SliderB"));
        SliderB->setGeometry(QRect(175, 145, 45, 100));
        SliderB->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        SliderB->setOrientation(Qt::Vertical);
        SliderA = new QSlider(FormEICAS);
        SliderA->setObjectName(QString::fromUtf8("SliderA"));
        SliderA->setGeometry(QRect(33, 145, 45, 100));
        SliderA->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        SliderA->setOrientation(Qt::Vertical);
        Slider_C = new QSlider(FormEICAS);
        Slider_C->setObjectName(QString::fromUtf8("Slider_C"));
        Slider_C->setGeometry(QRect(565, 140, 45, 100));
        Slider_C->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_C->setOrientation(Qt::Vertical);
        Slider_D = new QSlider(FormEICAS);
        Slider_D->setObjectName(QString::fromUtf8("Slider_D"));
        Slider_D->setGeometry(QRect(708, 142, 45, 100));
        Slider_D->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_D->setOrientation(Qt::Vertical);
        Slider_E = new QSlider(FormEICAS);
        Slider_E->setObjectName(QString::fromUtf8("Slider_E"));
        Slider_E->setGeometry(QRect(248, 400, 45, 100));
        Slider_E->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_E->setOrientation(Qt::Vertical);
        Slider_F = new QSlider(FormEICAS);
        Slider_F->setObjectName(QString::fromUtf8("Slider_F"));
        Slider_F->setGeometry(QRect(490, 400, 45, 100));
        Slider_F->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_F->setOrientation(Qt::Vertical);
        Slider_ha = new QSlider(FormEICAS);
        Slider_ha->setObjectName(QString::fromUtf8("Slider_ha"));
        Slider_ha->setGeometry(QRect(290, 490, 200, 16));
        Slider_ha->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_ha->setOrientation(Qt::Horizontal);
        Slider_hb = new QSlider(FormEICAS);
        Slider_hb->setObjectName(QString::fromUtf8("Slider_hb"));
        Slider_hb->setGeometry(QRect(590, 300, 130, 16));
        Slider_hb->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_hb->setOrientation(Qt::Horizontal);
        Slider_G = new QSlider(FormEICAS);
        Slider_G->setObjectName(QString::fromUtf8("Slider_G"));
        Slider_G->setGeometry(QRect(130, 280, 45, 100));
        Slider_G->setStyleSheet(QString::fromUtf8("QSlider {\n"
"    background: transparent; /* Hacer el fondo general transparente */\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"    background: lightgray; /* Color de la barra de recorrido horizontal */\n"
"    height: 5px; /* Grosor de la barra de recorrido horizontal */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: white; /* Color del bot\303\263n horizontal */\n"
"    border: 1px solid black; /* Borde del bot\303\263n horizontal */\n"
"    width: 15px; /* Ancho del bot\303\263n horizontal */\n"
"    margin: -5px 0; /* Ajustar la posici\303\263n vertical del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::groove:vertical {\n"
"    background: lightgray; /* Color de la barra de recorrido vertical */\n"
"    width: 5px; /* Grosor de la barra de recorrido vertical */\n"
"    margin: 0px; /* Eliminar m\303\241rgenes */\n"
"}\n"
"\n"
"QSlider::handle:vertical {\n"
"    background: whi"
                        "te; /* Color del bot\303\263n vertical */\n"
"    border: 1px solid black; /* Borde del bot\303\263n vertical */\n"
"    height: 15px; /* Altura del bot\303\263n vertical */\n"
"    margin: 0 -5px; /* Ajustar la posici\303\263n horizontal del bot\303\263n */\n"
"    border-radius: 3px; /* Bordes redondeados opcionales */\n"
"}\n"
"\n"
"QSlider::add-page:horizontal, QSlider::sub-page:horizontal,\n"
"QSlider::add-page:vertical, QSlider::sub-page:vertical {\n"
"    background: transparent; /* Hacer las p\303\241ginas (antes y despu\303\251s del bot\303\263n) transparentes */\n"
"}\n"
"\n"
"QSlider::tick-line:horizontal, QSlider::tick-line:vertical {\n"
"    background: transparent; /* Hacer las l\303\255neas de las marcas transparentes */\n"
"}\n"
"\n"
"QSlider::tick:horizontal, QSlider::tick:vertical {\n"
"    background: transparent; /* Hacer las marcas transparentes */\n"
"}"));
        Slider_G->setOrientation(Qt::Vertical);
        lcdNumber_a = new QLCDNumber(FormEICAS);
        lcdNumber_a->setObjectName(QString::fromUtf8("lcdNumber_a"));
        lcdNumber_a->setGeometry(QRect(60, 320, 64, 23));
        lcdNumber_a->setStyleSheet(QString::fromUtf8("QLCDNumber {\n"
"    background-color: black; /* Fondo negro oscuro */\n"
"	background: transparent;\n"
"    color: #00ff00; /* Color verde brillante t\303\255pico de LCD */\n"
"    border: 2px solid #00ff00; /* Borde verde brillante */\n"
"    border-radius: 5px; /* Bordes ligeramente redondeados */\n"
"    padding: 5px; /* Espacio alrededor del n\303\272mero */\n"
"    font-family: \"Monospace\"; /* Fuente monoespaciada para un aspecto digital */\n"
"    font-size: 20px; /* Tama\303\261o de la fuente (ajusta seg\303\272n necesidad) */\n"
"    /* Efecto de resplandor (glow) sutil */\n"
"    box-shadow: 0 0 10px rgba(0, 255, 0, 0.5); /* Resplandor verde */\n"
"}"));
        lcdNumber_b = new QLCDNumber(FormEICAS);
        lcdNumber_b->setObjectName(QString::fromUtf8("lcdNumber_b"));
        lcdNumber_b->setGeometry(QRect(620, 265, 64, 23));
        lcdNumber_b->setStyleSheet(QString::fromUtf8("QLCDNumber {\n"
"    background-color: black; /* Fondo negro oscuro */\n"
"	background: transparent;\n"
"    color: #00ff00; /* Color verde brillante t\303\255pico de LCD */\n"
"    border: 2px solid #ffffff; /* Borde verde brillante */\n"
"    border-radius: 5px; /* Bordes ligeramente redondeados */\n"
"    padding: 5px; /* Espacio alrededor del n\303\272mero */\n"
"    font-family: \"Monospace\"; /* Fuente monoespaciada para un aspecto digital */\n"
"    font-size: 20px; /* Tama\303\261o de la fuente (ajusta seg\303\272n necesidad) */\n"
"    /* Efecto de resplandor (glow) sutil */\n"
"    box-shadow: 0 0 10px rgba(0, 255, 0, 0.5); /* Resplandor verde */\n"
"}"));
        pushButton_FCTL = new QPushButton(FormEICAS);
        pushButton_FCTL->setObjectName(QString::fromUtf8("pushButton_FCTL"));
        pushButton_FCTL->setGeometry(QRect(0, 0, 131, 41));
        pushButton_FCTL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: gray; /* Fondo completamente gris */\n"
"	background: gray;;\n"
"    color: white; /* Letra blanca */\n"
"    font-weight: bold; /* Letra en negrita */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesidad) */\n"
"    border: 3px solid white; /* Borde grueso blanco (ajusta el grosor) */\n"
"    border-radius: 5px; /* Bordes ligeramente redondeados (opcional) */\n"
"    padding: 5px 15px; /* Espacio interno alrededor del texto (ajusta seg\303\272n necesidad) */\n"
"}"));
        pushButton_FUEL = new QPushButton(FormEICAS);
        pushButton_FUEL->setObjectName(QString::fromUtf8("pushButton_FUEL"));
        pushButton_FUEL->setGeometry(QRect(132, 0, 131, 41));
        pushButton_FUEL->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: gray; /* Fondo completamente gris */\n"
"	background: gray;;\n"
"    color: white; /* Letra blanca */\n"
"    font-weight: bold; /* Letra en negrita */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesidad) */\n"
"    border: 3px solid white; /* Borde grueso blanco (ajusta el grosor) */\n"
"    border-radius: 5px; /* Bordes ligeramente redondeados (opcional) */\n"
"    padding: 5px 15px; /* Espacio interno alrededor del texto (ajusta seg\303\272n necesidad) */\n"
"}"));
        pushButton_FIRE = new QPushButton(FormEICAS);
        pushButton_FIRE->setObjectName(QString::fromUtf8("pushButton_FIRE"));
        pushButton_FIRE->setGeometry(QRect(264, 0, 131, 41));
        pushButton_FIRE->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: gray; /* Fondo completamente gris */\n"
"	background: gray;;\n"
"    color: white; /* Letra blanca */\n"
"    font-weight: bold; /* Letra en negrita */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesidad) */\n"
"    border: 3px solid white; /* Borde grueso blanco (ajusta el grosor) */\n"
"    border-radius: 5px; /* Bordes ligeramente redondeados (opcional) */\n"
"    padding: 5px 15px; /* Espacio interno alrededor del texto (ajusta seg\303\272n necesidad) */\n"
"}"));
        label_R = new QLabel(FormEICAS);
        label_R->setObjectName(QString::fromUtf8("label_R"));
        label_R->setGeometry(QRect(340, 520, 87, 15));
        label_R->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_RF = new QLabel(FormEICAS);
        label_RF->setObjectName(QString::fromUtf8("label_RF"));
        label_RF->setGeometry(QRect(545, 250, 87, 15));
        label_RF->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_LF = new QLabel(FormEICAS);
        label_LF->setObjectName(QString::fromUtf8("label_LF"));
        label_LF->setGeometry(QRect(155, 250, 87, 15));
        label_LF->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_RA = new QLabel(FormEICAS);
        label_RA->setObjectName(QString::fromUtf8("label_RA"));
        label_RA->setGeometry(QRect(705, 250, 87, 15));
        label_RA->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_LA = new QLabel(FormEICAS);
        label_LA->setObjectName(QString::fromUtf8("label_LA"));
        label_LA->setGeometry(QRect(30, 250, 87, 15));
        label_LA->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_RT = new QLabel(FormEICAS);
        label_RT->setObjectName(QString::fromUtf8("label_RT"));
        label_RT->setGeometry(QRect(585, 330, 147, 15));
        label_RT->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_LE = new QLabel(FormEICAS);
        label_LE->setObjectName(QString::fromUtf8("label_LE"));
        label_LE->setGeometry(QRect(170, 485, 87, 15));
        label_LE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));
        label_RE = new QLabel(FormEICAS);
        label_RE->setObjectName(QString::fromUtf8("label_RE"));
        label_RE->setGeometry(QRect(540, 485, 87, 15));
        label_RE->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #00CED1; /* Azul turquesa (puedes ajustar el c\303\263digo de color) */\n"
"    font-weight: bold; /* Hace la letra m\303\241s gruesa (negrita) */\n"
"    font-size: 18px; /* Tama\303\261o de la letra (ajusta seg\303\272n necesites) */\n"
"    background: transparent; /* Hace el fondo transparente */\n"
"    border: none; /* Elimina el borde */\n"
"}"));

        retranslateUi(FormEICAS);

        QMetaObject::connectSlotsByName(FormEICAS);
    } // setupUi

    void retranslateUi(QWidget *FormEICAS)
    {
        FormEICAS->setWindowTitle(QCoreApplication::translate("FormEICAS", "Window A", nullptr));
        pushButton_FCTL->setText(QCoreApplication::translate("FormEICAS", "FCTL", nullptr));
        pushButton_FUEL->setText(QCoreApplication::translate("FormEICAS", "FUEL", nullptr));
        pushButton_FIRE->setText(QCoreApplication::translate("FormEICAS", "FIRE", nullptr));
        label_R->setText(QCoreApplication::translate("FormEICAS", "RUDDER", nullptr));
        label_RF->setText(QCoreApplication::translate("FormEICAS", "R. FLAP", nullptr));
        label_LF->setText(QCoreApplication::translate("FormEICAS", "L. FLAP", nullptr));
        label_RA->setText(QCoreApplication::translate("FormEICAS", "R. AIL", nullptr));
        label_LA->setText(QCoreApplication::translate("FormEICAS", "L. AIL", nullptr));
        label_RT->setText(QCoreApplication::translate("FormEICAS", "RUDDER TRIM", nullptr));
        label_LE->setText(QCoreApplication::translate("FormEICAS", "L. ELEV", nullptr));
        label_RE->setText(QCoreApplication::translate("FormEICAS", "R. ELEV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormEICAS: public Ui_FormEICAS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCTL_EICAS_H
