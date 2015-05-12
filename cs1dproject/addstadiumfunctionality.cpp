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
    bool zipCode;
    bool boxOffice;
    bool dateOpened;
    bool capacity;
    bool league;
    bool grassTypeEmpty;
    bool adjacentStadiums;



    stadiumEmpty     = ui->lineEdit_stadiumName->text().isEmpty();
    teamEmpty        = ui->lineEdit_teamName->text().isEmpty();
    cityEmpty        = ui->lineEdit_cityName->text().isEmpty();
    stateEmpty       = ui->lineEdit_stateName->text().isEmpty();
    zipCode          = ui->lineEdit_zipCode->text().isEmpty();
    boxOffice        = ui->lineEdit_boxOfficeNum->text().isEmpty();
    dateOpened       = ui->lineEdit_dateOpened->text().isEmpty();
    capacity         = ui->lineEdit_capacity->text().isEmpty();
    league           = ui->lineEdit_league->text().isEmpty();
    grassTypeEmpty   = ui->lineEdit_grassType->text().isEmpty();
    adjacentStadiums = ui->lineEdit_adjacentStadiums->text().isEmpty();


    // We need an id / key to identify the teams by / row
    if(stadiumEmpty   || teamEmpty     || cityEmpty  ||
       stateEmpty     || zipCode       || boxOffice  ||
       dateOpened     || capacity      || league     ||
       grassTypeEmpty || adjacentStadiums)
    {
        QMessageBox::information(this, "Missing Entry", "Please enter the appropriate information in all fields");
    }
    else
    {

        QMessageBox::information(this, "Success", "Addition succesful. To add more edges, visit modify stadium")
        //Must create a stadium here. pass the stadium object into a method that sends the data to the data base

    }

}
