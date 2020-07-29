#include "tempwidget.h"

TEMPWidget::TEMPWidget(QWidget *parent) : QWidget(parent)
{
    head->setStyleSheet("background-color:rgb(0,0,0,)");
    head->setFixedHeight(35);
    head->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    title->setStyleSheet("color: rgb(255, 255, 255);font: 11pt ;");

    //头部temp
    title->setText("TEMP");


    // 中部T1-?-,T2-?-,TD-?-,C
    t1->setText("T1 -?-");
    t2->setText("T2 -?-");
    td->setText("TD -?-");
    c->setText("℃");




    //头部布局设计
    layoutHead->addWidget(title,0,Qt::AlignLeft);
    layoutHead->addWidget(tu, 0 ,Qt::AlignRight );
    head->setLayout(layoutHead);





    //中部布局设计
    layoutBody->addWidget(t1,0, Qt::AlignHCenter|Qt::AlignTop);
    layoutBody->addWidget(t2, 0, Qt::AlignHCenter|Qt::AlignBottom);
    z1->setLayout(layoutBody);
    layoutBody2->addWidget(td, 0, Qt::AlignCenter);
    z2->setLayout(layoutBody2);
    layoutBody1->addWidget(z1);
    layoutBody1->addWidget(z2);
    body->setLayout(layoutBody1);
    layoutBody->setMargin(0);
    layoutBody1->setMargin(0);
    layoutBody2->setMargin(0);
    layoutBody->setSpacing(0);
    layoutBody1->setSpacing(0);
    layoutBody2->setSpacing(0);



    //整体布局设计
    layout->addWidget(head,0);
    layout->addWidget(c,0,Qt::AlignRight);
    layout->addWidget(body);
    layout->addWidget(nothing);
    layout->setMargin(0);
    this->setLayout(layout);
}

void TEMPWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TEMPWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);                         //st界面的几个label的排布，也是根据界面缩放比例进行
    *pix = pix->scaledToHeight(head->height()-18, Qt::SmoothTransformation);
    tu->setPixmap(*pix);
    int w = this->width(), h = this->height();
    int px22 = w*21/128 > h*21/128? h*21/128 : w*21/128;

    t1->setStyleSheet(QString("color: rgb(230, 0, 200);font:%1px;").arg(px22));
    t2->setStyleSheet(QString("color: rgb(230, 0, 200);font:%1px;").arg(px22));
    td->setStyleSheet(QString("color: rgb(230, 0, 200);font:%1px;").arg(px22));
    c->setStyleSheet(QString("color: rgb(230, 0, 200);font:%1pxt;").arg(px22));
}

void TEMPWidget::setT1Data(short t1Num)
{
    if(t1Num != -1)
    t1->setText(QString("T1 %1").arg(t1Num));
    dataForTCPSend1 = t1Num;
}

void TEMPWidget::setT2Data(short t2Num)
{
    if(t2Num != -1)
    t2->setText(QString("T2 %1").arg(t2Num));
    dataForTCPSend2 = t2Num;
}

void TEMPWidget::setTDData(short tdNum)
{
    if(tdNum != -1)
    td->setText(QString("TD %1").arg(tdNum));
    dataForTCPSend3 = tdNum;
}
