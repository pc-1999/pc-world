#ifndef DEVICESETTINGWIDGET_H
#define DEVICESETTINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QLayout>
#include <QNetworkInterface>
//#include "GetSerial.h"    此处加上串口获取

class DeviceSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceSettingWidget(QWidget *parent = nullptr);

//    GetSerial *gs;      串口定义

signals:

private:
    QLabel *deviceID = new QLabel;            //设备ID
    QLabel *serialPortLable = new QLabel;     //  串口选择
    QLabel *notesLabel = new QLabel;       // 备注

    QLineEdit *deviceIDEdit = new QLineEdit;     //设备ID修改
    QPushButton *serialComSet = new QPushButton;  //设置串口号
    QPushButton *serialComGet = new QPushButton;  //获取串口号
    QComboBox *serialChosen = new QComboBox;    //串口选择框
    QLineEdit *notesEdit = new QLineEdit;       //备注框
    QPushButton *notesButton = new QPushButton;

    QVBoxLayout *allLayout = new QVBoxLayout;
    QHBoxLayout *deviceLayout = new QHBoxLayout;
    QHBoxLayout *badLayout = new QHBoxLayout;
    QHBoxLayout *serialPortLayout = new QHBoxLayout;
    QHBoxLayout *notesLayout = new QHBoxLayout;

public slots:
    void setComNum();
    void getComs();
    void setNotes();

signals:
    void noteChangeSig(QString note);
};

#endif // DEVICESETTINGWIDGET_H
