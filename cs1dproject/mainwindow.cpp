#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>
#include <QModelIndex>
#include <QMessageBox>
#include <QModelIndexList>
#include <fstream>
#include <QTableView>


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);


	//Initializations of fonts for line edits, etc...
	QFont titleFont;
	titleFont.setPointSize(15);
	titleFont.setBold(true);
	titleFont.setItalic(true);

	ui->label_titleMainMenu->setFont(titleFont);
	ui->label_adminLoginTitle->setFont(titleFont);
	ui->label_planATripTitle->setFont(titleFont);
	ui->label_teamSearchTitle->setFont(titleFont);
	ui->label_stadiumListTitle->setFont(titleFont);
	ui->label_shopTitle->setFont(titleFont);
	// setup ui

	ui->stackedWidget_mainWidget->currentWidget()->hide();
	ui->page_mainMenu->show();
	ui->stackedWidget_mainWidget->show();


}

MainWindow::~MainWindow()
{


	delete ui;

}

QString MainWindow::getQStringData(QModelIndex* index, QString dataField)
{

}

int MainWindow::getIntData(QModelIndex* index, QString dataField)
{

}

float MainWindow::getFloatData(QModelIndex* index, QString dataField)
{

}

char MainWindow::getCharData(QModelIndex* index, QString dataField)
{

}


void MainWindow::on_button_back0_clicked()
{

	ui->page_planATrip0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_planATrip0_clicked()
{
	ui->page_mainMenu->hide();
	ui->page_planATrip0->show();
}

void MainWindow::on_button_searchForStadiums0_clicked()
{
	ui->page_mainMenu->hide();
	ui->page_searchForStadium0->show();
}

void MainWindow::on_button_mainMenu0_clicked()
{
	ui->page_planATrip0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back1_clicked()
{
	ui->page_planATrip1->hide();
	ui->page_planATrip0->show();
}

void MainWindow::on_button_mainMenu1_clicked()
{
	ui->page_planATrip1->hide();
	ui->page_planATrip0->show();}

void MainWindow::on_button_mainMenu2_clicked()
{
	ui->page_searchForStadium0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back2_clicked()
{
	ui->page_searchForStadium0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_mainMenu3_clicked()
{
	ui->page_shop0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back3_clicked()
{
	ui->page_shop0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_mainMenu4_clicked()
{
	ui->page_stadiumList->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_back4_clicked()
{

	ui->page_stadiumList->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_viewStadiums_clicked()
{
	ui->page_mainMenu->hide();
	ui->page_stadiumList->show();
}

void MainWindow::on_button_shop0_clicked()
{
	ui->page_mainMenu->hide();
	ui->page_shop0->show();
}

void MainWindow::on_button_adminAccess0_clicked()
{
	ui->page_mainMenu->hide();
	ui->page_adminLogin0->show();
}

void MainWindow::on_button_mainMenu5_clicked()
{
	ui->page_adminLogin0->hide();
	ui->page_mainMenu->show();
}

void MainWindow::on_button_login_clicked()
{
    //Login button pushed
    QString username      = "admin";
    QString password      = "password";
    QString inputName     = ui->lineEdit_username->text();
    QString inputPassword = ui->lineEdit_password->text();
    if(inputName != username || inputPassword != password)
    {
        QMessageBox::information(this, "Login Error", "incorrect Username or Password");
        ui->lineEdit_password->clear();
        ui->lineEdit_username->clear();
    }
    else
    {
           ui->page_adminLogin0->hide();
           ui->page_adminMainMenu->show();
    }

}

void MainWindow::on_button_back_adminMainMenu_clicked()
{
    ui->page_adminMainMenu->hide();
    ui->page_adminLogin0->show();
}
