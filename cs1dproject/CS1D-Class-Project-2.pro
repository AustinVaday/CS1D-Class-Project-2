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
    googleComputeInterface.h\
    hashTable.h \
    mysql_driver.h\
    mysql_connection.h\
    mysql_error.h\
    .\cppconn\build_config.h\
    .\cppconn\config.h\
    .\cppconn\connection.h\
    .\cppconn\datatype.h\
    .\cppconn\driver.h\
    .\cppconn\exception.h\
    .\cppconn\metadata.h\
    .\cppconn\parameter_metdata.h\
    .\cppconn\prepared_statement.h\
    .\cppconn\resultset_metdata.h\
    .\cppconn\resultset.h\
    .\cppconn\sqlstring.h\
    .\cppconn\statement.h\
    .\cppconn\variant.h\
    .\cppconn\version_info.h\
    .\cppconn\warning.h\

SOURCES += main.cpp\
        mainwindow.cpp\
    googleComputeInterface.cpp\



FORMS    += mainwindow.ui
