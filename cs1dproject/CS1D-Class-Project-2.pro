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
    hashTable.h\
    wrapperlist.h\
    exceptionclasses.h\
    heap.h\
    heapitem.h\
    comparators.h \
        MainHeader.h\
            souvenirs.h\
                graph.h\
    stadium.h\
    datatable.h \
    addstadiumfunctionality.h

SOURCES += main.cpp\
        mainwindow.cpp\
    levenshteinDistance.cpp \
    findHashKey.cpp\
    souvenirs.cpp\
    stadium.cpp \
    sqlfunctions.cpp \
    datatable.cpp \
    addstadiumfunctionality.cpp \
    createsouvenirs.cpp

FORMS    += mainwindow.ui

DISTFILES += baseball_stadiums

RESOURCES += \
    teamImages.qrc
