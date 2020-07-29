#include "plotwidget.h"



PlotWidget::PlotWidget(QWidget *parent,
                       QColor color_, int xScale_, double y0_, double yScale_, int updateInterval_) : QWidget(parent),
                        color(color_), xScale(xScale_), y0(y0_), yScale(yScale_), updateInterval(updateInterval_)
{
    connect(&timer, &QTimer::timeout, this, &PlotWidget::paintSlot);
    timer.setInterval(updateInterval);
    painter = new QPainter;
    pix = new QPixmap(this->width(), this->height());
    pix->fill(Qt::black);
    label.setParent(this);
    label.move(0,0);
    label.setStyleSheet("font: 10pt \"黑体\"; background-color: black; color: white");
}


PlotWidget::~PlotWidget()
{
    timer.stop();
    delete painter;
}

void PlotWidget::paintEvent(QPaintEvent *event)
{
    label.setText(text);
    label.adjustSize();
    Q_UNUSED(event);
    paintData();
    painter->begin(this);
    painter->drawPixmap(0, 0, this->width(), this->height(),*pix);
    painter->end();
}

void PlotWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    *pix = pix->scaled(this->width(), this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    t = 0;
    data.clear();
    time.clear();
    pix->fill(Qt::black);
}

void PlotWidget::paintData()
{
    int s = data.size()-1;
    int dis = 0;
    painter->begin(pix);
    painter->setRenderHint(QPainter::Antialiasing,true);
    if(s>-1)
    {
        painter->setPen(QPen(Qt::black, 1));
        painter->setBrush(Qt::black);
        if(s<10)
            painter->drawRect(time.at(s), 0, 10, this->height());
        painter->drawRect(time.at(s)+10, 0, 10, this->height());
    }

    if(s>1)
    {
        dis = 1;
        painter->setPen(QPen(color, 2));
        while(time.at(s-dis) == time.at(s) && dis < 8 && dis < s)
        {
            data[s] = (data.at(s) + data.at(s-dis))/2;
            dis++;
        }
        if(dataForTCP.length() < 200)
            dataForTCP.append((pix->height() - data.at(s-dis))*(yScale-y0)/pix->height() + y0);
        painter->drawLine(time.at(s-dis), data.at(s-dis),
                          time.at(s), data.at(s));
    }
    painter->end();
}

void PlotWidget::sendData(double d)
{
    data.append(pix->height() - (d-y0)*pix->height()/(yScale-y0));
    time.append(t*pix->width()/xScale);
    if(!timer.isActive())
        timer.start(updateInterval);
}

void PlotWidget::paintSlot()
{
    t += 1;
    TCPInterval += 1;
    if(t==xScale)
    {
        t = 0;
        data.clear();
        time.clear();
    }
    if(TCPInterval >= 2000)
    {
        emittedFlag = false;
        TCPInterval = 0;
    }
    if(dataForTCP.size() == 200 && emittedFlag == false && connected)
    {
        emit dataFulledForTCP(plotflag, dataForTCP);
        emittedFlag = true;
    }
    this->update();
}

void PlotWidget::dataSendedTCP()
{
    emittedFlag = false;
    dataForTCP.clear();
    TCPInterval = 0;
}

void PlotWidget::connectedChanged()
{
        connected = true;
}
