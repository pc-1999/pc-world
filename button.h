#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QEvent>

class Button : public QLabel
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
signals:
    void clicked();

};

#endif // BUTTON_H
