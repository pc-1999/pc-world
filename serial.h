#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include "plotwidget.h"

class Serial : public QSerialPort
{
    Q_OBJECT
public:
    explicit Serial(QString portName_ = "COM1", QObject *parent = nullptr);
    QString portName;      //串口名字
    QList<QString> getPortsName();
    void connectPort();

private:
    void statusMachine(char data);
    int status;             //状态
    char pkgType;
    char pkgDataHead;
    int dataLength;       //数据长度
    int pkgDataCnt;
    char pkgData[7];
    int pkgDataInt[3];
    unsigned int dataForSending;

    int flagCount = 2;

public slots:
    //bool sendString(QString str);
    void readMessage();
signals:
    //void receivedData(QString nowdata);
    void receivedECGdata(int data);
    void receivedBPdata(int data);
    void receivedSPO2data(int data);

    void receivedHRdata(int data);

    void receivedST1data(int data);
    void receivedST2data(int data);
    void receivedPVCdata(int data);

    void receivedLBPdata(int data);
    void receivedHBPdata(int data);
    void receivedIBPdata(int data);

    void receivedSPO2Wdata(int data);
    void receivedBPMdata(int data);

    void receivedT1data(int data);
    void receivedT2data(int data);
    void receivedTDdata(int data);

    void receivedRESPdata(int data);

    void receivedCO2data(int data);
    void receivedAWRRdata(int data);
    void receivedINSdata(int data);

};

#endif // SERIAL_H
