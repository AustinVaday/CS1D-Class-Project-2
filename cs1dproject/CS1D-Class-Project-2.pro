#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T21:26:20
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS1D-Class-Project-2
TEMPLATE = app

HEADERS  += mainwindow.h\
    googleComputeInterface.h

SOURCES += main.cpp\
        mainwindow.cpp\
    googleComputeInterface.cpp\
    gcloud-oauth2.py\
    hashTable.h

SOURCES += main.cpp\
        mainwindow.cpp

FORMS    += mainwindow.ui
