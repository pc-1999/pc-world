#include "button.h"

Button::Button(QWidget *parent) : QLabel(parent)
{

}

void Button::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    this->setStyleSheet("background-color: black;");
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("background-color: rgb(87, 96, 111);");
    emit clicked();
}

void Button::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("background-color: rgb(87, 96, 111);");
}

void Button::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("");
}
