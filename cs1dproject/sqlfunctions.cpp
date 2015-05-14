#include "mainwindow.h"


/***************************************************************************
 *  Initialize Model
 * ------------------------------------------------------------------------
 * This is method will take a QSqlTableModel pointer and set it's primary
 * table to be "stadiums", our default server at the moment.
 *	It sets the column headers 1-8 for it's current order of names.
 * This make it so you can modify it, we can intialize edit strategy to not
 * allow it to be editable.
 *************************************************************************/
void MainWindow::initializeModel(QSqlTableModel *initModel, bool editField)
{
	initModel->setTable("stadiums");
	// Defaulted to be false!!
	if(editField)
	{
		initModel->setEditStrategy(QSqlTableModel::OnFieldChange);
	}
	else
	{
		initModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	}
	initModel->select();
	initModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Stadium Names"));
	initModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Team Names"));
	initModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Street"));
	initModel->setHeaderData(4, Qt::Horizontal, QObject::tr("City"));
	initModel->setHeaderData(5, Qt::Horizontal, QObject::tr("State"));
	initModel->setHeaderData(6, Qt::Horizontal, QObject::tr("Zip"));
	initModel->setHeaderData(7, Qt::Horizontal, QObject::tr("Box Office Number"));
	initModel->setHeaderData(8, Qt::Horizontal, QObject::tr("Date Opened"));
	initModel->setHeaderData(9, Qt::Horizontal, QObject::tr("Capacity"));
	initModel->setHeaderData(10, Qt::Horizontal, QObject::tr("League"));
	initModel->setHeaderData(11, Qt::Horizontal, QObject::tr("Surface"));
	initModel->setHeaderData(12, Qt::Horizontal, QObject::tr("Vertices And Edges"));
}
/***************************************************************************
 *  Initialize Souvenir
 * ------------------------------------------------------------------------
 * This is method will take a QSqlTableModel pointer and set it's primary
 * table to be "souvenirs", our default server at the moment.
 *	It sets the column headers 1-2 for it's current order of names.
 * This make it so you can modify it, we can intialize edit strategy to not
 * allow it to be editable.
 *************************************************************************/
void MainWindow::initializeSouvenir(QSqlTableModel *souvenirModel, bool editField)
{
    souvenirModel->setTable("souvenirs");
    // Defaulted to be false!!
    if(editField)
    {
        souvenirModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    }
    else
    {
        souvenirModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    }
    souvenirModel->select();
    souvenirModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Qty"));
    souvenirModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
    souvenirModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Item"));
    souvenirModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
}

void MainWindow::refresh()
{
    souvenirModel->select();
    initModel->select();
}

QTableView* MainWindow::createView(QSqlTableModel *model, const QString &title)
{
	QTableView *view = new QTableView;

	view->setModel(model);
	view->resizeColumnsToContents();
	view->resizeRowsToContents();
	view->setWindowTitle(title);

	return view;
}

// ************** EXAMPLE ***************
// v.0.1 - It only updates the values after the application has been
//		restarted. I think there is a commit or something that can be done
//		by the admin to save it live.
//		This works though!
bool MainWindow::setStadiumName()
{
	QSqlQuery query;
	return query.exec("update stadiums set stadiumName='EXAMPLE THAT IT WORKSs' where teamName='Los Angeles Angels of Anaheim'");
}// ************** EXAMPLE ***************
bool MainWindow::setStadiumName(int stadiumId,const QString &newName)
{
	QSqlQuery query;
	return query.exec("update stadiums set stadiumName='"
					  + newName + " where Primary Key='" + QString(stadiumId) + "'");
}

bool MainWindow::setTeamName(int stadiumId,const QString &newName)
{
	QSqlQuery query;
	return query.exec("update stadiums set teamName='"
					  + newName + " where Primary Key='" + QString(stadiumId) + "'");
}

bool MainWindow::setCity(int stadiumId, const QString &city)
{
	QSqlQuery query;
	return query.exec("update stadiums set city='"
					  + city + " where Primary Key='" + QString(stadiumId) + "'");
}

bool MainWindow::setState(int stadiumId, const QString &state)
{
	QSqlQuery query;
	return query.exec("update stadiums set state='"
					  + state + " where Primary Key='" + QString(stadiumId) + "'");
}

