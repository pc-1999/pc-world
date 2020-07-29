#include "c1widget.h"


//界面中CO2区的界面
C1Widget::C1Widget(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("background-color: rgb(0, 0, 0);");      //背景颜色设置
    head->setFixedHeight(35);                          //高度固定
    head->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);   //固定
    body->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);  //body可扩展
    bottom->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    title->setStyleSheet("color: rgb(255, 255, 255);font: 11pt ;");  //标题设置颜色字体


    //头部co2
    title->setText("CO2");
    setting->setPixmap(*pix);

    //中部-?-
    data->setText("-?-");
    bpm->setText("mmHg");

    //尾部-?-
    ins->setText("ins -?-");
    awrr->setText("awrr -?-");

    //头部布局设计以及head背景颜色
    layoutHead->addWidget(title,0,Qt::AlignLeft);
    layoutHead->addWidget(setting, 0 ,Qt::AlignRight );
    head->setStyleSheet("background-color:rgb(0,0,0,)");
    head->setLayout(layoutHead);
    //中部布局设计
    layoutBody->addWidget(data, 0, Qt::AlignCenter|Qt::AlignBottom);
    layoutBody->addWidget(bpm ,0 ,Qt::AlignRight | Qt::AlignTop);
    body->setLayout(layoutBody);
    //尾部布局设计
    layoutBottom->addWidget(ins, 0, Qt::AlignCenter|Qt::AlignTop);
    layoutBottom->addWidget(awrr, 0, Qt::AlignCenter|Qt::AlignTop);
    bottom->setLayout(layoutBottom);

    //整体布局设计
    layoutResp->addWidget(head,0, Qt::AlignTop);
    layoutResp->addWidget(body, 0,Qt::AlignTop);
    layoutResp->addWidget(bottom, 0, Qt::AlignTop);
    layoutResp->setMargin(0);
    layoutResp->setSpacing(0);
    this->setLayout(layoutResp);
}

void C1Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    int h = this->height();
    int px15 = h*15/128;
    int px40 = h*40/128;
    data->setStyleSheet(QString("color: rgb(255, 242, 51); font:%1px;").arg(px40));  //每个字符的位置设计，根据界面比例能够实现缩放及放大
    ins->setStyleSheet(QString("color: rgb(255, 242, 51);font:%1px;").arg(px15));
    bpm->setStyleSheet(QString("color: rgb(255, 242, 51);font:%1px;").arg(px15));
    awrr->setStyleSheet(QString("color: rgb(255, 242, 51);font:%1px;").arg(px15));
}

void C1Widget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaledToHeight(head->height()-18, Qt::SmoothTransformation);
    setting->setPixmap(*pix);
}

void C1Widget::setCO2Num(short co2num)
{
    if(co2num != -1)
    data->setText(QString("%1").arg(co2num));
    dataForTCPSend1 = co2num;
}

void C1Widget::setINSNum(short insNum)
{
    if(insNum != -1)
    data->setText(QString("%1").arg(insNum));
    dataForTCPSend3 = insNum;
}

void C1Widget::setAWRRNum(short awrrNum)
{
    if(awrrNum != -1)
    data->setText(QString("%1").arg(awrrNum));
    dataForTCPSend2 = awrrNum;
}
