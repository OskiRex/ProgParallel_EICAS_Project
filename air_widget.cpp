#include "air_widget.h"
#include "ui_air_widget.h"



#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include <mpi.h>

AIR_Widget::AIR_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AIR_Widget)
{
    ui->setupUi(this);
    setFixedSize(800, 600);

    // --- COMIENZO DE MODIFICACIÓN PARA COMPACTAR ELEMENTOS ---
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(2);  // Reduce espacio entre secciones
    mainLayout->setContentsMargins(5, 2, 5, 5); // Margen exterior reducido

    QHBoxLayout *barraLayout1 = new QHBoxLayout();
    QHBoxLayout *barraLayout2 = new QHBoxLayout();

    QStringList fila1 = {"STAT", "ELEC", "HYD", "FUEL", "AIR", "DOOR"};
    QStringList fila2 = {"GEAR", "FCTL", "EFIS/DSP", "MAINT", "CB"};

    for (const QString &nombre : fila1) {
        QLabel *label = new QLabel(nombre);
        label->setStyleSheet(nombre == "AIR"
                                 ? "background-color: green; color: white; font-weight: bold; border: 1px solid white; padding: 1px;"
                                 : "background-color: #2e2e2e; color: white; font-weight: bold; border: 1px solid white; padding: 1px;");
        label->setFixedSize(130, 25); // Más pequeño
        barraLayout1->addWidget(label);
    }

    for (const QString &nombre : fila2) {
        QLabel *label = new QLabel(nombre);
        label->setStyleSheet("background-color: #2e2e2e; color: white; font-weight: bold; border: 1px solid white; padding: 1px;");
        label->setFixedSize(155, 25);
        barraLayout2->addWidget(label);
    }

    mainLayout->addLayout(barraLayout1);
    mainLayout->addLayout(barraLayout2);
    mainLayout->addSpacing(2);

    QHBoxLayout *topInfoLayout = new QHBoxLayout();

    QVBoxLayout *cabinLayout = new QVBoxLayout();
    QLabel *cabinLabel1 = new QLabel("CABIN");
    QLabel *cabinLabel2 = new QLabel("OCCUPANTS");
    QLabel *occupantsBox = new QLabel("201");

    cabinLabel1->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px");
    cabinLabel2->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px");
    occupantsBox->setStyleSheet("color: white; border: 1px solid cyan; padding: 1px;");
    occupantsBox->setAlignment(Qt::AlignCenter);
    occupantsBox->setFixedWidth(65);
    cabinLabel1->setAlignment(Qt::AlignCenter);
    cabinLabel2->setAlignment(Qt::AlignCenter);

    cabinLayout->setSpacing(1);
    cabinLayout->addWidget(cabinLabel1);
    cabinLayout->addWidget(cabinLabel2);
    cabinLayout->addWidget(occupantsBox);
    topInfoLayout->addLayout(cabinLayout);

    QVBoxLayout *tempLayout = new QVBoxLayout();
    QLabel *tempLabel1 = new QLabel("MASTER");
    QLabel *tempLabel2 = new QLabel("TEMP");
    QLabel *tempBox = new QLabel("24°C");

    tempLabel1->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px");
    tempLabel2->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px");
    tempBox->setStyleSheet("color: magenta; border: 1px solid cyan; padding: 1px;");
    tempBox->setAlignment(Qt::AlignCenter);
    tempBox->setFixedWidth(55);
    tempLabel1->setAlignment(Qt::AlignCenter);
    tempLabel2->setAlignment(Qt::AlignCenter);

    tempLayout->setSpacing(1);
    tempLayout->addWidget(tempLabel1);
    tempLayout->addWidget(tempLabel2);
    tempLayout->addWidget(tempBox);
    tempLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout *tempWrap = new QHBoxLayout();
    tempWrap->addStretch(2);
    tempWrap->addLayout(tempLayout);
    tempWrap->addStretch(3);
    topInfoLayout->addLayout(tempWrap);

    topInfoLayout->setSpacing(10);
    mainLayout->addLayout(topInfoLayout);
    mainLayout->addSpacing(2);
    // --- FIN DE MODIFICACIÓN PARA COMPACTAR ELEMENTOS ---


    // Esta sección crea la silueta del avión con los 8 recuadros y sus etiquetas
    // Debe colocarse justo debajo de la sección de MASTER TEMP en tu layout

    // --- CONTORNO DEL AVIÓN ---
    QFrame *aircraftOutline = new QFrame();
    aircraftOutline->setFixedSize(620, 89);
    aircraftOutline->setStyleSheet("background-color: #2e2e2e; border: 2px solid cyan; border-radius: 30px;");

    // --- LAYOUTS GENERALES ---
    QVBoxLayout *aircraftLayout = new QVBoxLayout();
    QHBoxLayout *upperZonesLayout = new QHBoxLayout();
    QHBoxLayout *lowerZonesLayout = new QHBoxLayout();

    // --- FUNCIONES AUXILIARES ---
    auto createZoneBox = [](QString labelText, QString nom, QString real, QString id) -> QVBoxLayout* {
        QVBoxLayout *zoneLayout = new QVBoxLayout();
        QLabel *label = new QLabel(labelText);
        QLabel *nominal = new QLabel(nom);
        QLabel *realTemp = new QLabel(real);
        QLabel *idBox = new QLabel(id);

        QWidget *tempWidget = new QWidget();
        QHBoxLayout *temps = new QHBoxLayout();
        temps->addWidget(nominal);
        temps->addStretch();
        temps->addWidget(realTemp);
        tempWidget->setLayout(temps);

        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("color: cyan; font-weight: bold;");
        nominal->setStyleSheet("color: magenta; font-size: 10px;");
        realTemp->setStyleSheet("color: white; font-size: 14px;");
        idBox->setStyleSheet("color: cyan; border: 1px solid cyan; padding: 1px;");
        idBox->setAlignment(Qt::AlignCenter);
        idBox->setFixedSize(16, 20);

        QFrame *container = new QFrame();
        container->setStyleSheet("background-color: black; border: 1px solid cyan;");
        QVBoxLayout *v = new QVBoxLayout();
        v->setContentsMargins(0, 0, 0, 0);  // Reduce márgenes
        v->setSpacing(0);                  // Casi sin espacio entre textos
        v->addWidget(label);
        v->addWidget(tempWidget);
        container->setLayout(v);
        container->setFixedSize(60, 50);

        zoneLayout->addWidget(container);
        zoneLayout->addWidget(idBox, 0, Qt::AlignHCenter);

        return zoneLayout;
    };

    // Recuadro FLT DECK (corregido, sin bordes internos, rectangular)
    QVBoxLayout *fltDeckLayout = new QVBoxLayout();
    QLabel *fltDeckTitle = new QLabel("FLT DECK");
    fltDeckTitle->setStyleSheet("color: cyan; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    fltDeckTitle->setAlignment(Qt::AlignCenter);


    // Números: 24 (morado, pequeño) y 25 (blanco, grande)
    QHBoxLayout *fltDeckTemps = new QHBoxLayout();
    QLabel *fltDeckNom = new QLabel("24");
    fltDeckNom->setStyleSheet("color: magenta; font-size: 10px; background-color: black; border: none;");
    fltDeckReal = new QLabel("25");
    fltDeckReal->setStyleSheet("color: white; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    fltDeckTemps->addWidget(fltDeckNom, 0, Qt::AlignLeft);
    fltDeckTemps->addWidget(fltDeckReal, 0, Qt::AlignRight);

    // Contenedor final
    fltDeckLayout->addWidget(fltDeckTitle);
    fltDeckLayout->addLayout(fltDeckTemps);

    QFrame *fltDeckBox = new QFrame();
    fltDeckBox->setFixedSize(70, 44); // ancho ≠ alto para evitar forma circular
    fltDeckBox->setLayout(fltDeckLayout);
    fltDeckBox->setStyleSheet("border: 1px solid cyan; background-color: black; border-radius: 0px;");



    // A, B, C, D (zonas)

    // Recuadro zona A (igual que FLT DECK pero con una sola letra arriba)
    QVBoxLayout *zoneALayout = new QVBoxLayout();
    QLabel *zoneATitle = new QLabel("A");
    zoneATitle->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px; background-color: black; border: none;");
    zoneATitle->setAlignment(Qt::AlignCenter);

    // Temperaturas
    QHBoxLayout *zoneATemps = new QHBoxLayout();
    QLabel *zoneANom = new QLabel("25");
    zoneANom->setStyleSheet("color: magenta; font-size: 10px; background-color: black; border: none;");
    zoneAReal = new QLabel("25");
    zoneAReal->setStyleSheet("color: white; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    zoneATemps->addWidget(zoneANom, 0, Qt::AlignLeft);
    zoneATemps->addWidget(zoneAReal, 0, Qt::AlignRight);

    // Contenedor final
    zoneALayout->addWidget(zoneATitle);
    zoneALayout->addLayout(zoneATemps);

    QFrame *zoneABox = new QFrame();
    zoneABox->setFixedSize(70, 44);
    zoneABox->setLayout(zoneALayout);
    zoneABox->setStyleSheet("border: 1px solid cyan; background-color: black; border-radius: 0px;");


    // Recuadro zona B (igual que FLT DECK pero con una sola letra arriba)
    QVBoxLayout *zoneBLayout = new QVBoxLayout();
    QLabel *zoneBTitle = new QLabel("B");
    zoneBTitle->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px; background-color: black; border: none;");
    zoneBTitle->setAlignment(Qt::AlignCenter);

    // Temperaturas
    QHBoxLayout *zoneBTemps = new QHBoxLayout();
    QLabel *zoneBNom = new QLabel("24");
    zoneBNom->setStyleSheet("color: magenta; font-size: 10px; background-color: black; border: none;");
    zoneBReal = new QLabel("25");
    zoneBReal->setStyleSheet("color: white; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    zoneBTemps->addWidget(zoneBNom, 0, Qt::AlignLeft);
    zoneBTemps->addWidget(zoneBReal, 0, Qt::AlignRight);

    // Contenedor final
    zoneBLayout->addWidget(zoneBTitle);
    zoneBLayout->addLayout(zoneBTemps);

    QFrame *zoneBBox = new QFrame();
    zoneBBox->setFixedSize(70, 44);
    zoneBBox->setLayout(zoneBLayout);
    zoneBBox->setStyleSheet("border: 1px solid cyan; background-color: black; border-radius: 0px;");




    // Recuadro zona C (igual que FLT DECK pero con una sola letra arriba)
    QVBoxLayout *zoneCLayout = new QVBoxLayout();
    QLabel *zoneCTitle = new QLabel("C");
    zoneCTitle->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px; background-color: black; border: none;");
    zoneCTitle->setAlignment(Qt::AlignCenter);

    // Temperaturas
    QHBoxLayout *zoneCTemps = new QHBoxLayout();
    QLabel *zoneCNom = new QLabel("25");
    zoneCNom->setStyleSheet("color: magenta; font-size: 10px; background-color: black; border: none;");
    zoneCReal = new QLabel("25");
    zoneCReal->setStyleSheet("color: white; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    zoneCTemps->addWidget(zoneCNom, 0, Qt::AlignLeft);
    zoneCTemps->addWidget(zoneCReal, 0, Qt::AlignRight);

    // Contenedor final
    zoneCLayout->addWidget(zoneCTitle);
    zoneCLayout->addLayout(zoneCTemps);

    QFrame *zoneCBox = new QFrame();
    zoneCBox->setFixedSize(70, 44);
    zoneCBox->setLayout(zoneCLayout);
    zoneCBox->setStyleSheet("border: 1px solid cyan; background-color: black; border-radius: 0px;");



    // Recuadro zona D (igual que FLT DECK pero con una sola letra arriba)
    QVBoxLayout *zoneDLayout = new QVBoxLayout();
    QLabel *zoneDTitle = new QLabel("D");
    zoneDTitle->setStyleSheet("color: cyan; font-weight: bold; font-size: 11px; background-color: black; border: none;");
    zoneDTitle->setAlignment(Qt::AlignCenter);

    // Temperaturas
    QHBoxLayout *zoneDTemps = new QHBoxLayout();
    QLabel *zoneDNom = new QLabel("22");
    zoneDNom->setStyleSheet("color: magenta; font-size: 10px; background-color: black; border: none;");
    zoneDReal = new QLabel("25");
    zoneDReal->setStyleSheet("color: white; font-size: 11px; font-weight: bold; background-color: black; border: none;");
    zoneDTemps->addWidget(zoneDNom, 0, Qt::AlignLeft);
    zoneDTemps->addWidget(zoneDReal, 0, Qt::AlignRight);

    // Contenedor final
    zoneDLayout->addWidget(zoneDTitle);
    zoneDLayout->addLayout(zoneDTemps);

    QFrame *zoneDBox = new QFrame();
    zoneDBox->setFixedSize(70, 44);
    zoneDBox->setLayout(zoneDLayout);
    zoneDBox->setStyleSheet("border: 1px solid cyan; background-color: black; border-radius: 0px;");

    upperZonesLayout->addWidget(fltDeckBox);
    upperZonesLayout->addSpacing(5);
    upperZonesLayout->addWidget(zoneABox);
    upperZonesLayout->addWidget(zoneBBox);
    upperZonesLayout->addWidget(zoneCBox);
    upperZonesLayout->addWidget(zoneDBox);

    // --- FWD ---
    QHBoxLayout *fwdLayout = new QHBoxLayout();
    fwdLayout->setAlignment(Qt::AlignLeft);
    fwdLayout->setContentsMargins(120, 0, 0, 0); // Mueve todo hacia la derecha (ajusta el valor si es necesario)

    QLabel *fwdLabel = new QLabel("FWD");
    fwdLabel->setStyleSheet("color: cyan; font-weight: bold; border: none;");
    fwdLabel->setAlignment(Qt::AlignVCenter);

    // TEMP dentro del recuadro
    fwdTemp = new QLabel("24");
    fwdTemp->setStyleSheet("color: white; border: 1px solid cyan; background-color: black; padding: 2px;");
    fwdTemp->setFixedSize(70, 20);
    fwdTemp->setAlignment(Qt::AlignCenter);

    // Añadir al layout
    fwdLayout->addWidget(fwdLabel);
    fwdLayout->addSpacing(1);
    fwdLayout->addWidget(fwdTemp);



    // --- AFT + BULK ---
    // --- AFT + BULK combinados ---
    QHBoxLayout *aftBulkLayout = new QHBoxLayout();
    aftBulkLayout->setAlignment(Qt::AlignLeft);
    aftBulkLayout->setContentsMargins(22, 0, 0, 0); // Ajusta esta distancia para mover horizontalmente

    // Texto AFT
    QLabel *aftLabel = new QLabel("AFT");
    aftLabel->setStyleSheet("color: cyan; font-weight: bold; border: none;");
    aftLabel->setAlignment(Qt::AlignVCenter);

    // Recuadro con 2 temperaturas
    QFrame *aftBulkBox = new QFrame();
    aftBulkBox->setStyleSheet("border: 1px solid cyan; background-color: black;");
    aftBulkBox->setFixedSize(110, 20);

    QHBoxLayout *tempsLayout = new QHBoxLayout();
    tempsLayout->setSpacing(0);
    tempsLayout->setContentsMargins(0, 0, 0, 0);

    // Temp AFT
    aftTemp = new QLabel("24");
    aftTemp->setStyleSheet("color: white; background-color: black; border: none;");
    aftTemp->setAlignment(Qt::AlignCenter);
    aftTemp->setFixedWidth(60);

    // Línea divisoria punteada simulada (espaciado visual)
    QLabel *separator = new QLabel("|");
    separator->setStyleSheet("color: cyan; font-weight: bold;");
    separator->setAlignment(Qt::AlignCenter);
    separator->setFixedWidth(5);

    // Temp BULK
    bulkTemp = new QLabel("22");
    bulkTemp->setStyleSheet("color: white; background-color: black; border: none;");
    bulkTemp->setAlignment(Qt::AlignCenter);
    bulkTemp->setFixedWidth(30);

    tempsLayout->addWidget(aftTemp);
    tempsLayout->addWidget(separator);
    tempsLayout->addWidget(bulkTemp);
    aftBulkBox->setLayout(tempsLayout);

    // Texto BULK
    QLabel *bulkLabel = new QLabel("BULK");
    bulkLabel->setStyleSheet("color: cyan; font-weight: bold; border: none;");
    bulkLabel->setAlignment(Qt::AlignVCenter);

    // Añadir todo al layout horizontal final
    aftBulkLayout->addWidget(aftLabel);
    aftBulkLayout->addSpacing(1);
    aftBulkLayout->addWidget(aftBulkBox);
    aftBulkLayout->addSpacing(1);
    aftBulkLayout->addWidget(bulkLabel);


    // Añadir al layout inferior
    lowerZonesLayout->addLayout(fwdLayout);
    lowerZonesLayout->addSpacing(50);
    lowerZonesLayout->addLayout(aftBulkLayout);

    // Añadir ambos a layout general
    aircraftLayout->addLayout(upperZonesLayout);
    aircraftLayout->addLayout(lowerZonesLayout);
    aircraftOutline->setLayout(aircraftLayout);




    // Añadir al layout principal


    // Finalmente, añadir todo al layout principal de la GUI
    mainLayout->addWidget(aircraftOutline, 0, Qt::AlignHCenter);

    // Caja "FLT DECK" del diagrama inferior (color cyan)
    QFrame *fltDeckCyanBox = new QFrame();
    fltDeckCyanBox->setStyleSheet("color: cyan; border-radius: 10px; border: 1px solid cyan; background-color: black;");
    fltDeckCyanBox->setFixedSize(620, 20);

    QLabel *fltDeckCyanLabel = new QLabel("FLT DECK");
    fltDeckCyanLabel->setStyleSheet("color: cyan; font-weight: bold;");
    fltDeckCyanLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *fltDeckCyanLayout = new QVBoxLayout();
    fltDeckCyanLayout->setContentsMargins(0, 0, 0, 0);
    fltDeckCyanLayout->addWidget(fltDeckCyanLabel);
    fltDeckCyanBox->setLayout(fltDeckCyanLayout);

    // Añadir la caja al layout principal centrado
    mainLayout->addWidget(fltDeckCyanBox, 0, Qt::AlignHCenter);





    // Layout del diagrama (crear si no existe)
    QVBoxLayout *diagramLayout = new QVBoxLayout();

    // --- PASSENGER CABIN ---
    QLabel *passengerCabinLabel = new QLabel("PASSENGER CABIN");
    passengerCabinLabel->setStyleSheet("color: cyan; font-weight: bold;");
    passengerCabinLabel->setAlignment(Qt::AlignCenter);

    QFrame *passengerCabinBox = new QFrame();
    passengerCabinBox->setFrameStyle(QFrame::Box);
    passengerCabinBox->setContentsMargins(0, 0, 0, 0);  // Borra márgenes internos
    passengerCabinBox->setStyleSheet("color: cyan; border: 1px solid cyan; border-radius: 10px; background-color: black; margin: 0px; padding: 0px;");  // Reemplaza tu línea actual
    passengerCabinBox->setFixedSize(420, 25);

    QVBoxLayout *passengerCabinLayout = new QVBoxLayout(passengerCabinBox);
    passengerCabinLayout->setContentsMargins(0, 0, 0, 0);
    passengerCabinLabel->setContentsMargins(0, 0, 0, 0);
    passengerCabinLayout->addWidget(passengerCabinLabel);





    // Asegúrate de agregar diagramLayout al final del mainLayout (si no lo hiciste ya)
    mainLayout->addLayout(diagramLayout);



    // Crear el widget del diagrama y el layout asociado
    QWidget *diagramWidget = new QWidget();
    diagramWidget->setStyleSheet("background-color: black;");

    diagramLayout->setContentsMargins(0, 0, 0, 0);
    diagramLayout->setSpacing(0);
    diagramWidget->setLayout(diagramLayout);  // ← se mantiene por claridad, aunque ya está arriba
    diagramWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);  // fuerza crecimiento

    // Contenedor vertical para la flecha izquierda
    QVBoxLayout *leftArrowLayout = new QVBoxLayout();
    leftArrowLayout->setSpacing(0);
    leftArrowLayout->setContentsMargins(0, 0, 0, 0);


    QLabel *leftArrowHead = new QLabel("↑");
    leftArrowHead->setContentsMargins(0, 0, 0, 0);
    leftArrowHead->setStyleSheet("color: lime; font-size: 26px; font-weight: bold; margin: 0px; padding: 0px;");
    leftArrowHead->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    leftArrowHead->setFixedHeight(15);  // ← ¡esto debería eliminar el hueco!
    leftArrowHead->setAlignment(Qt::AlignCenter);


    // Línea larga
    QFrame *leftLine = new QFrame();
    leftLine->setFrameShape(QFrame::VLine);
    leftLine->setStyleSheet("background-color: lime;");
    leftLine->setFixedWidth(3);
    leftLine->setFixedSize(3, 147);  // Aumenta aquí si quieres que baje más


    leftArrowLayout->addWidget(leftArrowHead, 0, Qt::AlignHCenter);
    leftArrowLayout->addWidget(leftLine, 1, Qt::AlignHCenter);  // ⬅ peso 1, ocupa lo que quede

    // Contenedor para mover horizontalmente la flecha
    QWidget *leftArrowWidget = new QWidget();
    leftArrowWidget->setLayout(leftArrowLayout);

    QHBoxLayout *arrowRow = new QHBoxLayout();
    arrowRow->addSpacing(100);
    arrowRow->addWidget(leftArrowWidget);
    arrowRow->addStretch();

    // Agregar al layout principal del diagrama
    diagramLayout->setSpacing(0);

    // --- L PACK + Válvula visual ---
    QHBoxLayout *lpackRow = new QHBoxLayout();
    lpackRow->setAlignment(Qt::AlignLeft);
    lpackRow->setContentsMargins(30, 0, 0, 0); // desplaza horizontalmente
    lpackRow->setSpacing(10); // espacio entre texto y válvula

    // Texto "L PACK"
    QLabel *lpackLabel = new QLabel("L PACK");
    lpackLabel->setStyleSheet("color: cyan; font-weight: bold;");
    lpackLabel->setAlignment(Qt::AlignVCenter);

    // Contenedor para la válvula y la línea encima
    QWidget *valveContainer = new QWidget();
    valveContainer->setFixedSize(56, 23);  // Igual tamaño que el óvalo
    QGridLayout *valveOverlay = new QGridLayout(valveContainer);
    valveOverlay->setContentsMargins(0, 0, 0, 0);
    valveOverlay->setSpacing(0);

    // Válvula
    QFrame *ovalValve = new QFrame();
    ovalValve->setStyleSheet(
        "background-color: black;"
        "border: 2px solid lime;"
        "border-radius: 10px;"
        );
    ovalValve->setFixedSize(56, 23);

    // Línea verde vertical centrada (efecto atravesar)
    QFrame *innerLine = new QFrame();
    innerLine->setStyleSheet("background-color: lime;");
    innerLine->setFixedSize(3, 23);  // mismo alto que la válvula
    innerLine->setFrameShape(QFrame::VLine);

    // Añadir ambos al mismo lugar (superposición)
    valveOverlay->addWidget(ovalValve, 0, 0, Qt::AlignCenter);
    valveOverlay->addWidget(innerLine, 0, 0, Qt::AlignCenter);

    // Añadir al layout
    lpackRow->addWidget(lpackLabel);
    lpackRow->addWidget(valveContainer);

    // Añadir al layout del diagrama






    // --- COMPRESORES L1 y L2 (forma de trapecios + líneas + etiquetas) ---
    QHBoxLayout *compressorRow = new QHBoxLayout();
    compressorRow->setContentsMargins(0, 0, 0, 0);
    compressorRow->setSpacing(1);

    // Crear cada compresor como un QLabel con borde trapecial (simulado con CSS)
    auto createCompressor = [](const QString &labelText) -> QWidget* {
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setSpacing(0);
        layout->setContentsMargins(0, 0, 0, 0);

        // Trapecio (estilo visual similar)
        QLabel *trap = new QLabel();
        trap->setFixedSize(25, 30);
        trap->setStyleSheet(
            "background-color: black;"
            "border-left: 8px solid lime;"
            "border-right: 8px solid lime;"
            "border-bottom: 8px solid lime;"
            "border-top: none;"
            );

        // Etiqueta debajo (L1 o L2)
        QLabel *label = new QLabel(labelText);
        label->setStyleSheet("color: cyan; font-weight: bold;");
        label->setAlignment(Qt::AlignCenter);

        layout->addWidget(trap, 0, Qt::AlignCenter);
        layout->addWidget(label, 0, Qt::AlignCenter);

        QWidget *container = new QWidget();
        container->setLayout(layout);
        return container;
    };

    QWidget *l1 = createCompressor("L1");
    QWidget *l2 = createCompressor("L2");

    compressorRow->addSpacing(46);  // Ajusta este número hasta que quede perfecto
    compressorRow->addWidget(l1);
    compressorRow->addSpacing(70);  // Espacio entre L1 y L2 (ajustable)
    compressorRow->addWidget(l2);
    compressorRow->addStretch();    // Empuja todo hacia la izquierda

    // Agregar al layout principal
    diagramLayout->addSpacing(0); // Separación con válvula


    // --- CONEXIÓN TIPO "Y" (desde válvula a compresores) ---

    // Layout vertical principal
    QVBoxLayout *yConnectionLayout = new QVBoxLayout();
    yConnectionLayout->setContentsMargins(0, 0, 0, 0);
    yConnectionLayout->setSpacing(0);

    // Línea vertical desde válvula
    QFrame *mainVerticalLine = new QFrame();
    mainVerticalLine->setFrameShape(QFrame::VLine);
    mainVerticalLine->setStyleSheet("background-color: lime;");
    mainVerticalLine->setFixedSize(3, 70);  // Altura ajustable
    mainVerticalLine->setFixedWidth(3);
    yConnectionLayout->addWidget(mainVerticalLine, 0, Qt::AlignHCenter);

    // Línea horizontal (conecta ramas)
    QFrame *horizontalLine = new QFrame();
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setStyleSheet("background-color: lime;");
    horizontalLine->setFixedSize(97, 3);  // Largo entre ramas ajustable
    horizontalLine->setLineWidth(2);
    yConnectionLayout->addWidget(horizontalLine, 0, Qt::AlignHCenter);

    // Layout para las dos líneas verticales pequeñas (ramas)
    QHBoxLayout *branchesLayout = new QHBoxLayout();
    branchesLayout->setContentsMargins(0, 0, 0, 0);
    branchesLayout->setSpacing(93);  // Distancia entre ramitas, ajústala si cambias separación entre L1 y L2

    // Rama izquierda (a L1)
    QFrame *leftBranch = new QFrame();
    leftBranch->setFrameShape(QFrame::VLine);
    leftBranch->setStyleSheet("background-color: lime;");
    leftBranch->setFixedSize(3, 15);

    // Rama derecha (a L2)
    QFrame *rightBranch = new QFrame();
    rightBranch->setFrameShape(QFrame::VLine);
    rightBranch->setStyleSheet("background-color: lime;");
    rightBranch->setFixedSize(3, 15);

    branchesLayout->addWidget(leftBranch, 0, Qt::AlignHCenter);
    branchesLayout->addWidget(rightBranch, 0, Qt::AlignHCenter);

    // Agrega ramas al layout principal
    yConnectionLayout->addLayout(branchesLayout);

    // --- CONTENEDOR HORIZONTAL PARA DESPLAZAR TODA LA "Y" ---
    QHBoxLayout *yConnectionRow = new QHBoxLayout();
    yConnectionRow->setContentsMargins(0, 0, 0, 0);
    yConnectionRow->setSpacing(0);

    yConnectionRow->addSpacing(57);  // << Ajusta este número para mover la "Y" a la izquierda
    yConnectionRow->addLayout(yConnectionLayout);
    yConnectionRow->addStretch();   // Para empujar el resto a la derecha


    yConnectionRow->addStretch();





    // Agrega el contenedor al diagrama


    // --- FLECHA DERECHA + R PACK + R1/R2 ---

    // 1. Flecha derecha (estructura igual a izquierda)
    QVBoxLayout *rightArrowLayout = new QVBoxLayout();
    rightArrowLayout->setSpacing(0);
    rightArrowLayout->setContentsMargins(0, 0, 0, 0);

    QLabel *rightArrowHead = new QLabel("↑");
    rightArrowHead->setContentsMargins(0, 0, 0, 0);
    rightArrowHead->setStyleSheet("color: lime; font-size: 26px; font-weight: bold; margin: 0px; padding: 0px;");
    rightArrowHead->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    rightArrowHead->setFixedHeight(15);
    rightArrowHead->setAlignment(Qt::AlignCenter);

    QFrame *rightLine = new QFrame();
    rightLine->setFrameShape(QFrame::VLine);
    rightLine->setStyleSheet("background-color: lime;");
    rightLine->setFixedSize(3, 147);

    rightArrowLayout->addWidget(rightArrowHead, 0, Qt::AlignHCenter);
    rightArrowLayout->addWidget(rightLine, 1, Qt::AlignHCenter);

    QWidget *rightArrowWidget = new QWidget();
    rightArrowWidget->setLayout(rightArrowLayout);

    QHBoxLayout *rightArrowRow = new QHBoxLayout();
    rightArrowRow->addStretch();
    rightArrowRow->addWidget(rightArrowWidget);
    rightArrowRow->addSpacing(100);



    diagramLayout->setSpacing(0);

    // 2. R PACK con válvula
    QHBoxLayout *rpackRow = new QHBoxLayout();
    rpackRow->setAlignment(Qt::AlignRight);
    rpackRow->setContentsMargins(0, 0, 30, 0);
    rpackRow->setSpacing(10);

    QLabel *rpackLabel = new QLabel("R PACK");
    rpackLabel->setStyleSheet("color: cyan; font-weight: bold;");
    rpackLabel->setAlignment(Qt::AlignVCenter);

    QWidget *rvalveContainer = new QWidget();
    rvalveContainer->setFixedSize(56, 23);
    QGridLayout *rvalveOverlay = new QGridLayout(rvalveContainer);
    rvalveOverlay->setContentsMargins(0, 0, 0, 0);
    rvalveOverlay->setSpacing(0);

    QFrame *rOvalValve = new QFrame();
    rOvalValve->setStyleSheet("background-color: black; border: 2px solid lime; border-radius: 10px;");
    rOvalValve->setFixedSize(56, 23);

    QFrame *rInnerLine = new QFrame();
    rInnerLine->setStyleSheet("background-color: lime;");
    rInnerLine->setFixedSize(3, 23);
    rInnerLine->setFrameShape(QFrame::VLine);

    rvalveOverlay->addWidget(rOvalValve, 0, 0, Qt::AlignCenter);
    rvalveOverlay->addWidget(rInnerLine, 0, 0, Qt::AlignCenter);

    rpackRow->addWidget(rvalveContainer);
    rpackRow->addWidget(rpackLabel);



    // 3. Compresores R1/R2
    QHBoxLayout *rightCompressorRow = new QHBoxLayout();
    rightCompressorRow->setContentsMargins(0, 0, 0, 0);
    rightCompressorRow->setSpacing(1);

    QWidget *r1 = createCompressor("R1");
    QWidget *r2 = createCompressor("R2");

    rightCompressorRow->addStretch();
    rightCompressorRow->addWidget(r1);
    rightCompressorRow->addSpacing(70);
    rightCompressorRow->addWidget(r2);
    rightCompressorRow->addSpacing(46);

    diagramLayout->addSpacing(0);

    // 4. Conexión tipo "Y"
    QVBoxLayout *yRightConnection = new QVBoxLayout();
    yRightConnection->setContentsMargins(0, 0, 0, 0);
    yRightConnection->setSpacing(0);

    QFrame *mainRightLine = new QFrame();
    mainRightLine->setFrameShape(QFrame::VLine);
    mainRightLine->setStyleSheet("background-color: lime;");
    mainRightLine->setFixedSize(3, 70);

    QFrame *hRightLine = new QFrame();
    hRightLine->setFrameShape(QFrame::HLine);
    hRightLine->setStyleSheet("background-color: lime;");
    hRightLine->setFixedSize(97, 3);
    hRightLine->setLineWidth(2);

    yRightConnection->addWidget(mainRightLine, 0, Qt::AlignHCenter);
    yRightConnection->addWidget(hRightLine, 0, Qt::AlignHCenter);

    QHBoxLayout *branchesRight = new QHBoxLayout();
    branchesRight->setContentsMargins(0, 0, 0, 0);
    branchesRight->setSpacing(93);

    QFrame *branchR1 = new QFrame();
    branchR1->setFrameShape(QFrame::VLine);
    branchR1->setStyleSheet("background-color: lime;");
    branchR1->setFixedSize(3, 15);

    QFrame *branchR2 = new QFrame();
    branchR2->setFrameShape(QFrame::VLine);
    branchR2->setStyleSheet("background-color: lime;");
    branchR2->setFixedSize(3, 15);

    branchesRight->addWidget(branchR1, 0, Qt::AlignHCenter);
    branchesRight->addWidget(branchR2, 0, Qt::AlignHCenter);
    yRightConnection->addLayout(branchesRight);

    QHBoxLayout *yRightRow = new QHBoxLayout();
    yRightRow->addStretch();
    yRightRow->addLayout(yRightConnection);
    yRightRow->addSpacing(57);







    // --- AIR DISTRIBUTION (Centro) ---
    QFrame *airDistBox = new QFrame();
    airDistBox->setStyleSheet("border: 1px solid lime; background-color: black;");
    airDistBox->setFixedSize(280, 25);

    QLabel *airDistLabel = new QLabel("AIR DISTRIBUTION");
    airDistLabel->setStyleSheet("color: lime; font-weight: bold;");
    airDistLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *airDistLayout = new QVBoxLayout(airDistBox);
    airDistLayout->setContentsMargins(0, 0, 0, 0);
    airDistLayout->addWidget(airDistLabel);

    // --- Flechas horizontales izquierda y derecha hacia AIR DISTRIBUTION ---
    QFrame *leftHArrow = new QFrame();
    leftHArrow->setFixedSize(60, 3);  // Más largo
    leftHArrow->setStyleSheet("background-color: lime;");

    QLabel *leftHArrowHead = new QLabel("→");
    leftHArrowHead->setStyleSheet("color: lime; font-weight: bold; font-size: 18px; margin-left: -5px;");  // Unión visual más estrecha
    leftHArrowHead->setAlignment(Qt::AlignLeft);

    QHBoxLayout *airHLeftLayout = new QHBoxLayout();
    airHLeftLayout->setSpacing(0);
    airHLeftLayout->setContentsMargins(0, 0, 0, 0);
    airHLeftLayout->addWidget(leftHArrow);
    airHLeftLayout->addWidget(leftHArrowHead);

    QWidget *airHLeftWidget = new QWidget();
    airHLeftWidget->setLayout(airHLeftLayout);

    QFrame *rightHArrow = new QFrame();
    rightHArrow->setFixedSize(50, 3);
    rightHArrow->setStyleSheet("background-color: lime;");

    QLabel *rightHArrowHead = new QLabel("←");
    rightHArrowHead->setStyleSheet("color: lime; font-weight: bold; font-size: 20px; margin-right: -5px;");
    rightHArrowHead->setAlignment(Qt::AlignRight);

    QHBoxLayout *airHRightLayout = new QHBoxLayout();
    airHRightLayout->setSpacing(0);
    airHRightLayout->setContentsMargins(0, 0, 0, 0);
    airHRightLayout->addWidget(rightHArrowHead);
    airHRightLayout->addWidget(rightHArrow);

    QWidget *airHRightWidget = new QWidget();
    airHRightWidget->setLayout(airHRightLayout);

    QHBoxLayout *airHDualLayout = new QHBoxLayout();
    airHDualLayout->setContentsMargins(0, 0, 0, 0);
    airHDualLayout->setSpacing(10);
    airHDualLayout->addWidget(airHLeftWidget);
    airHDualLayout->addStretch();
    airHDualLayout->addWidget(airDistBox);
    airHDualLayout->addStretch();
    airHDualLayout->addWidget(airHRightWidget);

    // --- AGREGAR ESPACIOS ENTRE BLOQUES SUPERIORES ---
    QVBoxLayout *airBoxWithArrows = new QVBoxLayout();
    airBoxWithArrows->setSpacing(6);  // Más separación entre recirculación y AIR DISTRIBUTION
    airBoxWithArrows->setContentsMargins(0, 0, 0, 0);
    airBoxWithArrows->addLayout(airHDualLayout);
    airBoxWithArrows->addSpacing(0);  // Espacio entre flechas y caja
    airBoxWithArrows->addWidget(airDistBox, 0, Qt::AlignCenter);


    // --- Flechas verticales hacia PASSENGER CABIN ---
    QFrame *upLineLeft = new QFrame();
    upLineLeft->setFixedSize(3, 30);
    upLineLeft->setStyleSheet("background-color: lime;");
    QLabel *upArrowLeft = new QLabel("↑");
    upArrowLeft->setStyleSheet("color: lime; font-size: 16px; font-weight: bold;");
    upArrowLeft->setAlignment(Qt::AlignCenter);

    QVBoxLayout *upLeftLayout = new QVBoxLayout();
    upLeftLayout->setSpacing(0);
    upLeftLayout->setContentsMargins(0, 0, 0, 0);
    upLeftLayout->addWidget(upArrowLeft);
    upLeftLayout->addWidget(upLineLeft);

    QFrame *upLineRight = new QFrame();
    upLineRight->setFixedSize(3, 30);
    upLineRight->setStyleSheet("background-color: lime;");
    QLabel *upArrowRight = new QLabel("↑");
    upArrowRight->setStyleSheet("color: lime; font-size: 16px; font-weight: bold;");
    upArrowRight->setAlignment(Qt::AlignCenter);

    QVBoxLayout *upRightLayout = new QVBoxLayout();
    upRightLayout->setSpacing(0);
    upRightLayout->setContentsMargins(0, 0, 0, 0);
    upRightLayout->addWidget(upArrowRight);
    upRightLayout->addWidget(upLineRight);

    QHBoxLayout *upArrowsRow = new QHBoxLayout();
    upArrowsRow->addLayout(upLeftLayout);
    upArrowsRow->addStretch();
    upArrowsRow->addLayout(upRightLayout);

    // --- NUEVO BLOQUE CORREGIDO ---
    // Contiene: flechas verticales hacia CABIN → caja → flechas horizontales → recirculación

    QVBoxLayout *airDistBlock = new QVBoxLayout();
    airDistBlock->setContentsMargins(0, 0, 0, 0);
    airDistBlock->setSpacing(0);

    // --- TEXTOS ---
    QLabel *upperText1 = new QLabel("UPPER");
    QLabel *upperText2 = new QLabel("RECIRC");
    QLabel *lowerText1 = new QLabel("LOWER");
    QLabel *lowerText2 = new QLabel("RECIRC");

    QString recircTextStyle = "color: cyan; font-size: 9px; font-weight: bold;";
    upperText1->setStyleSheet(recircTextStyle);
    upperText2->setStyleSheet(recircTextStyle);
    lowerText1->setStyleSheet(recircTextStyle);
    lowerText2->setStyleSheet(recircTextStyle);

    upperText1->setAlignment(Qt::AlignCenter);
    upperText2->setAlignment(Qt::AlignCenter);
    lowerText1->setAlignment(Qt::AlignCenter);
    lowerText2->setAlignment(Qt::AlignCenter);

    QVBoxLayout *upperTextLayout = new QVBoxLayout();
    upperTextLayout->addWidget(upperText1);
    upperTextLayout->addWidget(upperText2);
    upperTextLayout->setAlignment(Qt::AlignTop);

    QVBoxLayout *lowerTextLayout = new QVBoxLayout();
    lowerTextLayout->addWidget(lowerText1);
    lowerTextLayout->addWidget(lowerText2);
    lowerTextLayout->setAlignment(Qt::AlignTop);

    // --- CUADROS Y FLECHAS ---
    QWidget *upperIconWidget = new QWidget();
    upperIconWidget->setFixedSize(20, 30);
    QGridLayout *upperGrid = new QGridLayout(upperIconWidget);
    upperGrid->setContentsMargins(0, 0, 0, 0);
    upperGrid->setSpacing(0);

    QFrame *upperBox = new QFrame();
    upperBox->setStyleSheet("border: 2px solid lime; background-color: black;");
    upperBox->setFixedSize(20, 30);

    QFrame *upperLine = new QFrame();
    upperLine->setFrameShape(QFrame::VLine);
    upperLine->setStyleSheet("background-color: lime;");
    upperLine->setFixedSize(2, 28);

    QLabel *upArrow = new QLabel("↑");
    upArrow->setStyleSheet("color: lime; font-size: 16px; font-weight: bold;");
    upArrow->setAlignment(Qt::AlignCenter);

    upperGrid->addWidget(upperBox, 0, 0, Qt::AlignCenter);
    upperGrid->addWidget(upperLine, 0, 0, Qt::AlignCenter);

    QVBoxLayout *upperIconLayout = new QVBoxLayout();
    upperIconLayout->setSpacing(0);
    upperIconLayout->addWidget(upArrow, 0, Qt::AlignCenter);
    upperIconLayout->addWidget(upperIconWidget, 0, Qt::AlignCenter);

    QWidget *lowerIconWidget = new QWidget();
    lowerIconWidget->setFixedSize(20, 30);
    QGridLayout *lowerGrid = new QGridLayout(lowerIconWidget);
    lowerGrid->setContentsMargins(0, 0, 0, 0);
    lowerGrid->setSpacing(0);

    QFrame *lowerBox = new QFrame();
    lowerBox->setStyleSheet("border: 2px solid lime; background-color: black;");
    lowerBox->setFixedSize(20, 30);

    QFrame *lowerLine = new QFrame();
    lowerLine->setFrameShape(QFrame::VLine);
    lowerLine->setStyleSheet("background-color: lime;");
    lowerLine->setFixedSize(2, 28);

    QLabel *downArrow = new QLabel("↓");
    downArrow->setStyleSheet("color: lime; font-size: 16px; font-weight: bold;");
    downArrow->setAlignment(Qt::AlignCenter);

    lowerGrid->addWidget(lowerBox, 0, 0, Qt::AlignCenter);
    lowerGrid->addWidget(lowerLine, 0, 0, Qt::AlignCenter);

    QVBoxLayout *lowerIconLayout = new QVBoxLayout();
    lowerIconLayout->setSpacing(0);
    lowerIconLayout->addWidget(lowerIconWidget, 0, Qt::AlignCenter);
    lowerIconLayout->addWidget(downArrow, 0, Qt::AlignCenter);

    // --- RECIRCULADORES CENTRALES ---
    QHBoxLayout *iconsTogether = new QHBoxLayout();
    iconsTogether->setSpacing(10);
    iconsTogether->addLayout(upperIconLayout);
    iconsTogether->addLayout(lowerIconLayout);
    iconsTogether->setAlignment(Qt::AlignCenter);

    QHBoxLayout *recircsRow = new QHBoxLayout();
    recircsRow->setContentsMargins(0, 0, 0, 0);
    recircsRow->setSpacing(20);
    recircsRow->addLayout(upperTextLayout);
    recircsRow->addSpacing(5);
    recircsRow->addLayout(iconsTogether);
    recircsRow->addSpacing(5);
    recircsRow->addLayout(lowerTextLayout);
    recircsRow->setAlignment(Qt::AlignCenter);

    // --- FLECHAS VERTICALES HACIA CABIN ---
    QVBoxLayout *leftCol = new QVBoxLayout();
    leftCol->setSpacing(0);
    leftCol->setContentsMargins(0, 0, 0, 0);
    leftCol->addWidget(upArrowLeft, 0, Qt::AlignCenter);
    leftCol->addWidget(upLineLeft, 0, Qt::AlignCenter);

    QVBoxLayout *rightCol = new QVBoxLayout();
    rightCol->setSpacing(0);
    rightCol->setContentsMargins(0, 0, 0, 0);
    rightCol->addWidget(upArrowRight, 0, Qt::AlignCenter);
    rightCol->addWidget(upLineRight, 0, Qt::AlignCenter);

    QVBoxLayout *centerCol = new QVBoxLayout();
    centerCol->setSpacing(0);
    centerCol->addLayout(recircsRow);
    centerCol->setAlignment(Qt::AlignTop);

    // --- GRID COMÚN: flechas y recirculadores en una sola fila visual
    QGridLayout *recircAndArrowsGrid = new QGridLayout();
    recircAndArrowsGrid->setContentsMargins(0, 0, 0, 0);
    recircAndArrowsGrid->setHorizontalSpacing(15);
    recircAndArrowsGrid->addLayout(leftCol, 0, 0);
    recircAndArrowsGrid->addLayout(centerCol, 0, 1);
    recircAndArrowsGrid->addLayout(rightCol, 0, 2);
    recircAndArrowsGrid->setColumnStretch(0, 1);
    recircAndArrowsGrid->setColumnStretch(1, 2);
    recircAndArrowsGrid->setColumnStretch(2, 1);

    // --- AGREGARLO AL BLOQUE PRINCIPAL
    airDistBlock->addLayout(recircAndArrowsGrid);

    // NOTA: después de este bloque, tú ya agregas airDistRow (AIR DISTRIBUTION box + flechas horizontales)


    // La caja AIR DISTRIBUTION se pone en medio
    airBoxWithArrows->setSpacing(2);
    airBoxWithArrows->setContentsMargins(0, 0, 0, 0);
    airBoxWithArrows->addLayout(airHDualLayout);  // flechas horizontales
    airBoxWithArrows->addWidget(airDistBox, 0, Qt::AlignCenter);  // la caja
    // agrega al layout principal

    airDistBlock->addLayout(airBoxWithArrows);


    // --- CUADROS DE TRIM HEAT (debajo de AIR DISTRIBUTION) ---
    QLabel *trimHeatLeft = new QLabel("TRIM HEAT\nFLT DECK + B + D");
    QLabel *trimHeatRight = new QLabel("TRIM HEAT\nFLT DECK + A + C");

    QString trimBoxStyle = "color: cyan; font-weight: bold; border: 1px solid cyan; background-color: black;";
    trimHeatLeft->setStyleSheet(trimBoxStyle);
    trimHeatRight->setStyleSheet(trimBoxStyle);

    trimHeatLeft->setAlignment(Qt::AlignCenter);
    trimHeatRight->setAlignment(Qt::AlignCenter);

    trimHeatLeft->setFixedSize(130, 35);
    trimHeatRight->setFixedSize(130, 35);

    QHBoxLayout *trimHeatRow = new QHBoxLayout();
    trimHeatRow->setSpacing(10);
    trimHeatRow->addStretch(1);

    // --- NUEVO BLOQUE "L" DEBAJO DE TRIM HEAT (centrado con TRIM HEAT LEFT) ---
    QVBoxLayout *lConnectionBlock = new QVBoxLayout();
    lConnectionBlock->setContentsMargins(0, 0, 0, 0);
    lConnectionBlock->setSpacing(0);

    // Letra "L"
    QLabel *labelL_lower = new QLabel("L");
    labelL_lower->setStyleSheet("color: cyan; font-weight: bold; font-size: 12px;");
    labelL_lower->setAlignment(Qt::AlignCenter);

    // Flecha vertical hacia arriba
    QLabel *arrowHeadUp_lower = new QLabel("↑");
    arrowHeadUp_lower->setStyleSheet("color: lime; font-size: 20px; font-weight: bold;");
    arrowHeadUp_lower->setAlignment(Qt::AlignCenter);

    // Línea vertical verde
    QFrame *verticalLine = new QFrame();
    verticalLine->setFrameShape(QFrame::VLine);
    verticalLine->setStyleSheet("background-color: lime;");
    verticalLine->setFixedSize(3, 45);

    // Círculo con línea atravesando
    QFrame *circle = new QFrame();
    circle->setStyleSheet("border: 2px solid lime; border-radius: 6px; background-color: black;");
    circle->setFixedSize(20, 20);

    QGridLayout *circleOverlay_lower = new QGridLayout();
    circleOverlay_lower->setContentsMargins(0, 0, 0, 0);
    circleOverlay_lower->setSpacing(0);
    circleOverlay_lower->addWidget(circle, 0, 0, Qt::AlignCenter);
    circleOverlay_lower->addWidget(verticalLine, 0, 0, Qt::AlignCenter);

    QWidget *circleWidget = new QWidget();
    circleWidget->setLayout(circleOverlay_lower);

    // Línea horizontal verde
    QFrame *horizontalLine_lower = new QFrame();
    horizontalLine_lower->setFrameShape(QFrame::HLine);
    horizontalLine_lower->setStyleSheet("background-color: lime;");
    horizontalLine_lower->setFixedSize(70, 3);

    // Añadir en orden: letra, flecha, círculo y línea
    lConnectionBlock->addWidget(labelL_lower);
    lConnectionBlock->addWidget(arrowHeadUp_lower);
    lConnectionBlock->addWidget(circleWidget);
    lConnectionBlock->addWidget(horizontalLine_lower, 0, Qt::AlignHCenter);

    // Contenedor izquierdo
    QWidget *leftTrimWidget = new QWidget();
    QVBoxLayout *leftTrimLayout = new QVBoxLayout(leftTrimWidget);
    leftTrimLayout->setContentsMargins(0, 0, 0, 0);
    leftTrimLayout->setSpacing(5);
    leftTrimLayout->addWidget(trimHeatLeft, 0, Qt::AlignCenter);
    leftTrimLayout->addLayout(lConnectionBlock);
    leftTrimWidget->setFixedHeight(100);  // Ajusta según la altura total del bloque izquierdo

    // Contenedor derecho (emula altura del izquierdo)
    QWidget *rightTrimWidget = new QWidget();
    QVBoxLayout *rightTrimLayout = new QVBoxLayout(rightTrimWidget);
    rightTrimLayout->setContentsMargins(0, 0, 0, 0);
    rightTrimLayout->setSpacing(5);
    rightTrimLayout->addSpacing(5);  // Separación superior
    rightTrimLayout->addWidget(trimHeatRight, 0, Qt::AlignCenter);
    // --- NUEVO BLOQUE DERECHO (igual que el izquierdo) ---
    QVBoxLayout *rConnectionBlock = new QVBoxLayout();
    rConnectionBlock->setContentsMargins(0, 0, 0, 0);
    rConnectionBlock->setSpacing(0);

    // Letra "L"
    QLabel *labelL_right = new QLabel("R");
    labelL_right->setStyleSheet("color: cyan; font-weight: bold; font-size: 12px;");
    labelL_right->setAlignment(Qt::AlignCenter);

    // Flecha vertical hacia arriba
    QLabel *arrowHeadUp_right = new QLabel("↑");
    arrowHeadUp_right->setStyleSheet("color: lime; font-size: 20px; font-weight: bold;");
    arrowHeadUp_right->setAlignment(Qt::AlignCenter);

    // Línea vertical verde
    QFrame *verticalLine_right = new QFrame();
    verticalLine_right->setFrameShape(QFrame::VLine);
    verticalLine_right->setStyleSheet("background-color: lime;");
    verticalLine_right->setFixedSize(3, 45);

    // Círculo con línea atravesando
    QFrame *circle_right = new QFrame();
    circle_right->setStyleSheet("border: 2px solid lime; border-radius: 6px; background-color: black;");
    circle_right->setFixedSize(20, 20);

    QGridLayout *circleOverlay_right = new QGridLayout();
    circleOverlay_right->setContentsMargins(0, 0, 0, 0);
    circleOverlay_right->setSpacing(0);
    circleOverlay_right->addWidget(circle_right, 0, 0, Qt::AlignCenter);
    circleOverlay_right->addWidget(verticalLine_right, 0, 0, Qt::AlignCenter);

    QWidget *circleWidget_right = new QWidget();
    circleWidget_right->setLayout(circleOverlay_right);

    // Línea horizontal verde
    QFrame *horizontalLine_right = new QFrame();
    horizontalLine_right->setFrameShape(QFrame::HLine);
    horizontalLine_right->setStyleSheet("background-color: lime;");
    horizontalLine_right->setFixedSize(70, 3);

    // Añadir en orden
    rConnectionBlock->addWidget(labelL_right);
    rConnectionBlock->addWidget(arrowHeadUp_right);
    rConnectionBlock->addWidget(circleWidget_right);
    rConnectionBlock->addWidget(horizontalLine_right, 0, Qt::AlignHCenter);

    // Añadirlo al layout derecho
    rightTrimLayout->addLayout(rConnectionBlock);

    rightTrimLayout->addStretch();  // Empuja hacia arriba
    rightTrimWidget->setFixedHeight(100);  // Igual altura

    // Agrega ambos al layout horizontal
    trimHeatRow->addStretch(1);
    trimHeatRow->addWidget(leftTrimWidget);
    trimHeatRow->addSpacing(10);
    trimHeatRow->addWidget(rightTrimWidget);
    trimHeatRow->addStretch(1);




    trimHeatRow->addStretch(1);




    airDistBlock->addSpacing(-52);  // Ajusta a -15 si quieres subir más
    airDistBlock->addLayout(trimHeatRow);




    // Añadir al layout principal debajo de trimHeatRow
    airDistBlock->addSpacing(5);

    // Layout horizontal con espaciadores laterales











    QVBoxLayout *cabinBlock = new QVBoxLayout();
    cabinBlock->setContentsMargins(0, 0, 0, 0);
    cabinBlock->addWidget(passengerCabinBox, 0, Qt::AlignHCenter);

    // Crear layout que contenga PASSENGER CABIN + AIR DISTRIBUTION
    QVBoxLayout *topCenterBlock = new QVBoxLayout();
    topCenterBlock->setSpacing(0); // Dejamos en 0 para evitar saltos raros
    topCenterBlock->addLayout(cabinBlock);       // ← combinado: caja azul + flechas
    topCenterBlock->addLayout(airDistBlock);     // ← sigue igual






    // Conexión desde arriba (recirculación)
    QVBoxLayout *recircLayout = new QVBoxLayout();
    recircLayout->setContentsMargins(0, 0, 0, 0);
    recircLayout->setSpacing(0);



    // --- BLOQUE IZQUIERDO COMPLETO ---
    QVBoxLayout *leftSideLayout = new QVBoxLayout();
    leftSideLayout->addLayout(arrowRow);
    leftSideLayout->addLayout(lpackRow);
    leftSideLayout->addLayout(yConnectionRow);
    leftSideLayout->addLayout(compressorRow);

    // --- BLOQUE DERECHO COMPLETO ---
    QVBoxLayout *rightSideLayout = new QVBoxLayout();
    rightSideLayout->addLayout(rightArrowRow);
    rightSideLayout->addLayout(rpackRow);
    rightSideLayout->addLayout(yRightRow);
    rightSideLayout->addLayout(rightCompressorRow);

    // --- LAYOUT HORIZONTAL PARA AMBOS LADOS ---
    QHBoxLayout *packsRow = new QHBoxLayout();


    // Añadir a diagrama
    diagramLayout->addSpacing(0); // Separación respecto a secciones superiores

    QVBoxLayout *centerOverlay = new QVBoxLayout();

    // Envoltura con ancho mínimo igual al ancho del AIR DISTRIBUTION (~390px mínimo)
    QWidget *topCenterWidget = new QWidget();
    topCenterWidget->setLayout(topCenterBlock);
    topCenterWidget->setMinimumWidth(400);  // Ajusta si cambias el tamaño de AIR DISTRIBUTION

    // Centrado con layout horizontal
    QHBoxLayout *topCenterRow = new QHBoxLayout();
    topCenterRow->setContentsMargins(0, 0, 0, 0);
    topCenterRow->addStretch();
    topCenterRow->addWidget(topCenterWidget);
    topCenterRow->addStretch();

    centerOverlay->addLayout(topCenterRow);





    centerOverlay->addStretch();

    packsRow->addLayout(leftSideLayout);
    packsRow->addStretch();
    packsRow->addLayout(centerOverlay);  // 👈 ya no es topCenterBlock directo
    packsRow->addStretch();
    packsRow->addLayout(rightSideLayout);

    // Primero añadimos el bloque central (parte alta del diagrama)



    // Luego los lados
    diagramLayout->addLayout(packsRow);




    // Finalmente, añadir a la GUI
    mainLayout->addWidget(diagramWidget, 1);


    // --- ALERTA VISUAL AIR ---
    alertaAIR = new QLabel();
    alertaAIR->setText("");  // Sin texto al inicio
    alertaAIR->setAlignment(Qt::AlignCenter);
    alertaAIR->setStyleSheet("color: white; font-size: 16px; font-weight: bold;");
    alertaAIR->setFixedHeight(40);  // Puedes ajustarlo



    // Layout centrado para la alerta
    QHBoxLayout *alertaLayout = new QHBoxLayout();
    alertaAIR->setFixedWidth(380);  // Puedes ajustar a tu gusto
    alertaLayout->addStretch();
    alertaLayout->addWidget(alertaAIR);
    alertaLayout->addStretch();

    // Añadir al layout principal
    mainLayout->addLayout(alertaLayout);









    // Añadir separador vertical (espacio expandible)
    mainLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));

    // Crear widget central y aplicar layout principal
    this->setLayout(mainLayout);
    this->setStyleSheet("background-color: black;");

    // --- INICIALIZACIÓN DEL LECTOR DE GLOBAL.txt (AIR) ---
    archivoAIR.setFileName("GLOBAL.txt");

    if (!archivoAIR.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "[ERROR] No se pudo abrir GLOBAL.txt";
        return;
    }

    streamAIR.setDevice(&archivoAIR);

    timerAIR = new QTimer(this);
    connect(timerAIR, &QTimer::timeout, this, &AIR_Widget::leerSiguienteLineaAIR);
    timerAIR->start(24);  // 24 milisegundos entre líneas (~41.67 Hz)

}


void AIR_Widget::leerSiguienteLineaAIR() {
    if (streamAIR.atEnd()) {
        timerAIR->stop();
        qDebug() << "[FIN] Se alcanzó el final del archivo GLOBAL.txt";
        return;
    }

    QString linea = streamAIR.readLine();
    std::string lineaStd = linea.toStdString();

    // --- ENVÍO A CADA RANK ---
    for (int destino = 1; destino <= 3; ++destino) {
        MPI_Send(lineaStd.c_str(), lineaStd.size() + 1, MPI_CHAR, destino, 0, MPI_COMM_WORLD);
        qDebug() << "[ENVÍO][RANK 0] Línea enviada a RANK" << destino << ":" << lineaStd.c_str();
    }

    // Confirmación general
    qDebug() << "[INFO] Línea enviada a esclavos:" << lineaStd.c_str();

    QStringList valores = linea.split(',');

    // Debug específico en zona de primer alerta
    if (contadorFilasAIR >= 14990 && contadorFilasAIR <= 15050) {
        qDebug() << "[DEBUG] Fila:" << contadorFilasAIR
                 << "| TRIM_L:" << valores[8]
                 << "| PACK_L:" << valores[14]
                 << "| COMP3:" << valores[12];
    }

    // --- ACTUALIZACIÓN VISUAL ---
    if (valores.size() != 21) return;

    float temps[8];
    for (int i = 0; i < 8; ++i) {
        temps[i] = valores[i].toFloat();
    }

    contadorFilasAIR++;

    if (contadorFilasAIR % 7 == 0) {
        fltDeckReal->setText(QString::number(temps[0], 'f', 1));
        zoneAReal->setText(QString::number(temps[1], 'f', 1));
        zoneBReal->setText(QString::number(temps[2], 'f', 1));
        zoneCReal->setText(QString::number(temps[3], 'f', 1));
        zoneDReal->setText(QString::number(temps[4], 'f', 1));
        fwdTemp->setText(QString::number(temps[5], 'f', 1));
        aftTemp->setText(QString::number(temps[6], 'f', 1));
        bulkTemp->setText(QString::number(temps[7], 'f', 1));
    }

    // --- RECEPCIÓN DE ALERTAS ---
    char alertaBuffer[128] = {0};
    MPI_Status status;
    bool alertaRecibida = false;

    for (int src = 1; src <= 3; ++src) {
        int flag = 0;
        MPI_Iprobe(src, 1, MPI_COMM_WORLD, &flag, &status);
        if (flag) {
            MPI_Recv(alertaBuffer, sizeof(alertaBuffer), MPI_CHAR, src, 1, MPI_COMM_WORLD, &status);
            alertaRecibida = true;
            qDebug() << "[RECEPCIÓN][RANK 0] Mensaje recibido de RANK" << src << ":" << alertaBuffer;
            break;
        }
    }

    if (alertaRecibida) {
        qDebug() << "[GUI] Recibida alerta desde MPI:" << alertaBuffer;
        QString alertaTexto(alertaBuffer);
        QStringList partes = alertaTexto.split('|');
        if (partes.size() == 2) {
            QString mensaje = partes[0];
            QString color = partes[1];
            QString estilo = QString("background-color: %1; color: white; font-size: 16px; font-weight: bold; border: 1px solid white;").arg(color);
            alertaAIR->setText(mensaje);
            alertaAIR->setStyleSheet(estilo);
        }
    } else {
        alertaAIR->clear();
        alertaAIR->setStyleSheet("");
    }
}


AIR_Widget::~AIR_Widget()
{
    delete ui;
}
