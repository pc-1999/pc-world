#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>
#include <QApplication>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QPainter>
#include<QDateTime>
#include<QTimer>
#include<QString>
#include<QDebug>
#include<QLabel>
#include<qmath.h>
#include<QPixmap>
#include<QTimerEvent>
#include<QBasicTimer>
#include<QLabel>
#include<QDateTime>
#include<QDebug>
class QWidgetDraw : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetDraw(QWidget *parent = nullptr);
public:

    int ecgDataIndex;

    qreal index;
    qreal range;
    QPixmap *pixmap;
    virtual void timerEvent(QTimerEvent *event);
    void drawWaveToPixmap();
    virtual void paintEvent(QPaintEvent *event) override;
    void drawEcgWave(QPainter *painter);
};

#endif // QWIDGETDRAW_H
