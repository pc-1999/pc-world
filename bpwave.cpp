#include "bpwave.h"
#include "ecgwave.h"
#include "qwidgetdraw3.h"
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
BPWave::BPWave(QWidget *parent) : QWidget(parent)
{
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background-color:black");

    QLabel *title3 = new QLabel("BP");
    title3->setStyleSheet("font-size:20px;background-color:rgb(000,000,000);color:white");
    QWidgetDraw3* waveWin3 = new QWidgetDraw3();
    QVBoxLayout* layout3= new QVBoxLayout();

    layout3->addWidget(title3);
    layout3->addWidget(waveWin3);
    layout3->setStretch(0,1);
    layout3->setStretch(1,5);
    layout3->setMargin(0);
    layout3->setSpacing(0);
    this->setLayout(layout3);
}
