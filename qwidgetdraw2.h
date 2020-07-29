#ifndef QWIDGETDRAW2_H
#define QWIDGETDRAW2_H

#include <QWidget>

class QWidgetDraw2 : public QWidget
{
    Q_OBJECT
public:
    explicit QWidgetDraw2(QWidget *parent = nullptr);

    int ecgDataIndex;

    qreal index;
    qreal range;
    QPixmap *pixmap;
virtual void timerEvent(QTimerEvent *event);


    void drawWaveToPixmap();
    virtual void paintEvent(QPaintEvent * event);
    void drawSPo2Wave(QPainter *painter);
};

#endif // QWIDGETDRAW2_H
