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
    souvenirModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    souvenirModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
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

	queryString = "(insert into stadiums values(" + query.size() + stadiumData.getStadiumQuery();
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


