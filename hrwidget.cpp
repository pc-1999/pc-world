#include "hrwidget.h"


//界面中hr区的界面
HrWidget::HrWidget(QWidget *parent) : QWidget(parent)
{
    title->setText("HR");    //标题hr
    data->setText("80");     //数据
    bpm->setText("bpm");     //bpm
    title->setStyleSheet("color:white; font: 11pt");    //title颜色及背景颜色
    titlebar->setStyleSheet("background-color:rgb(0,0,0,);");

    titlebar->setFixedHeight(35);           //title高度
    titlebarLayout->addWidget(title, 0, Qt::AlignLeft);
    titlebarLayout->addWidget(pixContainer, 0, Qt::AlignRight);
    titlebar->setLayout(titlebarLayout);

    hrlayout->addWidget(titlebar);         //hr布局
    hrlayout->addWidget(bpm,0,Qt::AlignRight|Qt::AlignTop);
    hrlayout->addWidget(data,1,Qt::AlignCenter);
    hrlayout->addWidget(bpm2nothing,0,Qt::AlignRight|Qt::AlignTop);
    hrlayout->setMargin(0);
    hrlayout->setSpacing(0);
    this->setLayout(hrlayout);
}

void HrWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void HrWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);                    //hr界面的几个label的排布，也是根据界面缩放比例进行
    *pix = pix->scaledToHeight(titlebar->height()-18);
    pixContainer->setPixmap(*pix);
    int w = this->width(), h = this->height();
    int px15 = w*15/128 > h*15/128? h*15/128 : w*15/128;
    int px50 = w*50/128 > h*50/128? h*50/128 : w*50/128;
    data->setStyleSheet(QString("color:rgb(81, 255, 0); font: %1px").arg(px50));
    bpm->setStyleSheet(QString("color:rgb(81, 255, 0); font: %1px").arg(px15));
    bpm2nothing->setStyleSheet(QString("color:rgb(81, 255, 0); font: %1px").arg(px15));
}

void HrWidget::setData(short bpmNum)
{
    if(bpmNum != -1)
    data->setText(QString("%1").arg(bpmNum));
    dataForTCPSend = bpmNum;
}
