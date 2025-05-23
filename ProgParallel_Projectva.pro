######################################################################
# Automatically generated by qmake (3.1) Sat Apr 12 17:09:56 2025
######################################################################

TEMPLATE = app
TARGET = ProgParallel_Projectva
INCLUDEPATH += /usr/lib/x86_64-linux-gnu/openmpi/include

QT += core gui widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += EICAS_Alertas.h EICAS_DataReader.h FCTL_EICAS.h
FORMS += EICAS_Alertas.ui FCTL_EICAS.ui
SOURCES += EICAS_DataReader.cpp main.cpp
RESOURCES += images/images.qrc

# Enlazado con la biblioteca MPI
LIBS += -lmpi
LIBS += -lmpi_cxx # Si usas la interfaz C++

# Configuración para la compilación y enlazado de MPI (opcional pero recomendado)
CONFIG += link_pkgconfig
PKGCONFIG += ompi