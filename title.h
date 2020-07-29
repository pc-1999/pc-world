#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLayout>
#include "button.h"
#include "devicesettingwidget.h"
#include "tcpsettingwidget.h"
#include "patienterinfowidget.h"
//#include "client.h"   还需要一个客户端

class Title : public QWidget
{
    Q_OBJECT
public:
    explicit Title(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    //title部分主要显示设备信息，备注      以及四个图标的点击，具体可以参见老师的图片，四个图标的点击分别实现IP配置，串口设备绑定,病人信息显示以及全屏。
    //此部分需要结合之前几个小界面

    QHBoxLayout *layout = new QHBoxLayout(this);
    QLabel *deviceAndNote = new QLabel(this);      //设备信息以及备注信息
 /*   QLabel *peopleIcon = new QLabel(this);  */       //一个小人的图标，最左边做装饰用
    Button *cloudIcon = new Button(this);          //云朵图标  点击进去为IP
    Button *exclamationIcon = new Button(this);    //感叹号的图标  点击进去为串口设置
    Button *peopleInfoIcon = new Button(this);     // 人形图标   点击进去为病人信息
    Button *scaleIcon = new Button(this);         //   放大全屏图标  点击进入全屏

/*    QPixmap *peoplePNG = new QPixmap(":/new/prefix1/imags/people.png");  */    //几个图片的路径
    QPixmap *exclamationPNG = new QPixmap(":/new/prefix1/imags/exclamation.png");
    QPixmap *scalePNG = new QPixmap(":/new/prefix1/imags/scale.png");
    QPixmap *cloudPNG = new QPixmap(":/new/prefix1/imags/cloud.png");
    QPixmap *infoPNG = new QPixmap(":/new/prefix1/imags/info.png");

    DeviceSettingWidget       *ds = new DeviceSettingWidget;
    TCPSettingWidget *tcpsettings = new TCPSettingWidget;
    PatienterInfoWidget *pinfo = new PatienterInfoWidget;
    bool isfullscreen = false;

public slots:
    void openDSWindow();
    void openTCPWindow();     //tcp
    void openINFOWindow();     //病人信息
    void setFullscreen();      //全屏
    void middleTCPSlot(QString ip, quint16 port);
    void setNotes(QString note);
signals:
    void enablefullscreen();
    void disablefullscreen();
    void middleTCP(QString ip, quint16 port);

};

#endif // TITLE_H
