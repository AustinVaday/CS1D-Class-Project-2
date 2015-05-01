#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include <QMessageBox>
#include "graph.h"
#include "querydatatable.h"
#include "projsqlmodel.h"
#include <QTableView>
#include <QSqlQueryModel>

void initializeModel(QSqlQueryModel *model);
QTableView* createView(QSqlQueryModel *model, const QString &title = "");
void executeQueriesFromFile(QFile *file, QSqlQuery *query);
bool createConnection();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	/////// TEMP GRAPH TESTING /////////
	Graph<QString,int> graph4(12, UNDIRECTED_GRAPH); // 12 vertices
	graph4.insert("Seattle", "San Francisco", 807);
	graph4.insert("Seattle", "Denver", 1331);
	graph4.insert("Chicago", "Seattle", 2097);
	graph4.insert("Chicago", "Boston", 983);
	graph4.insert("Denver","San Francisco", 1267);
	graph4.insert("Denver", "Chicago", 1003);
	graph4.insert("San Francisco", "Los Angeles", 381);
	graph4.insert("Los Angeles", "Denver", 1015);
	graph4.insert("Kansas City","Los Angeles", 1663);
	graph4.insert("Kansas City", "Chicago", 533);
	graph4.insert("Kansas City", "Denver", 599);
	graph4.insert("Kansas City", "New York", 1260);
	graph4.insert("Kansas City", "Atlanta", 864);
	graph4.insert("Dallas", "Los Angeles", 1435);
	graph4.insert("Dallas", "Kansas City", 496);
	graph4.insert("Dallas", "Atlanta", 781);
	graph4.insert("New York", "Chicago", 787);
	graph4.insert("New York", "Atlanta", 888);
	graph4.insert("Houston", "Dallas", 239);
	graph4.insert("Houston", "Atlanta", 810);
	graph4.insert("Miami", "Houston", 1187);
	graph4.insert("Boston", "New York", 214);
	graph4.insert("Atlanta", "Miami", 661);

	//	Display is too messy b/c no set(w) in QT
	graph4.display();

	graph4.Dijkstra("Seattle");



	return a.exec();
}


void initializeModel(QSqlQueryModel *model)
{
	model->setQuery("SELECT * FROM  Stadiums");
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("Stadium Names"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Team Names"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Street"));
}

QTableView* createView(QSqlQueryModel *model, const QString &title)
{
	QTableView *view = new QTableView;
	view->setModel(model);
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
	Q_UNUSED(title);
	view->resizeColumnsToContents();
#else
	static int offset = 0;

	view->setWindowTitle(title);
	view->move(100 + offset, 100 + offset);
	offset += 20;
	view->show();
#endif

	return view;
}

