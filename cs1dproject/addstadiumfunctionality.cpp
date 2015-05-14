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

    stadium * newStadium;
    vertexEdgeStruct newEdge;
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
    bool weightOk;
    bool street;
    bool found;
    float weight;
    vector<QString> nameVector;
    vector<QString>::iterator nameIt;
    vector<vertexEdgeStruct> adjacentVertices;
    QString temp;
    int largest = -1;


    // add in all stadiums to combobox
    for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {
        if (!(*stadiumIt).getStadiumName().isEmpty())
        {
            ui->comboBox_adjacentList->addItem((*stadiumIt).getStadiumName());
        }
    }

    for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {
        if ((*stadiumIt).getStadiumNumber() > largest)
        {
            largest = (*stadiumIt).getStadiumNumber();
        }
    }
    largest++;

    for (stadiumIt = stadiumHash.begin(); stadiumIt != stadiumHash.end(); stadiumIt++)
    {
        if (!(*stadiumIt).getStadiumName().isEmpty())
        {
            nameVector.push_back((*stadiumIt).getStadiumName());
        }
    }

    street           = ui->lineEdit_streetName->text().isEmpty();
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

//    adjacentStadiums = ui->lineEdit_adjacentStadiums->text().isEmpty();







    // We need an id / key to identify the teams by / row
    if(stadiumEmpty   || teamEmpty     || cityEmpty  ||
       stateEmpty     || zipCode       || boxOffice  ||
       dateOpened     || capacity      || league     ||
       grassTypeEmpty || street)
    {
        QMessageBox::information(this, "Missing Entry", "Please enter the appropriate information in all fields");
    }
    else
    {



        temp       = ui->comboBox_adjacentList->currentText();


        weightOk = true;

        if(ui->lineEdit_distanceAdjacentVertex->text().isEmpty())
        {
            weightOk = false;
        }
        else
        {
            weight = ui->lineEdit_distanceAdjacentVertex->text().isEmpty();
        }



        if(weightOk)
        {
            newEdge.otherVertex = ui->comboBox_adjacentList->currentText();
            newEdge.edge        = (ui->lineEdit_distanceAdjacentVertex->text()).toFloat();

            adjacentVertices.push_back(newEdge);

            newStadium  = new stadium(largest,
                                        ui->lineEdit_stadiumName->text(),
                                        ui->lineEdit_teamName->text(),
                                        ui->lineEdit_streetName->text(),
                                        ui->lineEdit_cityName->text(),
                                        ui->lineEdit_stateName->text(),
                                        ui->lineEdit_zipCode->text().toInt(),
                                        ui->lineEdit_boxOfficeNum->text(),
                                        ui->lineEdit_dateOpened->text(),
                                        ui->lineEdit_capacity->text(),
                                        ui->lineEdit_league->text(),
                                        ui->lineEdit_grassType->text(),
                                        adjacentVertices);
            qDebug() << "**********" << newStadium->returnFormatedEdges();

            //Adds stadium to the database
            addStadium(*newStadium);
            //inserts new stadium into the map
            stadiumHash.insert(ui->lineEdit_stadiumName->text(),  *newStadium);

            //adds new stadium and edge to the graph
            graph.insert(*newStadium, *(stadiumHash.find(newEdge.otherVertex)), newEdge.edge);

            qDebug() << "After add stadium" << endl;
            QMessageBox::information(this, "Success", "Addition succesful. To add more edges, visit modify stadium");

            ui->page_addStadium->hide();
            ui->page_adminMainMenu->show();

            ui->lineEdit_stadiumName->clear();
            ui->lineEdit_teamName->clear();
            ui->lineEdit_cityName->clear();
            ui->lineEdit_stateName->clear();
            ui->lineEdit_zipCode->clear();
            ui->lineEdit_boxOfficeNum->clear();
            ui->lineEdit_dateOpened->clear();
            ui->lineEdit_capacity->clear();
            ui->lineEdit_league->clear();
            ui->lineEdit_grassType->clear();
            ui->lineEdit_streetName->clear();

        //Must create a stadium here. pass the stadium object into a method that sends the data to the database
        }
        else
        {

                QMessageBox::information(this, "Error", "Please enter a weight");
        }

    }
}
