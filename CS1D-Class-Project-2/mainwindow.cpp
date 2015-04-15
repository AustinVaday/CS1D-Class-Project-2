#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    // setup ui
    ui->setupUi(this);

    // setup database


	if (createDatabaseConnection())
	{
		qDebug() << "Database creation success.";
	}
	else
	{
		qDebug() << "Database creation failure.";
	}
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::createDatabaseConnection()
{
	// Add database type
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	// set attributes
	db.setHostName("107.178.222.186/");
	db.setDatabaseName("baseball_stadiums");
	db.setUserName("root");
	db.setPassword("CS1D");


	if (!db.open())
		return false;
	else
		return true;
}
