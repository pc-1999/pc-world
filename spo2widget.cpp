#include "spo2widget.h"

SPO2Widget::SPO2Widget(QWidget *parent) : QWidget(parent)
{

    head->setFixedHeight(35);
    head->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    title->setStyleSheet("color: rgb(255, 255, 255);font: 11pt ;");

     //头部spo
    title->setText("SPO2");
    //tu->setPixmap();
    //中部98%
    data->setText("98");
    fu->setText("%");
    //底部84bpm
    bpm->setText("84 bpm");
    //头部布局设计，颜色
    layoutHead->addWidget(title,0,Qt::AlignLeft);
    layoutHead->addWidget(tu,0,Qt::AlignRight );
    head->setStyleSheet("background-color:rgb(0,0,0,)");
    head->setLayout(layoutHead);
    //中部布局设计
    layoutBody->addWidget(nothing);
    layoutBody->addWidget(data,0,Qt::AlignCenter);
    layoutBody->addWidget(fu,0,Qt::AlignRight | Qt::AlignTop);
    layoutBody->setMargin(2);
    body->setLayout(layoutBody);
    body->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    //底部布局设计
    layoutBottom->addWidget(bpm,0,Qt::AlignRight);
    layoutBottom->addSpacing(6);
    layoutBottom->setMargin(0);
    bottom->setLayout(layoutBottom);
    bottom->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    //整体布局设计
    layout->addWidget(head,0);
    layout->addWidget(body, 1);
    layout->addWidget(bottom, 0);
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);
}

void SPO2Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void SPO2Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);              //nibp界面的几个label的排布，也是根据界面缩放比例进行
    *pix = pix->scaledToHeight(head->height() - 18, Qt::SmoothTransformation);
    tu->setPixmap(*pix);
    int w = this->width(), h = this->height();
    int px15 = w*15/128 > h*15/128? h*15/128 : w*15/128;
    int px50 = w*45/128 > h*45/128? h*45/128 : w*45/128;

    data->setStyleSheet(QString("color: rgb(255, 0, 4);font:%1px;").arg(px50));
    fu->setStyleSheet(QString("color: rgb(255, 0, 4);font:%1px;").arg(px15));
    nothing->setStyleSheet(QString("color: rgb(255, 0, 4);font:%1px;").arg(px15));
    bpm->setStyleSheet(QString("color: rgb(255, 0, 4);font:%1px;").arg(px15));
}

void SPO2Widget::setDataNum(short dataNum)
{

    if(dataNum != -1)
    data->setText(QString("%1").arg(dataNum));
    dataForTCPSend2 = dataNum;
}

void SPO2Widget::setBPMNum(short bpmNum)
{
    if(bpmNum != -1)
    bpm->setText(QString("%1 bpm").arg(bpmNum));
    dataForTCPSend1 = bpmNum;
}
