#include "spo2wave.h"
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
#include <qwidgetdraw2.h>
SPO2Wave::SPO2Wave(QWidget *parent) : QWidget(parent)
{
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:black");

    QLabel *title2 = new QLabel("SPO2");
    title2->setStyleSheet("font-size:20px;background-color:black;color:white");
    QWidgetDraw2* waveWin2 = new QWidgetDraw2();
    QVBoxLayout* layout2= new QVBoxLayout();

    layout2->addWidget(title2);
    layout2->addWidget(waveWin2);
    layout2->setStretch(0,1);
    layout2->setStretch(1,5);
    layout2->setMargin(0);
    layout2->setSpacing(0);
    this->setLayout(layout2);
}
