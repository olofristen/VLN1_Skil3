#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:14:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Skil-3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    data.cpp \
    domain.cpp \
    person.cpp \
    infoscientist.cpp \
    infocomputers.cpp

HEADERS  += mainwindow.h \
    computer.h \
    data.h \
    domain.h \
    person.h \
    infoscientist.h \
    infocomputers.h

FORMS    += mainwindow.ui \
    infoscientist.ui \
    infocomputers.ui

RESOURCES += \
    images.qrc
