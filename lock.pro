#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T16:21:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lock
TEMPLATE = app


SOURCES += main.cpp\
        key.cpp \
    producer.cpp \
    consumer.cpp

HEADERS  += key.h \
    producer.h \
    consumer.h

FORMS    += key.ui
