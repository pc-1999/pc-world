
#include "ecgwave.h"
#include "qwidgetdraw.h"
#include <QApplication>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QPainter>
#include<QDateTime>
#include<QTimer>
#include<QString>
#include<QDebug>
#include<QLabel>
#include<qmath.h>
#include<QPixmap>
#include<QTimerEvent>
#include<QBasicTimer>
#include<QLabel>
#include<QDateTime>
#include<QDebug>
EcgWave::EcgWave(QWidget *parent) : QWidget(parent)
{

    this->setStyleSheet("background-color:black");

    QLabel *title = new QLabel("ECG");
    title->setStyleSheet("font-size:20px;background-color:black;color:white");
    QWidgetDraw* waveWin = new QWidgetDraw();
    QVBoxLayout* layout= new QVBoxLayout();

    layout->addWidget(title);
    layout->addWidget(waveWin);
    layout->setStretch(0,1);
    layout->setStretch(1,5);
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);



}
