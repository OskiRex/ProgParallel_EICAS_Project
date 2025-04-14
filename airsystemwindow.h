/********************************************************************************
** Form generated from reading UI file 'airsystemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef AIRSYSTEMWINDOW_H
#define AIRSYSTEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AirSystemWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AirSystemWindow)
    {
        if (AirSystemWindow->objectName().isEmpty())
            AirSystemWindow->setObjectName(QString::fromUtf8("AirSystemWindow"));
        AirSystemWindow->resize(800, 600);
        centralwidget = new QWidget(AirSystemWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AirSystemWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AirSystemWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        AirSystemWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AirSystemWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AirSystemWindow->setStatusBar(statusbar);

        retranslateUi(AirSystemWindow);

        QMetaObject::connectSlotsByName(AirSystemWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AirSystemWindow)
    {
        AirSystemWindow->setWindowTitle(QCoreApplication::translate("AirSystemWindow", "AirSystemWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AirSystemWindow: public Ui_AirSystemWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // AIRSYSTEMWINDOW_H
