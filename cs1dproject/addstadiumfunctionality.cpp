#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>
#include <QModelIndex>
#include <QMessageBox>
#include <QModelIndexList>
#include <fstream>
#include <QTableView>
#include <QTextStream>
#include "stadium.h"

/******************************************************************************
 *  addStadium function.
 *
 * current issue
 *
 ******************************************************************************/



void MainWindow::on_button_continueAddStadium_clicked()
{




//    QString stadium;
//    QString team;
//    QString city;
//    QString state;
//    QString grassType;

    stadium * newStadium;

    bool stadiumEmpty;
    bool teamEmpty;
    bool cityEmpty;
    bool stateEmpty;
    bool grassTypeEmpty;



    stadiumEmpty    = ui->lineEdit_stadiumName->text().isEmpty();
    teamEmpty       = ui->lineEdit_teamName->text().isEmpty();
    cityEmpty       = ui->lineEdit_cityName->text().isEmpty();
    stateEmpty      = ui->lineEdit_stateName->text().isEmpty();
    grassTypeEmpty  = ui->lineEdit_grassType->text().isEmpty();

    // We need an id / key to identify the teams by / row
    if(stadiumEmpty || teamEmpty || cityEmpty || stateEmpty || grassTypeEmpty)
    {
        QMessageBox::information(this, "Missing Entry", "Please enter the appropriate information in all fields");
    }
    else
    {

       // stadium:: stadium(QString newStadiumName, QString newTeamName,  QString newCityName,
         //                 QString newStateName,   QString newGrassType, int     newStadiumNumber)
//        newStadium = new stadium(ui->lineEdit_stadiumName->text(),
//                                 ui->lineEdit_teamName->text(),
//                                 ui->lineEdit_cityName->text(),
//                                 ui->lineEdit_stateName->text(),
//                                 ui->lineEdit_grassType->text(),
//                                 0);


    }

}
