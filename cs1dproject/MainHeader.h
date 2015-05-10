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
enum DatabaseEnumeration
{
    PRIMARY_KEY,
    STADIUM_NAME,
    TEAM_NAME,
    STREET,
    CITY,
    STATE,
    ZIP,
    BOX_OFFICE_NUM,
    DATE_OPENED,
    CAPACITY,
    LEAGUE,
    SURFACE,
    VERTICES_AND_EDGES
};

struct vertexEdgeStruct
{
    QString otherVertex;
    float edge;
};

#endif // MAINHEADER_H
