#ifndef C1WIDGET_H
#define C1WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QStyleOption>
#include <QLabel>
#include <QLayout>
#include "button.h"

class C1Widget : public QWidget
{
    Q_OBJECT
public:
    explicit C1Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    QVBoxLayout *layoutResp = new QVBoxLayout;     //布局
    QHBoxLayout *layoutHead = new QHBoxLayout;
    QHBoxLayout *layoutBody = new QHBoxLayout;
    QHBoxLayout *layoutBottom = new QHBoxLayout;

    QWidget *head = new QWidget;           //头部
    QWidget *body = new QWidget;           //中部
    QWidget *bottom = new QWidget;         //尾部

    QLabel *title = new QLabel;           //co2
    Button *setting = new Button;

    QLabel *data = new QLabel;
    QLabel *bpm = new QLabel;

    QLabel *ins = new QLabel;
    QLabel *awrr = new QLabel;
    QPixmap *pix = new QPixmap(":/new/prefix1/settings.png");      //图片
    int dataForTCPSend1;
    int dataForTCPSend2;
    int dataForTCPSend3;

public slots:
    void setCO2Num(short int co2num);
    void setINSNum(short int insNum);
    void setAWRRNum(short int awrrNum);

signals:

};

#endif // C1WIDGET_H
