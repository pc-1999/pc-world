#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QThread>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QScreen>
#include <QGuiApplication>
#include "plotwidget.h"
#include "title.h"
#include "hrwidget.h"
#include "stwidget.h"
#include "nibpwidget.h"
#include "respwidget.h"
#include "c1widget.h"
#include "spo2widget.h"
#include "tempwidget.h"
#include "qwidgetdraw.h"
#include "qwidgetdraw2.h"
#include "qwidgetdraw3.h"
#include "ecgwave.h"
#include "spo2wave.h"
#include "bpwave.h"
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);


    void resizeEvent(QResizeEvent *event) override;

    //布局Layout
    QVBoxLayout *splitTitle = new QVBoxLayout;
    QVBoxLayout *leftPlotsLayout = new QVBoxLayout;
    QHBoxLayout *leftrightLayout = new QHBoxLayout;
    QGridLayout *rightGrids = new QGridLayout;

    //布局Widget
    QWidget *left = new QWidget(this);
    QWidget *right = new QWidget(this);
    QWidget *mainW = new QWidget(this);

    Title title;
    EcgWave ecgiiPlot;
    SPO2Wave spo2Plot;
    BPWave bpPlot;
    HrWidget hr;
    STWidget st;
    NIBPWidget nibp;
    SPO2Widget spo2;
    TEMPWidget temp;
    RESPWidget resp;
    C1Widget c1;

//    GetSerial *gs = new GetSerial();

//    Client cl;
    QThread tcpThread;
    QString patientName;
    QString patientSex;
    QString patientAge;
    QString patientID;
public slots:
    void setFull();
    void setNotFull();
signals:
    void initTCPSig();
};
#endif // MAINWIDGET_H
