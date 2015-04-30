#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{



	QErrorMessage warnWin_initFail;
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","./baseball_stadiums.sql");
	ui->setupUi(this);

	if(db.open())
	{


		QSqlQuery query(db);
		QSqlTableModel tableMdl_teamName;
		QSqlTableModel tableMdl_teamName_grassOnly;
		QSqlTableModel tableMdl_teamNameAmerican;
		QSqlTableModel tableMdl_teamNameNational;
		QSqlTableModel tableMdl_stadiumName;
		QSqlTableModel tableMdl_dateOpened;
		QSqlTableModel tableMdl_souvenirs;
		QSqlTableModel tableMdl_stadiums;


		tableMdl_teamName.setTable("ASC_Team_Name");
		tableMdl_teamName_grassOnly.setTable("ASC_Team_Name_Grass_Only");
		tableMdl_teamNameAmerican.setTable("ASC_American_TeamName");
		tableMdl_teamNameNational.setTable("ASC_National_Team_Name");
		tableMdl_stadiumName.setTable("ASC_Stadium_Name");
		tableMdl_dateOpened.setTable("ASC_Date_Opened");
		tableMdl_souvenirs.setTable("Souvenirs");
		tableMdl_stadiums.setTable("Stadiums");

		tableMdl_dateOpened.select();
		tableMdl_souvenirs.select();
		tableMdl_stadiumName.select();
		tableMdl_stadiums.select();
		tableMdl_teamName.select();
		tableMdl_teamName_grassOnly.select();
		tableMdl_teamNameAmerican.select();
		tableMdl_teamNameNational.select();

	}
	else
	{
		warnWin_initFail.showMessage("Database failed to open");
	}

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

	ui->page_mainMenu->show();
	ui->stackedWidget_mainWidget->show();


}

MainWindow::~MainWindow()
{
	delete ui;
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


