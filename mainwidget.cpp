#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    //   c1widget   布局
    //    hrwidget
    //   labelbutton
    //    main
    //   nibpwidget
    //  plotwidget
    //  respwidget
    //  spo2widget
     //  stwidget
    //  tempwidget
    QScreen* screen = QGuiApplication::screens().at(0);
    QRect screenRect = screen->availableGeometry();
    this->resize(screenRect.width()*2/3, screenRect.height()*2/3);
    this->setWindowTitle("随便组一组医疗监护仪");
    title.setFixedHeight(50);
    title.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    splitTitle->addWidget(&title);
    splitTitle->addWidget(mainW);
    splitTitle->setMargin(0);
    splitTitle->setSpacing(1);
    title.setStyleSheet("background-color: rgb(0,0,0)");
    mainW->setStyleSheet("background-color: white");
    ecgiiPlot.setStyleSheet("background-color: rgb(0,0,0)");
    spo2Plot.setStyleSheet("background-color: rgb(0,0,0)");
    bpPlot.setStyleSheet("background-color: rgb(0,0,0)");
    hr.setStyleSheet("background-color: rgb(0,0,0)");
    st.setStyleSheet("background-color: rgb(0,0,0)");
    nibp.setStyleSheet("background-color: rgb(0,0,0)");
    spo2.setStyleSheet("background-color: rgb(0,0,0)");
    temp.setStyleSheet("background-color: rgb(0,0,0)");
    resp.setStyleSheet("background-color: rgb(0,0,0)");
    c1.setStyleSheet("background-color: rgb(0,0,0)");





    leftrightLayout->addWidget(left);
    leftrightLayout->addWidget(right);
    leftrightLayout->setStretch(0, 2);
    leftrightLayout->setStretch(1, 1);
    leftrightLayout->setMargin(0);
    leftrightLayout->setSpacing(1);
    leftPlotsLayout->addWidget(&ecgiiPlot);
    leftPlotsLayout->addWidget(&spo2Plot);
    leftPlotsLayout->addWidget(&bpPlot);
    leftPlotsLayout->setMargin(0);
    leftPlotsLayout->setSpacing(1);

    rightGrids->addWidget(&hr,0, 0, 1, 1);
    rightGrids->addWidget(&st,0, 1, 1, 1);
    rightGrids->addWidget(&nibp,1, 0, 1, 2);
    rightGrids->addWidget(&spo2,2, 0, 1, 1);
    rightGrids->addWidget(&temp,2, 1, 1, 1);
    rightGrids->addWidget(&resp,3, 0, 1, 1);
    rightGrids->addWidget(&c1,3, 1, 1, 1);
    rightGrids->setMargin(0);
    rightGrids->setSpacing(1);
    rightGrids->setRowStretch(0, 1);
    rightGrids->setRowStretch(1, 1);
    rightGrids->setRowStretch(2, 1);
    rightGrids->setRowStretch(3, 1);
    rightGrids->setColumnStretch(1, 1);
    rightGrids->setColumnStretch(0, 1);

    left->setLayout(leftPlotsLayout);
    right->setLayout(rightGrids);
    mainW->setLayout(leftrightLayout);

    this->setLayout(splitTitle);

    connect(&title, &Title::enablefullscreen, this, &MainWidget::setFull);
    connect(&title, &Title::disablefullscreen, this, &MainWidget::setNotFull);

}


void MainWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
}


void MainWidget::setFull()
{
        this->showFullScreen();
}

void MainWidget::setNotFull()
{
        this->showNormal();
}