bool MainWindow::setSurface(int stadiumId, const QString &playingSurface)
{
	QSqlQuery query;
	return query.exec("update stadiums set playingSurface='"
					  + playingSurface + " where Primary Key='" + QString(stadiumId) + "'");
}


bool MainWindow::setStreet(int stadiumId, const QString &street)
{
	QSqlQuery query;
	return query.exec("update stadiums set street='"
					  + street + " where Primary Key='" + QString(stadiumId) + "'");
}


void MainWindow::showTableView()
{
	QTableView *table = createView(initModel, QObject::tr("Stadium Info"));
	table->show();
}

bool MainWindow::addStadium(stadium stadiumData)
{
	QSqlQuery query;
	QString queryString;

    queryString = "(insert into stadiums values(" +
            (query.size() + 1)+ stadiumData.getStadiumQuery();
	return query.exec(queryString);

}

void MainWindow::submit(QSqlTableModel* model)
{
	model->database().transaction();
	if (model->submitAll()) {
		model->database().commit();
	} else {
		model->database().rollback();
		QMessageBox::warning(this, tr("Cached Table"),
							 tr("The database reported an error: %1")
							 .arg(model->lastError().text()));
	}
}

bool MainWindow::createConnection(bool restart)
{

    //add the new database
    //now your database will be stored in fileName
    db = QSqlDatabase::addDatabase("QSQLITE");
    bool tableMade = false;
    bool tableMade2 = false;
    db.setHostName("localhost");
    db.setDatabaseName("baseball_stadiums");

    if (!db.open())
    {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                              qApp->tr("Unable to establish a database connection.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
        qDebug() << "IT DOESN'T DOESN'T WORK!" << endl;
        return false;
    }

    QSqlQuery query = QSqlQuery(db);

    if(restart)
    {
        query.clear();
        query.exec("drop table stadiums");
        query.clear();
        query.exec("drop table souvenirs");
        query.clear();

        qDebug() << "restart: " << restart;
    }

    /**************************************************************************
     * Creates stadium table
     *************************************************************************/
    tableMade = query.exec("create table stadiums"
                           "(stadium_id int primary key,stadiumName "
                           "varchar(50), "
                           "teamName varchar(50),"
                           "street varchar(50), "
                           "city varchar(50),"
                           "state varchar(50), "
                           "zip varchar(50), "
                           "boxOfficeNum varchar(50),"
                           "dateOpened varchar(50), "
                           "capacity varchar(50), "
                           "league varchar(50),"
                           "surface varchar(50),"
                           "verticesAndEdges varchar(100))");

    qDebug() << "TableMade: " << tableMade;
    /**************************************************************************
     * Creates souvenir table
     *************************************************************************/
    tableMade2 = query.exec("create table souvenirs"
                            "(souvenirs_id int primary key,"
                            "quantity int, "
                            "teamName varchar(50), "
                            "itemName varchar(50), "
                            "price decimal(6,2))");

    // Shopping cart table!!!!
            query.clear();
    query.exec("drop table shoppingCart");
            query.clear();
    query.exec("create table shoppingCart(quantity int, teamName varchar(50), itemName varchar(50), price decimal(6,2))");


    qDebug() << "TableMade2: " << tableMade2;

    if(tableMade || restart)
    {

        qDebug() << query.exec("insert into stadiums values(1, "
                               "'Angels Stadium of Anaheim', "
                               "'Los Angeles Angels of Anaheim',"
                               "'2000 E Gene Autry Way','Anaheim', "
                               "'CA', '92806', '714-940-2000', "
                               "'1966-04-19', '45,483',"
                               "'American', 'Grass', "
                               "'Petco Park;110~Dodger Stadium;0')");
        qDebug() << query.exec("insert into stadiums values"
                               "(2, 'Comerica Park', 'Detroit Tigers', "
                               "'2100 Woodward Ave', 'Detroit', 'MI', "
                               "'48201', '313-962-4000', '2000-04-11', "
                               "'41,681', 'American', 'Grass', "
                               "'Rogers Centre;210~Progressive "
                               "Field;90~US Cellular Field;240')");
        qDebug() << query.exec("insert into stadiums values"
                               "(3, 'Fenway Park', 'Boston Red Sox', "
                               "'4 Yawkey Way', 'Boston', 'MA', '02215', "
                               "'877-733-7699', '1912-04-20', '37,499 (night) "
                               "& 37,071 (day)', 'American', 'Grass', "
                               "'Rogers Centre;430~Marlins "
                               "Park;1255~Yankee Stadium;195')");
        qDebug() << query.exec("insert into stadiums values"
                               "(4, 'Globe Life Park in Arlington', "
                               "'Texas Rangers', '1000 Ballpark Way', "
                               "'Arlington', 'TX', '76011', '817-273-5222', "
                               "'1994-04-1', '48,114', 'American', 'Grass', "
                               "'Chase Field;870~Coors Field;650~Kauffman "
                               "Stadium;460~Turner Field;740~Minute "
                               "Maid Park;230')");
        qDebug() << query.exec("insert into stadiums values"
                               "(5, 'Kauffman Stadium', 'Kansas City Royals', "
                               "'1 Royal Way', 'Kansas City', 'MO', '64129', "
                               "'816-921-8000', '1973-04-10', '37,903', "
                               "'American', 'Grass', 'Wrigley Field;415~Busch "
                               "Stadium;235~Globe Life Park in Arlington;"
                               "460~Coors Field;560')");
        qDebug() << query.exec("insert into stadiums values"
                               "(6, 'Minute Maid Park', 'Houston Astros', "
                               "'501 Crawford St', 'Houston', 'TX', '77002', "
                               "'713-259-8000', '2000-03-30', '42,060', "
                               "'American', 'Grass', "
                               "'Busch Stadium;680~Tropicana Field;790~Marlins "
                               "Park;965~Chase Field;1115~Globe Life Park in "
                               "Arlington;230')");
        qDebug() << query.exec("insert into stadiums values"
                               "(7, 'O.co Coliseum', 'Oakland Athletics', "
                               "'7000 Coliseum Way', 'Oakland', 'CA', '94621', "
                               "'510-569-2121', '1966-09-18', '37,090 (April - "
                               "August) & 55,945 (Sept - Jan)', 'American', "
                               "'Grass', 'AT&T Park;0~Chase Field;650~Dodger "
                               "Stadium;340')");
        qDebug() << query.exec("insert into stadiums values(8, 'Oriole Park at"
                               " Camden Yards', 'Baltimore Orioles', '333 West"
                               " Camden Street', 'Baltimore', 'MD', '21201', "
                               "'410-685-9800', '1992-04-6', '48,187', "
                               "'American', 'Grass', 'Nationals Park;"
                               "0~Citizens Bank Park;90')");
        qDebug() << query.exec("insert into stadiums values"
                               "(9, 'Progressive Field', 'Cleveland Indians', "
                               "'2401 Ontario Street', 'Cleveland', 'OH', "
                               "'44115', '216-420-4487', '1994-04-2', "
                               "'42,404', 'American', 'Grass', 'Comerica "
                               "Park;90~PNC Park;115~Great American Ball Park;"
                               "225')");
        qDebug() << query.exec("insert into stadiums values"
                               "(10, 'Rogers Centre', 'Toronto Blue Jays', "
                               "'1 Blue Jays Way', 'Toronto', 'Ontario,Canada',"
                               " 'M5V1J3', '416-341-1000', '1989-06-3', "
                               "'49,282', 'American', 'Turf', 'Fenway Park;"
                               "430~PNC Park;225~Comerica Park;210~Miller Park;"
                               "430~SafeCo Field;2070')");
        qDebug() << query.exec("insert into stadiums values"
                               "(11, 'SafeCo Field', 'Seattle Mariners', '1516 "
                               "First Avenue South', 'Seattle', 'WA', '98134', "
                               "'206-346-4000', '1999-07-15', '47,476', "
                               "'American', 'Grass', 'Rogers Centre;2070~Target"
                               " Field;1390~AT&T Park;680')");
        qDebug() << query.exec("insert into stadiums values"
                               "(12, 'Target Field', 'Minnesota Twins', '353 N "
                               "5th St', 'Minneapolis', 'MN', '55403', "
                               "'800-338-9467', '2010-04-12', '39,021', "
                               "'American', 'Grass', 'SafeCo Field;1390~Miller"
                               " Park;300~Busch Stadium;465~Dodger "
                               "Stadium;1500')");
        qDebug() << query.exec("insert into stadiums values"
                               "(13, 'Tropicana Field', 'Tampa Bay Rays', "
                               "'1 Tropicana Dr', 'St. Petersburg', 'FL', "
                               "'33705', '727-825-3137', '1990-03-3', "
                               "'31,042 (Regular Season) 42,735 (Postseason)',"
                               " 'American', 'Turf', 'Marlins Park;210~Minute"
                               " Maid Park;790~Great American Ball Park;790')");
        qDebug() << query.exec("insert into stadiums values"
                               "(14, 'US Cellular Field', 'Chicago White Sox',"
                               " '333 West 35th Street', 'Chicago', 'IL', "
                               "'60616', '312-674-1000', '1991-04-18', "
                               "'40,615', 'American', 'Grass', 'Wrigley "
                               "Field;0~Comerica Park;240~Great American"
                               " Ball Park;250')");
        qDebug() << query.exec("insert into stadiums values"
                               "(15, 'Yankee Stadium', 'New York Yankees', "
                               "'1 E 161st St', 'South Bronx', 'NY', '10451', "
                               "'718-293-4300', '2009-04-16', '50,291', "
                               "'American', 'Grass', 'Citi Field;0~Citizens "
                               "Bank Park;80~PNC Park;315~Fenway Park;195')");
        qDebug() << query.exec("insert into stadiums values"
                               "(16, 'AT&T Park', 'San Francisco Giants', "
                               "'24 Willie Mays Plaza', 'San Francisco', "
                               "'CA', '94107', '415-972-2000', '2000-04-11', "
                               "'41,915', 'National', 'Grass', 'O.co "
                               "Coliseum;0~SafeCo Field;680')");
        qDebug() << query.exec("insert into stadiums values"
                               "(17, 'Busch Stadium', 'St. Louis Cardinals', "
                               "'700 Clark Street', 'St. Louis', 'MO', "
                               "'63102', '314-345-9600', '2006-04-10', "
                               "'46,861', 'National', 'Grass', 'Great American"
                               " Ball Park;310~Minute Maid Park;680~Kauffman "
                               "Stadium;235~Target Field;465')");
        qDebug() << query.exec("insert into stadiums values"
                               "(18, 'Chase Field', 'Arizona Diamondbacks', "
                               "'401 East Jefferson Street', 'Phoenix', 'AZ', "
                               "'85004', '602-462-6500', '1998-03-31', "
                               "'48,633', 'National', 'Grass', "
                               "'Coors Field;580~Globe Life Park in "
                               "Arlington;870~Minute Maid Park;1115~Petco "
                               "Park;300~O.co Coliseum;650')");
        qDebug() << query.exec("insert into stadiums values"
                               "(19, 'Citi Field', 'New York Mets', '126th "
                               "St. & Roosevelt Ave.', 'Queens', 'NY', "
                               "'11368', '718-507-6387', '2009-04-13', "
                               "'41,922', 'National', 'Grass', "
                               "'Yankee Stadium;0')");
        qDebug() << query.exec("insert into stadiums values"
                               "(20, 'Citizens Bank Park', "
                               "'Philadelphia Phillies', "
                               "'1 Citizens Bank Way', 'Philadelphia', 'PA', "
                               "'19148', '215-463-1000', '2004-04-3', "
                               "'43,651', 'National', 'Grass', 'Yankee "
                               "Stadium;80~Oriole Park at Camden Yards;90')");
        qDebug() << query.exec("insert into stadiums values"
                               "(21, 'Coors Field', 'Colorado Rockies', "
                               "'2001 Blake St', 'Denver', 'CO', '80205', "
                               "'303-292-0200', '1995-04-26', '50,480', "
                               "'National', 'Grass', 'Kauffman Stadium;"
                               "560~Globe Life Park in Arlington;650~Chase "
                               "Field;580~Petco Park;830')");
        qDebug() << query.exec("insert into stadiums values"
                               "(22, 'Dodger Stadium', 'Los Angeles Dodgers', "
                               "'1000 Elysian Park Avenue', 'Los Angeles', "
                               "'CA', '90090', '323-224-1507', '1962-04-10', "
                               "'56,000', 'National', 'Grass', 'Angels Stadium "
                               "of Anaheim;0~Target Field;1500~O.co "
                               "Coliseum;340')");
        qDebug() << query.exec("insert into stadiums values"
                               "(23, 'Great American Ball Park', "
                               "'Cincinnati Reds', '100 Joe Nuxhall Way', "
                               "'Cincinnati', 'OH', '45202', '513-381-7337', "
                               "'2003-03-31', '42,319', 'National', 'Grass', "
                               "'Progressive Field;225~PNC Park;260~Tropicana "
                               "Field;790~Turner Field;375~Busch "
                               "Stadium;310~US Cellular Field;250')");
        qDebug() << query.exec("insert into stadiums values"
                               "(24, 'Marlins Park', 'Miami Marlins', "
                               "'501 Marlins Way', 'Miami', 'FL', '33125', "
                               "'305-480-1300', '2012-04-4', '37,442', "
                               "'National', 'Grass', 'Nationals "
                               "Park;930~Fenway Park;1255~Minute Maid "
                               "Park;965~Tropicana Field;210~Turner "
                               "Field;600')");
        qDebug() << query.exec("insert into stadiums values"
                               "(25, 'Miller Park', 'Milwaukee Brewers', "
                               "'1 Brewers Way', 'Milwaukee', 'WI', '53214', "
                               "'414-902-4400', '2001-04-6', '41,900', "
                               "'National', 'Grass', 'Rogers "
                               "Centre;430~Wrigley Field;80~Target "
                               "Field;300')");
        qDebug() << query.exec("insert into stadiums values"
                               "(26, 'Nationals Park', 'Washington Nationals', "
                               "'1500 S Capitol St SE', 'Washington', 'DC', "
                               "'20003', '202-675-6287', '2008-03-30', "
                               "'41,418', 'National', 'Grass', 'Oriole Park at "
                               "Camden Yards;0~Marlins Park;930~Turner "
                               "Field;560~PNC Park;195')");
        qDebug() << query.exec("insert into stadiums values"
                               "(27, 'Petco Park', 'San Diego Padres', "
                               "'19 Tony Gwynn Drive', 'San Diego', 'CA', "
                               "'92101', '619-795-5000', '2004-04-8', '42,524',"
                               " 'National', 'Grass', 'Angels Stadium of "
                               "Anaheim;110~Coors Field;830~Chase Field;300')");
        qDebug() << query.exec("insert into stadiums values"
                               "(28, 'PNC Park', 'Pittsburgh Pirates', "
                               "'115 Federal St', 'Pittsburgh', 'PA', '15212', "
                               "'412-321-2827', '2001-03-31', '38,362', "
                               "'National', 'Grass', 'Rogers Centre;225~Yankee "
                               "Stadium;315~Nationals Park;195~Great American "
                               "Ball Park;260~Progressive Field;115')");
        qDebug() << query.exec("insert into stadiums values"
                               "(29, 'Turner Field', 'Atlanta Braves', "
                               "'755 Hank Aaron Drive', 'Atlanta', 'GA', "
                               "'30315', '404-522-7630', '1997-03-29', "
                               "'49,586', 'National', 'Grass', 'Great American "
                               "Ball Park;375~Nationals Park;560~Marlins Park;"
                               "600~Globe Life Park in Arlington;740')");
        qDebug() << query.exec("insert into stadiums values"
                               "(30, 'Wrigley Field', 'Chicago Cubs', "
                               "'1060 West Addison Street', 'Chicago', 'IL', "
                               "'60613', '773-404-2827', '1914-04-23', "
                               "'42,374', 'National', 'Grass', 'US Cellular "
                               "Field;0~Kauffman Stadium;415~Miller Park;80')");
    }
    if(tableMade2 || restart)
        {

            qDebug() << query.exec("insert into souvenirs values(1, 0, 'generic', 'Baseball Cap', 25.99)");

            qDebug() << query.exec("insert into souvenirs values(2,  0,  'generic', 'Baseball Cap', 25.99)");


            qDebug() << query.exec("insert into souvenirs values(3,  0,  'generic', 'Team Pennant', 12.99) ");

            qDebug() << query.exec("insert into souvenirs values(4,  0,  'generic', 'Autographed baseball',19.99)");
        }

    return tableMade;
}
