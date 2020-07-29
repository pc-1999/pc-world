#include "nibpwidget.h"


//界面NIBP界面
NIBPWidget::NIBPWidget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background:rgb(0,0,0)");

    playoutHead->addWidget(title,0,Qt::AlignLeft);                      //布局
    playoutHead->addWidget(setting,0,Qt::AlignRight);
    wholehead->setFixedHeight(35);
    wholehead->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    wholehead->setLayout(playoutHead);
    playoutBody->addWidget(bodyLeft,1);
    playoutBody->addWidget(bodymiddle,1);
    playoutBody->addWidget(bodyright,1);
    playoutLeft->addWidget(bodyleftUp, 0);
    playoutLeft->addWidget(bodyleftLabel, 1, Qt::AlignCenter);
    bodyLeft->setLayout(playoutLeft);
    playoutmiddle->addWidget(pCurrentTimeLabel,0, Qt::AlignHCenter|Qt::AlignTop);
    playoutmiddle->addWidget(middlemiddle,1, Qt::AlignCenter);
    bodymiddle->setLayout(playoutmiddle);
    playoutRight->addWidget(righttop,0, Qt::AlignRight|Qt::AlignTop);
    playoutRight->addWidget(rightmiddle,1, Qt::AlignCenter);
    bodyright->setLayout(playoutRight);
    wholebody->setLayout(playoutBody);
    playoutWhole->addWidget(wholehead,0);
    playoutWhole->addWidget(wholebody,1);
    playoutWhole->setMargin(0);
    playoutLeft->setMargin(0);
    playoutRight->setMargin(0);
    playoutmiddle->setMargin(0);
    playoutBody->setMargin(0);
    this->setLayout(playoutWhole);

    title->setStyleSheet("color:white; font: 11pt；");
    wholehead->setStyleSheet("background-color:rgb(0,0,0,)");

    time = QTime::currentTime();                                       //时钟
    timer.start(50);
    pCurrentTimeLabel->setText(time.toString("hh:mm:ss"));
    setting->setPixmap(*pix);
    title->setText("NIBP");
    bodyleftLabel->setText("-?-");
    middlemiddle->setText("/ -?-");
    righttop->setText("mmHg");
    rightmiddle->setText("-?-");
    connect(&timer, &QTimer::timeout, this, &NIBPWidget::setLCDTime);
}

void NIBPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void NIBPWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);                                //nibp界面的几个label的排布，也是根据界面缩放比例进行
    *pix = pix->scaledToHeight(wholehead->height() - 18, Qt::SmoothTransformation);
    setting->setPixmap(*pix);
    int w = this->width();
    int h = this->height();
    int px12 = w*12/256 > h*12/128? h*12/128 : w*12/256;
    int px25 = w*25/256 > h*25/128? h*25/128 : w*25/256;
    int px40 = w*40/256 > h*40/128? h*40/128 : w*40/256;

    pCurrentTimeLabel->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px12));
    bodyleftUp->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px12));
    bodyleftLabel->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px25));
    middlemiddle->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px40));
    righttop->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px12));
    rightmiddle->setStyleSheet(QString("color:rgb(88, 76, 255);font: %1px;").arg(px40));
}

void NIBPWidget::setLCDTime()
{
    //时钟显示
    time = QTime::currentTime();
    timeStr = time.toString("hh:mm:ss");
    pCurrentTimeLabel->setText(timeStr);
}

void NIBPWidget::setLowPa(short lowPa)
{
    if(lowPa != -1)
    middlemiddle->setText(QString("%1").arg(lowPa));
    dataForTCPSend2 = lowPa;
}

void NIBPWidget::setHighPa(short highPa)
{
    if(highPa != -1)
    bodyleftLabel->setText(QString("%1").arg(highPa));
    dataForTCPSend1 = highPa;
}

void NIBPWidget::setAverage(short average)
{
    if(average != -1)
    rightmiddle->setText(QString("%1").arg(average));
    dataForTCPSend3 = average;
}
