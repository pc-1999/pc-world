#include "devicesettingwidget.h"

DeviceSettingWidget::DeviceSettingWidget(QWidget *parent) : QWidget(parent)
{


    this->setWindowTitle("Device");
    this->resize(300,300);
    //布局
    deviceLayout->addWidget(deviceID);
    deviceLayout->addWidget(deviceIDEdit);
    serialPortLayout->addWidget(serialPortLable);
    serialPortLayout->addWidget(serialChosen);
    serialPortLayout->addWidget(serialComGet);
    serialPortLayout->addWidget(serialComSet);
    notesLayout->addWidget(notesLabel);
    notesLayout->addWidget(notesEdit);
    notesLayout->addWidget(notesButton);
    allLayout->addStretch(2);
    allLayout->addLayout(deviceLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(notesLayout);
    allLayout->addStretch(1);
    allLayout->addLayout(serialPortLayout);
    allLayout->addStretch(1);
    allLayout->addStretch(2);

    this->setLayout(allLayout);

    //   设备序列号：  xxxxxxxxxxx
    //   备注：001           修改
    //   串口： 下拉框   获取本机串口   设置串口

    deviceID->setText("设备序列号：");
    deviceIDEdit->setText(QNetworkInterface::allInterfaces()[0].hardwareAddress().split(":").join("0"));
    deviceIDEdit->setEnabled(false);

    serialPortLable->setText("串口：");
    serialComGet->setText("获取本机串口");
    serialComSet->setText("设置串口");

    notesLabel->setText("备注:");
    notesEdit->setText("001");
    notesButton->setText("修改");

    connect(notesButton, &QPushButton::clicked, this, &DeviceSettingWidget::setNotes);
    connect(serialComSet, &QPushButton::clicked, this, &DeviceSettingWidget::setComNum);
    connect(serialComGet, &QPushButton::clicked, this, &DeviceSettingWidget::getComs);
}

void DeviceSettingWidget::setComNum()
{
//    gs->close();
//    gs->portName = serialChosen->currentText();
//    QMessageBox::information(NULL, "Success", "成功");
//    gs->connectPort();
//    设置串口
}

void DeviceSettingWidget::getComs()
{
//    QList<QString> coms = gs->getPortsName();
//    for(int i=0;i<coms.length();i++)
//    {
//        serialChosen->addItem(coms[i]);
//    }

    //获取串口
}

void DeviceSettingWidget::setNotes()
{
        emit noteChangeSig(notesEdit->text());
}
