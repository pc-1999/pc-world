#ifndef PATIENTERINFOWIDGET_H
#define PATIENTERINFOWIDGET_H

#include <QWidget>
//#include "TCPSocket.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QThread>
//#include "patientinfoclient.h"

class PatienterInfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PatienterInfoWidget(QWidget *parent = nullptr);
    QThread thread;
    PatienterInfoWidget *client;
private:
    QWidget *ptopWidget = new QWidget;
    QWidget *pmiddle1Widget = new QWidget;
    QWidget *pmiddle2Widget = new QWidget;
    QWidget *pbottomWidget = new QWidget;
    QWidget *pIDnumberWidget = new QWidget;
    QLabel *name = new QLabel;           //姓名
    QLabel *sex = new QLabel;            //性别
    QLabel *age = new QLabel;            //年龄
    QLabel *IDnumber = new QLabel;      //身份证号
    QLineEdit *nameLineEdit = new QLineEdit;
    QLineEdit *sexLineEdit = new QLineEdit;
    QLineEdit *ageLineEdit = new QLineEdit;
    QLineEdit *IDnumberLineEdit = new QLineEdit;
    QPushButton *update = new QPushButton;   //刷新

    QVBoxLayout *pwholeLayout = new QVBoxLayout;
    QHBoxLayout *ptopLayout = new QHBoxLayout;
    QHBoxLayout *pmiddle1Layout = new QHBoxLayout;
    QHBoxLayout *pmiddle2Layout = new QHBoxLayout;
    QHBoxLayout *pbottomLayout = new QHBoxLayout;
    QHBoxLayout *pIDnumberLayout = new QHBoxLayout;
public slots:
    void on_update_clicked();
    void getfacilityID(QString id);
    void receivedData(QString name, QString sex, QString age, QString idNum);

signals:
    void getinfoSig();
};

#endif // PATIENTERINFOWIDGET_H
