#include "tcpsettingwidget.h"

TCPSettingWidget::TCPSettingWidget(QWidget *parent) : QWidget(parent)
{

    this->resize(300,300);
    this->setWindowTitle("TCP");
    ipLayout->addWidget(ipLabel);
    ipLayout->addWidget(ipEdit);
    portLayout->addWidget(portLabel);
    portLayout->addWidget(portEdit);
    buttonLayout->addWidget(testBtn);
    buttonLayout->addWidget(applyBtn);
    all->addLayout(ipLayout);
    all->addLayout(portLayout);
    all->addLayout(buttonLayout);
    this->setLayout(all);

    //IP:
    //串口：
    //Test    Apply


    ipLabel->setText("IP:");
    portLabel->setText("串口:");
    testBtn->setText("Test");
    applyBtn->setText("Apply");

    //这里需要连接槽函数

//    connect(applyBtn, &QPushButton::clicked, this, &TCPSettingsWidget::setTCPIP);
//    connect(testBtn, &QPushButton::clicked, this, &TCPSettingsWidget::testTCPIP);
//    connect(this, &TCPSettingsWidget::testSig, socketForTest, &TCPSocket::testTCPIP);
//    connect(socketForTest, &TCPSocket::testSuccess, this, &TCPSettingsWidget::successTest);
//    connect(socketForTest, &TCPSocket::testFailed, this, &TCPSettingsWidget::failTest);
//    socketForTest->moveToThread(&thread);
    thread.start();
}

void TCPSettingWidget::setWindowSize(int w, int h)
{
       emit tcpipChanged(ipEdit->text(), portEdit->text().toUInt());
}

void TCPSettingWidget::setTCPIP()
{
//      emit testSig(ipEdit->text(), portEdit->text().toUInt());
}

void TCPSettingWidget::testTCPIP()
{
//      QMessageBox::information(NULL, "Success", "成功");
}

void TCPSettingWidget::successTest()
{
//       QMessageBox::information(NULL, "Failed", "失败");
}

void TCPSettingWidget::failTest()
{
//    this->resize(w, h);
}
