#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T10:51:25
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppliContact
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    contact.cpp \
    dialognewcontact.cpp \
    dialogmodif.cpp

HEADERS  += mainwindow.h \
    contact.h \
    dialognewcontact.h \
    dialogmodif.h

FORMS    += mainwindow.ui \
    dialognewcontact.ui \
    dialogmodif.ui
