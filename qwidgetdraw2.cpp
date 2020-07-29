#include "qwidgetdraw2.h"
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
const int ecgWave[] = {2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
        2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
        2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
        2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
        2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
        1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
        2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
        2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
        1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
        2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
        2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
        2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
        2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
        2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
        2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
        2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
        2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
        2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};

const int ecgWave2[] ={
    0x21, 0x21, 0x22, 0x22, 0x23, 0x22, 0x22, 0x21, 0x21,
    0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1b, 0x1a,
    0x19, 0x18, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12,
    0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f, 0x0e, 0x0d, 0x0c,
    0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08, 0x07, 0x06, 0x06,
    0x05, 0x05, 0x04, 0x04, 0x03, 0x03, 0x02, 0x02, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e, 0x13, 0x18, 0x1d,
    0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b, 0x40, 0x44, 0x49,
    0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a, 0x5a, 0x5a, 0x59,
    0x59, 0x57, 0x55, 0x52, 0x50, 0x4c, 0x49, 0x45, 0x42,
    0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f, 0x2c, 0x29, 0x26,
    0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e, 0x1e, 0x1d, 0x1d,
    0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x22,
    0x22, 0x21, 0x21, 0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c,
    0x1b, 0x1b, 0x1a, 0x19, 0x18, 0x18, 0x17, 0x16, 0x15,
    0x14, 0x13, 0x12, 0x11, 0x11, 0x10, 0x10, 0x0f, 0x0f,
    0x0e, 0x0d, 0x0c, 0x0c, 0x0b, 0x0a, 0x09, 0x09, 0x08,
    0x07, 0x06, 0x06, 0x05, 0x05, 0x04, 0x04, 0x03, 0x03,
    0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0a, 0x0e,
    0x13, 0x18, 0x1d, 0x23, 0x28, 0x2d, 0x32, 0x37, 0x3b,
    0x40, 0x44, 0x49, 0x4d, 0x51, 0x54, 0x57, 0x58, 0x5a,
    0x5a, 0x5a, 0x59, 0x59, 0x57, 0x55, 0x52, 0x50, 0x4c,
    0x49, 0x45, 0x42, 0x3e, 0x3b, 0x37, 0x34, 0x31, 0x2f,
    0x2c, 0x29, 0x26, 0x24, 0x22, 0x20, 0x1f, 0x1f, 0x1e,
    0x1e, 0x1d, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x21, 0x22,
    0x22, 0x23, 0x22, 0x22, 0x21,
};

const int ecgWave3[] {
    0x0f, 0x10, 0x10, 0x11, 0x12, 0x12, 0x12, 0x13, 0x13,
    0x14, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17, 0x17, 0x18,
    0x18, 0x19, 0x19, 0x19, 0x19, 0x1a, 0x19, 0x1a, 0x1a,
    0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1b, 0x1b, 0x1a, 0x1a,
    0x1a, 0x19, 0x19, 0x18, 0x18, 0x18, 0x17, 0x17, 0x15,
    0x15, 0x15, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x15,
    0x14, 0x14, 0x15, 0x14, 0x14, 0x14, 0x15, 0x17, 0x17,
    0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1b,
    0x1c, 0x1d, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x24,
    0x24, 0x26, 0x26, 0x26, 0x26, 0x24, 0x23, 0x23, 0x23,
    0x23, 0x22, 0x21, 0x20, 0x1d, 0x1d, 0x1c, 0x1c, 0x1c,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1b, 0x1c, 0x1b, 0x1a, 0x1a,
    0x19, 0x18, 0x17, 0x15, 0x14, 0x12, 0x12, 0x11, 0x10,
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f
  };
QWidgetDraw2::QWidgetDraw2(QWidget *parent) : QWidget(parent)
{
    QBasicTimer *timer = new QBasicTimer();
    timer->start(10,this);

    pixmap = new QPixmap(this->width()+1000,this->height());
    pixmap->fill(Qt::black);

    index = 0;
    ecgDataIndex = 0;
}

void QWidgetDraw2::timerEvent(QTimerEvent *event)
{
    drawWaveToPixmap();
    this->update();
}

void QWidgetDraw2::drawWaveToPixmap()
{
    QPainter pixPainter;
    pixPainter.begin(this->pixmap);//huadaotupianshang
    drawSPo2Wave(&pixPainter);
    pixPainter.end();
}

void QWidgetDraw2::paintEvent(QPaintEvent *event)
{
    QPainter * painter = new QPainter();

    painter->begin(this);
    painter->resetTransform();//坐标系复位

   // drawSineWave(painter);
    painter->drawPixmap(0,0,*pixmap);//把图画到控件上
    painter->resetTransform();
    painter->end();
}

void QWidgetDraw2::drawSPo2Wave(QPainter *painter)
{
    QPen pen ;
    pen.setWidth(2);
    pen.setColor(QColor("#FF000F"));
    painter->setPen(pen);


    index = index+2;
    if(index > width())
        index = 1;
    //擦除当前列
    painter->save();//保持当前配置
    pen.setColor(Qt::black);//修改painter画笔颜色配置
    painter->setPen(pen);
    painter->drawLine(index,0,index,height());
    painter->restore();//还原当前配置
    //绘图
    qreal height = this->height();
    QPoint linestart;
    QPoint lineEnd;

    linestart.setX(index-1);
    lineEnd.setX(index);


    qreal value = ecgWave2[ecgDataIndex];
    int y = round(height/2-((value-30)/100)*height/2);
    qDebug()<<y;
    linestart.setY(y);

    ecgDataIndex = ecgDataIndex +5;
      if(ecgDataIndex>=sizeof(ecgWave2)/sizeof(int))
        ecgDataIndex = 0;

    value = ecgWave2[ecgDataIndex];
     y = round(height/2-((value-30)/100)*height/2);
    lineEnd.setY(y);
    painter->drawLine(linestart,lineEnd);
}

