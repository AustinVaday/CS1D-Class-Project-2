#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QErrorMessage>
#include <QModelIndex>
#include <QMessageBox>
#include <QModelIndexList>
#include <fstream>
#include <QTableView>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow),
    graph(200, UNDIRECTED_GRAPH) // 200 vertices, undirected
{
    vector<Vertex<stadium> *> shortestPath;
    float totalCost = 0;
	ui->setupUi(this);

	createConnection();

    fillGraph();

    // Testing ...
    qDebug() << "TESTING DIJKSTRA's: ";
    stadium sourceStadium;
    sourceStadium.setStadiumName("SEE STADIUM NUM INSTEAD!");
    sourceStadium.setStadiumNumber(5);

    stadium endStadium;
    endStadium.setStadiumName("SEE STADIUM NUM INSTEAD!");
    endStadium.setStadiumNumber(2);

    graph.DijkstraShortestPath(sourceStadium, endStadium, shortestPath, totalCost);

    qDebug() << "Displaying shortest path from shortestPath list!";

    for (int i = 0; i < shortestPath.size(); i++)
    {
        // *(shortestPath[i]) returns a stadium POINTER
        qDebug() << *(*(shortestPath[i]));
        qDebug() << " --> ";
    }

    qDebug() << "And the total cost is: " << totalCost;



	QSqlTableModel *model = new QSqlTableModel();
	initializeModel(model);
	QTableView *table = createView(model, QObject::tr("Stadium Info"));

	table->show();
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

void MainWindow::on_button_continueAddStadium_clicked()
{
	QString stadium;
	QString team;
	QString city;
	QString state;
	QString grassType;

	if(ui->lineEdit_cityName->text().isEmpty())
	{

	}

}

void MainWindow::on_button_backAddStadium_clicked()
{
	ui->page_addStadium->hide();
	ui->page_adminMainMenu->show();
}

void MainWindow::on_button_addStadium0_clicked()
{
	ui->page_adminMainMenu->hide();
	ui->page_addStadium->show();
}


bool MainWindow::createConnection()
{
QDir dir = QDir::current();


//add the new database
//now your database will be stored in fileName
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setHostName("localhost");
	db.setDatabaseName("../../../../../baseball_stadiums");
	if (!db.open())
	{
		QMessageBox::critical(0, qApp->tr("Cannot open database"),
							  qApp->tr("Unable to establish a database connection.\n"
									   "Click Cancel to exit."), QMessageBox::Cancel);
		qDebug() << "IT DOESN'T DOESN'T WORK!" << endl;
		return false;
	}

	QSqlQuery query = QSqlQuery(db);
	qDebug()<<   query.exec("create table stadiums (stadiumName varchar(50),"
							"teamName varchar(50),street varchar(50), city varchar(50),"
							"state varchar(50), zip varchar(50), boxOfficeNum varchar(50),"
							"dateOpened varchar(50), capacity varchar(50), league varchar(50),"
							"surface  varchar(50))");

	query.exec("insert into stadiums values('Angels Stadium of Anaheim', "
			   "'Los Angeles Angels of Anaheim', '2000 E Gene Autry Way', "
			   "'Anaheim', 'CA', '92806', '714-940-2000', '1966-04-19', '45,483', "
			   "'American', 'Grass')");

	query.exec("insert into stadiums values('Comerica Park', 'Detroit Tigers', "
			   "'2100 Woodward Ave', 'Detroit', 'MI', '48201', '313-962-4000', "
			   "'2000-04-11', '41,681', 'American', 'Grass')");

	query.exec("insert into stadiums values('Fenway Park', 'Boston Red Sox', "
			   "'4 Yawkey Way', 'Boston', 'MA', "
			   "'02215', '877-733-7699', '1912-04-20', '37,499 (night)"
			   " & 37,071 (day)', 'American', 'Grass')");

	query.exec("insert into stadiums values (Globe Life Park in Arlington', '"
			   "Texas Rangers', '1000 Ballpark Way', 'Arlington', 'TX', '76011', "
			   "'817-273-5222', '1994-04-1', '48,114', 'American', 'Grass')");

	query.exec("insert into stadiums values('Kauffman Stadium', "
			   "'Kansas City Royals', '1 Royal Way', "
			   "'Kansas City', 'MO', '64129', "
			   "'816-921-8000', '1973-04-10', '37,903', 'American', 'Grass')");

	query.exec("insert into stadiums values('Minute Maid Park', "
			   "'Houston Astros', '501 Crawford St', 'Houston', 'TX', '77002', "
			   "'713-259-8000', '2000-03-30', '42,060', 'American', 'Grass')");

	query.exec("insert into stadiums values('O.co Coliseum', '"
			   "Oakland Athletics', '7000 Coliseum Way', 'Oakland', 'CA', "
			   "'94621', '510-569-2121', '1966-09-18', '37,090 "
			   "(April - August) & 55,945 (Sept - Jan)', 'American', 'Grass')");

	query.exec("insert into stadiums values('Oriole Park at Camden Yards', "
			   "'Baltimore Orioles', '333 West Camden Street', 'Baltimore', "
			   "'MD', '21201', '410-685-9800', '1992-04-6', '48,187', "
			   "'American', 'Grass')");

	qDebug() << query.exec("insert into stadiums values('Progressive Field', "
			   "'Cleveland Indians', '2401 Ontario Street', 'Cleveland', 'OH', "
			   "'44115', '216-420-4487', '1994-04-2', '42,404', 'American', "
			   "'Grass')");

	query.exec("insert into stadiums values('Rogers Centre', "
			   "'Toronto Blue Jays', '1 Blue Jays Way', 'Toronto', "
			   "'Ontario,Canada', 'M5V1J3', '416-341-1000', '1989-06-3', "
			   "'49,282', 'American', 'Turf')");

	query.exec("insert into stadiums values('SafeCo Field', "
			   "'Seattle Mariners', '1516 First Avenue South', 'Seattle', 'WA',"
			   " '98134', '206-346-4000', '1999-07-15', '47,476', 'American', "
			   "'Grass')");

	query.exec("insert into stadiums values('Target Field', 'Minnesota Twins',"
			   " '353 N 5th St', 'Minneapolis', 'MN', '55403', '800-338-9467',"
			   " '2010-04-12', '39,021', 'American', 'Grass')");

	query.exec("insert into stadiums values('Tropicana Field', "
			   "'Tampa Bay Rays', '1 Tropicana Dr', 'St. Petersburg', 'FL', "
			   "'33705', '727-825-3137', '1990-03-3', '31,042 (Regular Season)"
			   " 42,735 (Postseason)', 'American', 'Turf')");

	query.exec("insert into stadiums values('US Cellular Field', "
			   "'Chicago White Sox', '333 West 35th Street', 'Chicago', 'IL', "
			   "'60616', '312-674-1000', '1991-04-18', '40,615', 'American', "
			   "'Grass')");

	query.exec("insert into stadiums values('Yankee Stadium', "
			   "'New York Yankees', '1 E 161st St', 'South Bronx', 'NY', "
			   "'10451', '718-293-4300', '2009-04-16', '50,291', 'American', "
			   "'Grass')");

	query.exec("insert into stadiums values('AT&T Park', "
			   "'San Francisco Giants', '24 Willie Mays Plaza', "
			   "'San Francisco', 'CA', '94107', '415-972-2000', '2000-04-11', "
			   "'41,915', 'National', 'Grass'), ('Busch Stadium', "
			   "'St. Louis Cardinals', '700 Clark Street', 'St. Louis', 'MO', "
			   "'63102', '314-345-9600', '2006-04-10', '46,861', 'National', "
			   "'Grass')");

	query.exec("insert into stadiums values('Chase Field', "
			   "'Arizona Diamondbacks', '401 East Jefferson Street', "
			   "'Phoenix', 'AZ', '85004', '602-462-6500', '1998-03-31', "
			   "'48,633', 'National', 'Grass')");

	query.exec("insert into stadiums values(('Citi Field', 'New York Mets', "
			   "'126th St. & Roosevelt Ave.','Queens', 'NY', '11368', "
			   "'718-507-6387', '2009-04-13', '41,922', 'National', 'Grass')");

	query.exec("insert into stadiums values('Citizens Bank Park', "
			   "'Philadelphia Phillies', '1 Citizens Bank Way','Philadelphia', "
			   "'PA', '19148', '215-463-1000', '2004-04-3', '43,651', "
			   "'National', 'Grass'), ('Coors Field', 'Colorado Rockies', "
			   "'2001 Blake St', 'Denver', 'CO', '80205', '303-292-0200', "
			   "'1995-04-26', '50,480', 'National', 'Grass')");

	query.exec("insert into stadiums values('Dodger Stadium', "
			   "'Los Angeles Dodgers', '1000 Elysian Park Avenue', "
			   "'Los Angeles', 'CA', '90090', '323-224-1507', '1962-04-10', "
			   "'56,000', 'National', 'Grass')");

	query.exec("insert into stadiums values('Great American Ball Park', "
			   "'Cincinnati Reds', '100 Joe Nuxhall Way', 'Cincinnati', 'OH',"
			   "'45202', '513-381-7337', '2003-03-31', '42,319', 'National',"
			   "'Grass')");

	query.exec("insert into stadiums values('Marlins Park', 'Miami Marlins', "
			   "'501 Marlins Way', 'Miami', 'FL', '33125', '305-480-1300', "
			   "'2012-04-4', '37,442', 'National', 'Grass')");

	query.exec("insert into stadiums values('Miller Park', 'Milwaukee Brewers',"
			   "'1 Brewers Way', 'Milwaukee', 'WI', '53214', '414-902-4400', "
			   "'2001-04-6', '41,900', 'National', 'Grass')");

	query.exec("insert into stadiums values('Nationals Park', 'Washington Nationals', "
			   "'1500 S Capitol St SE', 'Washington', 'DC', '20003', "
			   "'202-675-6287', '2008-03-30', '41,418', 'National', 'Grass')");

	query.exec("insert into stadiums values('Petco Park', 'San Diego Padres', '19 Tony Gwynn Drive', "
			   "'San Diego', 'CA', '92101', '619-795-5000', '2004-04-8', "
			   "'42,524', 'National', 'Grass')");

	query.exec("insert into stadiums values('PNC Park', 'Pittsburgh Pirates', '115 Federal St', "
			   "'Pittsburgh', 'PA', '15212', '412-321-2827', '2001-03-31', "
			   "'38,362', 'National', 'Grass')");

	query.exec("insert into stadiums values('Turner Field', 'Atlanta Braves', "
			   "'755 Hank Aaron Drive', 'Atlanta', 'GA', '30315', "
			   "'404-522-7630', '1997-03-29', '49,586', 'National', 'Grass')");

	query.exec("insert into stadiums values('Wrigley Field', 'Chicago Cubs', "
			   "'1060 West Addison Street', 'Chicago', 'IL', '60613', "
			   "'773-404-2827', '1914-04-23', '42,374', 'National', 'Grass')");
	query.next();
qDebug() << "Commit: " << db.commit();


	return true;
}

void MainWindow::fillGraph()
{
    qDebug() << "filling out the graph...";

    // create all stadium objects

    /****************************************
     *  Temp -- dummy data
     * *************************************/
    stadium stadiumDummyArray[10];

    //fill out stadium name and
    for (int i = 0; i < 10; i++)
    {

        stadiumDummyArray[i].setStadiumName("SEE STADIUM NUM INSTEAD!");
        stadiumDummyArray[i].setStadiumNumber(i);

    }


    // add all stadium objects to graph

    for (int i = 1; i < 10; i++)
    {
        // connect vertices with random weights...
        // the weight is completely randomized, do no fear my friends!
        graph.insert(stadiumDummyArray[i-1],stadiumDummyArray[i], (i*203 + 7000) % 71);
    }

}
