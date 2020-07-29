#include "title.h"
#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLayout>
#include "button.h"
#include "devicesettingwidget.h"
#include "tcpsettingwidget.h"
#include "patienterinfowidget.h"
//#include "client.h"
Title::Title(QWidget *parent) : QWidget(parent)
{
//    layout->addWidget(peopleIcon);
    layout->addWidget(deviceAndNote);

    layout->addSpacerItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

    layout->addWidget(cloudIcon);
    layout->addSpacing(6);
    layout->addWidget(exclamationIcon);
    layout->addSpacing(10);
    layout->addWidget(peopleInfoIcon);
    layout->addSpacing(10);
    layout->addWidget(scaleIcon);
    layout->addSpacing(6);
    layout->setSpacing(8);
    layout->setMargin(6);

    deviceAndNote->setText("设备: " + QNetworkInterface::allInterfaces()[0].hardwareAddress().split(":").join("0") + "  备注: 001");
    deviceAndNote->setStyleSheet("color: white;font: 11pt ;");

    this->setLayout(layout);

    //槽函数连接   点击出现一系列子界面

    connect(cloudIcon, &Button::clicked, this, &Title::openTCPWindow);

    connect(exclamationIcon, &Button::clicked, this, &Title::openDSWindow);

   connect(peopleInfoIcon, &Button::clicked, this, &Title::openINFOWindow);

    connect(scaleIcon, &Button::clicked, this, &Title::setFullscreen);

   connect(tcpsettings, &TCPSettingWidget::tcpipChanged, this, &Title::middleTCPSlot);

   connect(ds, &DeviceSettingWidget::noteChangeSig, this, &Title::setNotes);



}

void Title::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void Title::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
//    *peoplePNG = peoplePNG->scaledToHeight(this->height() - 20, Qt::SmoothTransformation);
    *exclamationPNG = exclamationPNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
    *scalePNG = scalePNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
    *cloudPNG = cloudPNG->scaledToHeight(this->height() - 12, Qt::SmoothTransformation);
    *infoPNG = infoPNG->scaledToHeight(this->height() - 24, Qt::SmoothTransformation);
//    peopleIcon->setPixmap(*peoplePNG);
    cloudIcon->setPixmap(*cloudPNG);
    peopleInfoIcon->setPixmap(*infoPNG);
    scaleIcon->setPixmap(*scalePNG);
    exclamationIcon->setPixmap(*exclamationPNG);
    tcpsettings->setWindowSize(this->width()/3, this->height()*3);
}

void Title::openDSWindow()
{
       ds->show();
}

void Title::openTCPWindow()
{
      tcpsettings->show();
}

void Title::openINFOWindow()
{
     pinfo->show();
}

void Title::setFullscreen()
{
    if(isfullscreen)
        emit disablefullscreen();
    else
        emit enablefullscreen();
    isfullscreen = !isfullscreen;
}

void Title::middleTCPSlot(QString ip, quint16 port)
{
    emit middleTCP(ip, port);
//   pinfo->client.ipAddr = ip;
//    pinfo->client.port = port;
}

void Title::setNotes(QString note)
{
    deviceAndNote->setText("设备: " + QNetworkInterface::allInterfaces()[0].hardwareAddress().split(":").join("0") + "  备注: " + note);
}
