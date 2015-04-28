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
	QProcess sysCommandOutput;



}
//QSqlError MainWindow::addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port)
//{
//	static int cCount = 0;

//	QSqlError err;
//	QSqlDatabase db = QSqlDatabase::addDatabase(driver, QString("Browser%1").arg(++cCount));
//	db.setDatabaseName(dbName);
//	db.setHostName(host);
//	db.setPort(port);
//	if (!db.open(user, passwd)) {
//		err = db.lastError();
//		db = QSqlDatabase();
//		QSqlDatabase::removeDatabase(QString("Browser%1").arg(cCount));
//	}

//	return err;
//}
/*	// Add database type
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	bool open = false;
	// set attributes
	db.setHostName("107.178.222.186");
	db.setDatabaseName("baseball_stadiums");
	db.setUserName("root");

	if (db.open("root",""))
	   open = true;

	return open;*/
