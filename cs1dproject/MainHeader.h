#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <QString>
#include <QDebug>
#include <QApplication>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QTableView>
#include <QApplication>
#include <QSqlError>
#include <QFile>
#include <QFileDialog>
#include <QDir>
using namespace std;

size_t LevenshteinDistance(const string &s1, const string &s2);

string findHashKey(QString stadiumNames[], QString searchKey, const int SIZE);


#endif // MAINHEADER_H