void executeQueriesFromFile(QFile *file, QSqlQuery *query)
{
	while (!file->atEnd()){
		QByteArray readLine="";
		QString cleanedLine;
		QString line="";
		bool finished=false;
		while(!finished){
			readLine = file->readLine();
			cleanedLine=readLine.trimmed();
			// remove comments at end of line
			QStringList strings=cleanedLine.split("--");
			cleanedLine=strings.at(0);

			// remove lines with only comment, and DROP lines
			if(!cleanedLine.startsWith("--")
			   && !cleanedLine.startsWith("DROP")
			   && !cleanedLine.isEmpty()){
				line+=cleanedLine;
			}
			if(cleanedLine.endsWith(";")){
				break;
			}
			if(cleanedLine.startsWith("COMMIT")){
				finished=true;
			}
		}

		if(!line.isEmpty()){
			query->exec(line);
		}
		if(!query->isActive()){
			qDebug() << QSqlDatabase::drivers();
			qDebug() <<  query->lastError();
			qDebug() << "test executed query:"<< query->executedQuery();
			qDebug() << "test last query:"<< query->lastQuery();
		}
	}
}
bool createConnection()
{


	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	QSqlTableModel model;
	QTableView tableView;
	QSqlQueryModel *queryModel = new QSqlQueryModel;

	db.setDatabaseName(":memory:");
	if (!db.open())
	{
		QMessageBox::critical(0, qApp->tr("Cannot open database"),
							  qApp->tr("Unable to establish a database connection.\n"
									   "Click Cancel to exit."), QMessageBox::Cancel);
		qDebug() << "IT DOESN'T DOESN'T WORK!" << endl;
		return 1;
	}


	QSqlQuery query;
	query.exec("create table stadiums (stadiumName varchar(50),"
			   "teamName varchar(50),street varchar(50), city varchar(50),"
			   "state varchar(50), zip varchar(50), boxOfficeNum varchar(50),"
			   "dateOpened varchar(50), capacity varchar(50), league varchar(50),"
			   "surface  varchar(50))");

	query.exec("insert into stadiums values('Angels Stadium of Anaheim', "
			   "'Los Angeles Angels of Anaheim', '2000 E Gene Autry Way', "
			   "'Anaheim', 'CA', '92806', '714-940-2000', '1966-04-19', '45,483', "
			   "'American', 'Grass')");

	query->exec("insert into stadiums values('Comerica Park', 'Detroit Tigers', "
				"'2100 Woodward Ave', 'Detroit', 'MI', '48201', '313-962-4000', "
				"'2000-04-11', '41,681', 'American', 'Grass')");

	query->exec("insert into stadiums values('Fenway Park', 'Boston Red Sox', "
				"'4 Yawkey Way', 'Boston', 'MA', "
				"'02215', '877-733-7699', '1912-04-20', '37,499 (night)"
				" & 37,071 (day)', 'American', 'Grass')");

	query->exec("insert into stadiums values (Globe Life Park in Arlington', '"
				"Texas Rangers', '1000 Ballpark Way', 'Arlington', 'TX', '76011', "
				"'817-273-5222', '1994-04-1', '48,114', 'American', 'Grass')");

	query->exec("insert into stadiums values('Kauffman Stadium', "
				"'Kansas City Royals', '1 Royal Way', "
				"'Kansas City', 'MO', '64129', "
				"'816-921-8000', '1973-04-10', '37,903', 'American', 'Grass')");

	query->exec("insert into stadiums values('Minute Maid Park', "
				"'Houston Astros', '501 Crawford St', 'Houston', 'TX', '77002', "
				"'713-259-8000', '2000-03-30', '42,060', 'American', 'Grass'");

	query->exec("insert into stadiums values('O.co Coliseum', '"
				"Oakland Athletics', '7000 Coliseum Way', 'Oakland', 'CA', "
				"'94621', '510-569-2121', '1966-09-18', '37,090 "
				"(April - August) & 55,945 (Sept - Jan)', 'American', 'Grass')");

	query->exec("insert into stadiums values('Oriole Park at Camden Yards', "
				"'Baltimore Orioles', '333 West Camden Street', 'Baltimore', "
				"'MD', '21201', '410-685-9800', '1992-04-6', '48,187', "
				"'American', 'Grass')");

	query->exec("insert into stadiums values('Progressive Field', "
				"'Cleveland Indians', '2401 Ontario Street', 'Cleveland', 'OH', "
				"'44115', '216-420-4487', '1994-04-2', '42,404', 'American', "
				"'Grass')");

	query->exec("insert into stadiums values('Rogers Centre', "
				"'Toronto Blue Jays', '1 Blue Jays Way', 'Toronto', "
				"'Ontario,Canada', 'M5V1J3', '416-341-1000', '1989-06-3', "
				"'49,282', 'American', 'Turf')");

	query->exec("insert into stadiums values('SafeCo Field', "
				"'Seattle Mariners', '1516 First Avenue South', 'Seattle', 'WA',"
				" '98134', '206-346-4000', '1999-07-15', '47,476', 'American', "
				"'Grass')");

	query->exec("insert into stadiums values('Target Field', 'Minnesota Twins',"
				" '353 N 5th St', 'Minneapolis', 'MN', '55403', '800-338-9467',"
				" '2010-04-12', '39,021', 'American', 'Grass')");

	query->exec("insert into stadiums values('Tropicana Field', "
				"'Tampa Bay Rays', '1 Tropicana Dr', 'St. Petersburg', 'FL', "
				"'33705', '727-825-3137', '1990-03-3', '31,042 (Regular Season)"
				" 42,735 (Postseason)', 'American', 'Turf')");

	query->exec("insert into stadiums values('US Cellular Field', "
				"'Chicago White Sox', '333 West 35th Street', 'Chicago', 'IL', "
				"'60616', '312-674-1000', '1991-04-18', '40,615', 'American', "
				"'Grass')");

	query->exec("insert into stadiums values('Yankee Stadium', "
				"'New York Yankees', '1 E 161st St', 'South Bronx', 'NY', "
				"'10451', '718-293-4300', '2009-04-16', '50,291', 'American', "
				"'Grass')");

	query->exec("insert into stadiums values('AT&T Park', "
				"'San Francisco Giants', '24 Willie Mays Plaza', "
				"'San Francisco', 'CA', '94107', '415-972-2000', '2000-04-11', "
				"'41,915', 'National', 'Grass'), ('Busch Stadium', "
				"'St. Louis Cardinals', '700 Clark Street', 'St. Louis', 'MO', "
				"'63102', '314-345-9600', '2006-04-10', '46,861', 'National', "
				"'Grass'");

	query->exec("insert into stadiums values('Chase Field', "
				"'Arizona Diamondbacks', '401 East Jefferson Street', "
				"'Phoenix', 'AZ', '85004', '602-462-6500', '1998-03-31', "
				"'48,633', 'National', 'Grass')");

	query->exec("insert into stadiums values(('Citi Field', 'New York Mets', "
				"'126th St. & Roosevelt Ave.','Queens', 'NY', '11368', "
				"'718-507-6387', '2009-04-13', '41,922', 'National', 'Grass')");

	query->exec("insert into stadiums values('Citizens Bank Park', "
				"'Philadelphia Phillies', '1 Citizens Bank Way','Philadelphia', "
				"'PA', '19148', '215-463-1000', '2004-04-3', '43,651', "
				"'National', 'Grass'), ('Coors Field', 'Colorado Rockies', "
				"'2001 Blake St', 'Denver', 'CO', '80205', '303-292-0200', "
				"'1995-04-26', '50,480', 'National', 'Grass')");

	query->exec("insert into stadiums values('Dodger Stadium', "
				"'Los Angeles Dodgers', '1000 Elysian Park Avenue', "
				"'Los Angeles', 'CA', '90090', '323-224-1507', '1962-04-10', "
				"'56,000', 'National', 'Grass')");

	query->exec("insert into stadiums values('Great American Ball Park', "
				"'Cincinnati Reds', '100 Joe Nuxhall Way', 'Cincinnati', 'OH',"
				"'45202', '513-381-7337', '2003-03-31', '42,319', 'National',"
				"'Grass')");

	query.exec("inest into stadiums values('Marlins Park', 'Miami Marlins', "
			   "'501 Marlins Way', 'Miami', 'FL', '33125', '305-480-1300', "
			   "'2012-04-4', '37,442', 'National', 'Grass')");
	query.exec("'Miller Park', 'Milwaukee Brewers',
			   "'1 Brewers Way', 'Milwaukee', 'WI', '53214', '414-902-4400', "
			   "'2001-04-6', '41,900', 'National', 'Grass')");
	query.exec("'Nationals Park', 'Washington Nationals', "
			   "'1500 S Capitol St SE', 'Washington', 'DC', '20003', "
			   "'202-675-6287', '2008-03-30', '41,418', 'National', 'Grass')");
	query.exec("'Petco Park', 'San Diego Padres', '19 Tony Gwynn Drive', "
			   "'San Diego', 'CA', '92101', '619-795-5000', '2004-04-8', "
			   "'42,524', 'National', 'Grass')");
	"('PNC Park', 'Pittsburgh Pirates', '115 Federal St', 'Pittsburgh', 'PA', '15212', '412-321-2827', '2001-03-31', '38,362', 'National', 'Grass'), "
	"('Turner Field', 'Atlanta Braves', '755 Hank Aaron Drive', 'Atlanta', 'GA', '30315', '404-522-7630', '1997-03-29', '49,586', 'National', 'Grass'), "
	"('Wrigley Field', 'Chicago Cubs', '1060 West Addison Street', 'Chicago', 'IL', '60613', '773-404-2827', '1914-04-23', '42,374', 'National', 'Grass'");


	model.setTable("stadium");
	model.setSort(2, Qt::DescendingOrder);
	model.select();

	initializeModel(&model);
	QTableView* view1 = createView(&model, QObject::tr("Stadiums"));

	return true;
}


