#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T01:26:26
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taigu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    rail.cpp \
    drum.cpp \
    score.cpp \
    mytimer.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    rail.h \
    drum.h \
    score.h \
    mytimer.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc \
    hit.qrc \
    end.qrc \
    bgm.qrc \
    bgm2.qrc \
    haha.qrc
