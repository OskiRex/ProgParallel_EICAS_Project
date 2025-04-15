QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Habilitar OpenMP
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

# Habilitar MPI
INCLUDEPATH += "C:/Program Files (x86)/Microsoft SDKs/MPI/Include"
LIBS += -L"C:/Program Files (x86)/Microsoft SDKs/MPI/Lib/x64" -lmsmpi

SOURCES += \
    AIR_main.cpp \
    air_widget.cpp \
    hibrido.cpp

HEADERS += \
    air_widget.h

FORMS += \
    air_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    GLOBAL.txt


