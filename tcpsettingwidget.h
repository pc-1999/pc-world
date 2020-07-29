#ifndef TCPSETTINGWIDGET_H
#define TCPSETTINGWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QThread>
//#include "TCPSocket.h"

class TCPSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TCPSettingWidget(QWidget *parent = nullptr);
    void setWindowSize(int w, int h);
    QVBoxLayout *all = new QVBoxLayout;
    QHBoxLayout *ipLayout = new QHBoxLayout;
    QHBoxLayout *portLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QPushButton *applyBtn = new QPushButton;   //应用
    QPushButton *testBtn = new QPushButton;   //测试
    QLabel *ipLabel = new QLabel;    //IP
    QLabel *portLabel = new QLabel;   //串口
    QLineEdit *ipEdit = new QLineEdit;   //IP编辑
    QLineEdit *portEdit = new QLineEdit;  //串口编辑

//    TCPSocket *socketForTest = new TCPSocket;

    QThread thread;
public slots:
    void setTCPIP();
    void testTCPIP();
    void successTest();
    void failTest();

signals:
    void tcpipChanged(QString ip, quint16 port);
    void testSig(QString ip, quint16 port);
};

#endif // TCPSETTINGWIDGET_H
