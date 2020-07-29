#ifndef QWIDGETDRAW3_H
#define QWIDGETDRAW3_H

#include <QWidget>

class QWidgetDraw3 : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetDraw3(QWidget *parent = nullptr);


    int ecgDataIndex;

    qreal index;
    qreal range;
    QPixmap *pixmap;

    virtual void timerEvent(QTimerEvent *event);
    void  drawWaveToPixmap();

    virtual void paintEvent(QPaintEvent * event);
    void  drawRESPWave(QPainter *painter);

};

#endif // QWIDGETDRAW3_H
