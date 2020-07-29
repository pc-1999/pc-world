QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bpwave.cpp \
    button.cpp \
    c1widget.cpp \
    devicesettingwidget.cpp \
    ecgwave.cpp \
    hrwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    nibpwidget.cpp \
    patienterinfowidget.cpp \
    plotwidget.cpp \
    qwidgetdraw.cpp \
    qwidgetdraw2.cpp \
    qwidgetdraw3.cpp \
    respwidget.cpp \
    serial.cpp \
    spo2wave.cpp \
    spo2widget.cpp \
    stwidget.cpp \
    tcpsettingwidget.cpp \
    tempwidget.cpp \
    title.cpp

HEADERS += \
    bpwave.h \
    button.h \
    c1widget.h \
    devicesettingwidget.h \
    ecgwave.h \
    hrwidget.h \
    mainwidget.h \
    nibpwidget.h \
    patienterinfowidget.h \
    plotwidget.h \
    qwidgetdraw.h \
    qwidgetdraw2.h \
    qwidgetdraw3.h \
    respwidget.h \
    serial.h \
    spo2wave.h \
    spo2widget.h \
    stwidget.h \
    tcpsettingwidget.h \
    tempwidget.h \
    title.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
