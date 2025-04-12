/********************************************************************************
** Form generated from reading UI file 'EICAS_Alertas.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef EICAS_ALERTAS_H
#define EICAS_ALERTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EICAS_Alertas
{
public:
    QWidget *EICAS_Alertas1;
    QLabel *Warning;
    QLabel *caution;
    QLabel *Advisory;
    QLabel *lineseleven;
    QFrame *line;
    QFrame *line_2;
    QLabel *communication;
    QLabel *memo;
    QLabel *RECALLindication;
    QLabel *PageNo;
    QPushButton *btnCancRecall;
    QLabel *msglabel1;
    QLabel *msglabel2;
    QLabel *msglabel3;
    QLabel *msglabel4;
    QLabel *msglabel5;
    QLabel *msglabel7;
    QLabel *msglabel6;
    QLabel *msglabel8;
    QLabel *msglabel9;
    QLabel *msglabel10;
    QLabel *msglabel11;
    QLabel *lblChecklist;
    QPushButton *btnNextPage;
    QPushButton *btnPrevPage;
    QPushButton *pushButton_FCTL;
    QPushButton *pushButton_FUEL;
    QPushButton *pushButton_FIRE;

    void setupUi(QWidget *EICAS_Alertas)
    {
        if (EICAS_Alertas->objectName().isEmpty())
            EICAS_Alertas->setObjectName(QString::fromUtf8("EICAS_Alertas"));
        EICAS_Alertas->resize(800, 600);
        EICAS_Alertas1 = new QWidget(EICAS_Alertas);
        EICAS_Alertas1->setObjectName(QString::fromUtf8("EICAS_Alertas1"));
        EICAS_Alertas1->setGeometry(QRect(0, 0, 800, 600));
        EICAS_Alertas1->setStyleSheet(QString::fromUtf8("background-color: black;\n"
""));
        Warning = new QLabel(EICAS_Alertas1);
        Warning->setObjectName(QString::fromUtf8("Warning"));
        Warning->setGeometry(QRect(90, 40, 221, 16));
        Warning->setStyleSheet(QString::fromUtf8(""));
        caution = new QLabel(EICAS_Alertas1);
        caution->setObjectName(QString::fromUtf8("caution"));
        caution->setGeometry(QRect(30, 80, 331, 16));
        caution->setStyleSheet(QString::fromUtf8(""));
        Advisory = new QLabel(EICAS_Alertas1);
        Advisory->setObjectName(QString::fromUtf8("Advisory"));
        Advisory->setGeometry(QRect(60, 120, 251, 21));
        Advisory->setStyleSheet(QString::fromUtf8(""));
        lineseleven = new QLabel(EICAS_Alertas1);
        lineseleven->setObjectName(QString::fromUtf8("lineseleven"));
        lineseleven->setGeometry(QRect(340, 250, 151, 21));
        lineseleven->setStyleSheet(QString::fromUtf8("color: white;\n"
"font: bold 16pt;"));
        line = new QFrame(EICAS_Alertas1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(150, 210, 8, 130));
        line->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(EICAS_Alertas1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(650, 210, 8, 130));
        line_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
""));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        communication = new QLabel(EICAS_Alertas1);
        communication->setObjectName(QString::fromUtf8("communication"));
        communication->setGeometry(QRect(30, 410, 81, 16));
        communication->setStyleSheet(QString::fromUtf8(""));
        memo = new QLabel(EICAS_Alertas1);
        memo->setObjectName(QString::fromUtf8("memo"));
        memo->setGeometry(QRect(30, 450, 181, 16));
        memo->setStyleSheet(QString::fromUtf8(""));
        RECALLindication = new QLabel(EICAS_Alertas1);
        RECALLindication->setObjectName(QString::fromUtf8("RECALLindication"));
        RECALLindication->setGeometry(QRect(30, 490, 101, 16));
        RECALLindication->setStyleSheet(QString::fromUtf8(""));
        PageNo = new QLabel(EICAS_Alertas1);
        PageNo->setObjectName(QString::fromUtf8("PageNo"));
        PageNo->setGeometry(QRect(670, 475, 111, 31));
        PageNo->setStyleSheet(QString::fromUtf8(""));
        btnCancRecall = new QPushButton(EICAS_Alertas1);
        btnCancRecall->setObjectName(QString::fromUtf8("btnCancRecall"));
        btnCancRecall->setGeometry(QRect(310, 560, 131, 21));
        btnCancRecall->setStyleSheet(QString::fromUtf8("background-color: #444;\n"
"color: white;\n"
"font: bold 12pt;"));
        msglabel1 = new QLabel(EICAS_Alertas1);
        msglabel1->setObjectName(QString::fromUtf8("msglabel1"));
        msglabel1->setGeometry(QRect(180, 170, 441, 21));
        msglabel1->setStyleSheet(QString::fromUtf8(""));
        msglabel2 = new QLabel(EICAS_Alertas1);
        msglabel2->setObjectName(QString::fromUtf8("msglabel2"));
        msglabel2->setGeometry(QRect(180, 191, 441, 21));
        msglabel2->setStyleSheet(QString::fromUtf8(""));
        msglabel3 = new QLabel(EICAS_Alertas1);
        msglabel3->setObjectName(QString::fromUtf8("msglabel3"));
        msglabel3->setGeometry(QRect(180, 212, 441, 21));
        msglabel3->setStyleSheet(QString::fromUtf8(""));
        msglabel4 = new QLabel(EICAS_Alertas1);
        msglabel4->setObjectName(QString::fromUtf8("msglabel4"));
        msglabel4->setGeometry(QRect(180, 233, 441, 21));
        msglabel4->setStyleSheet(QString::fromUtf8(""));
        msglabel5 = new QLabel(EICAS_Alertas1);
        msglabel5->setObjectName(QString::fromUtf8("msglabel5"));
        msglabel5->setGeometry(QRect(180, 254, 441, 21));
        msglabel5->setStyleSheet(QString::fromUtf8(""));
        msglabel7 = new QLabel(EICAS_Alertas1);
        msglabel7->setObjectName(QString::fromUtf8("msglabel7"));
        msglabel7->setGeometry(QRect(180, 296, 441, 21));
        msglabel7->setStyleSheet(QString::fromUtf8(""));
        msglabel6 = new QLabel(EICAS_Alertas1);
        msglabel6->setObjectName(QString::fromUtf8("msglabel6"));
        msglabel6->setGeometry(QRect(180, 275, 441, 21));
        msglabel6->setStyleSheet(QString::fromUtf8(""));
        msglabel8 = new QLabel(EICAS_Alertas1);
        msglabel8->setObjectName(QString::fromUtf8("msglabel8"));
        msglabel8->setGeometry(QRect(180, 317, 441, 21));
        msglabel8->setStyleSheet(QString::fromUtf8(""));
        msglabel9 = new QLabel(EICAS_Alertas1);
        msglabel9->setObjectName(QString::fromUtf8("msglabel9"));
        msglabel9->setGeometry(QRect(180, 338, 441, 21));
        msglabel9->setStyleSheet(QString::fromUtf8(""));
        msglabel10 = new QLabel(EICAS_Alertas1);
        msglabel10->setObjectName(QString::fromUtf8("msglabel10"));
        msglabel10->setGeometry(QRect(180, 359, 441, 21));
        msglabel10->setStyleSheet(QString::fromUtf8(""));
        msglabel11 = new QLabel(EICAS_Alertas1);
        msglabel11->setObjectName(QString::fromUtf8("msglabel11"));
        msglabel11->setGeometry(QRect(180, 380, 441, 21));
        msglabel11->setStyleSheet(QString::fromUtf8(""));
        lblChecklist = new QLabel(EICAS_Alertas1);
        lblChecklist->setObjectName(QString::fromUtf8("lblChecklist"));
        lblChecklist->setGeometry(QRect(30, 30, 41, 41));
        lblChecklist->setStyleSheet(QString::fromUtf8(""));
        btnNextPage = new QPushButton(EICAS_Alertas1);
        btnNextPage->setObjectName(QString::fromUtf8("btnNextPage"));
        btnNextPage->setGeometry(QRect(670, 520, 41, 21));
        btnNextPage->setStyleSheet(QString::fromUtf8("background-color: #444;\n"
"color: white;\n"
"font: bold 8pt;"));
        btnPrevPage = new QPushButton(EICAS_Alertas1);
        btnPrevPage->setObjectName(QString::fromUtf8("btnPrevPage"));
        btnPrevPage->setGeometry(QRect(730, 520, 41, 21));
        btnPrevPage->setStyleSheet(QString::fromUtf8("background-color: #444;\n"
"color: white;\n"
"font: bold 8pt;"));
        pushButton_FCTL = new QPushButton(EICAS_Alertas1);
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
        pushButton_FUEL = new QPushButton(EICAS_Alertas1);
        pushButton_FUEL->setObjectName(QString::fromUtf8("pushButton_FUEL"));
        pushButton_FUEL->setGeometry(QRect(130, 0, 131, 41));
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
        pushButton_FIRE = new QPushButton(EICAS_Alertas1);
        pushButton_FIRE->setObjectName(QString::fromUtf8("pushButton_FIRE"));
        pushButton_FIRE->setGeometry(QRect(260, 0, 131, 41));
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

        retranslateUi(EICAS_Alertas);

        QMetaObject::connectSlotsByName(EICAS_Alertas);
    } // setupUi

    void retranslateUi(QWidget *EICAS_Alertas)
    {
        EICAS_Alertas->setWindowTitle(QCoreApplication::translate("EICAS_Alertas", "Form", nullptr));
        Warning->setText(QString());
        caution->setText(QString());
        Advisory->setText(QString());
        lineseleven->setText(QCoreApplication::translate("EICAS_Alertas", "(11 LINES)", nullptr));
        communication->setText(QString());
        memo->setText(QString());
        RECALLindication->setText(QString());
        PageNo->setText(QString());
        btnCancRecall->setText(QCoreApplication::translate("EICAS_Alertas", "[CANC/RCL]", nullptr));
        msglabel1->setText(QString());
        msglabel2->setText(QString());
        msglabel3->setText(QString());
        msglabel4->setText(QString());
        msglabel5->setText(QString());
        msglabel7->setText(QString());
        msglabel6->setText(QString());
        msglabel8->setText(QString());
        msglabel9->setText(QString());
        msglabel10->setText(QString());
        msglabel11->setText(QString());
        lblChecklist->setText(QString());
        btnNextPage->setText(QCoreApplication::translate("EICAS_Alertas", "NEXT", nullptr));
        btnPrevPage->setText(QCoreApplication::translate("EICAS_Alertas", "PREV", nullptr));
        pushButton_FCTL->setText(QCoreApplication::translate("EICAS_Alertas", "FCTL", nullptr));
        pushButton_FUEL->setText(QCoreApplication::translate("EICAS_Alertas", "FUEL", nullptr));
        pushButton_FIRE->setText(QCoreApplication::translate("EICAS_Alertas", "FIRE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EICAS_Alertas: public Ui_EICAS_Alertas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // EICAS_ALERTAS_H
