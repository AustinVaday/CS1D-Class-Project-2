#ifndef CONNECTDATABASE
#define CONNECTDATABASE

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>


//static void executeQueriesFromFile(QFile *file, QSqlQuery *query)
//{
//	while (!file->atEnd()){
//		QByteArray readLine="";
//		QString cleanedLine;
//		QString line="";
//		bool finished=false;
//		while(!finished){
//			readLine = file->readLine();
//			cleanedLine=readLine.trimmed();
//			// remove comments at end of line
//			QStringList strings=cleanedLine.split("--");
//			cleanedLine=strings.at(0);

//			// remove lines with only comment, and DROP lines
//			if(!cleanedLine.startsWith("--")
//			   && !cleanedLine.startsWith("DROP")
//			   && !cleanedLine.isEmpty()){
//				line+=cleanedLine;
//			}
//			if(cleanedLine.endsWith(";")){
//				break;
//			}
//			if(cleanedLine.startsWith("COMMIT")){
//				finished=true;
//			}
//		}

//		if(!line.isEmpty()){
//			query->exec(line);
//		}
//		if(!query->isActive()){
//			qDebug() << QSqlDatabase::drivers();
//			qDebug() <<  query->lastError();
//			qDebug() << "test executed query:"<< query->executedQuery();
//			qDebug() << "test last query:"<< query->lastQuery();
//		}
//	}
//}
//static bool createConnection()
//{
//	QSqlQuery query;
//	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//	db.setDatabaseName(":memory:");
//	if (!db.open())
//	{
//		QMessageBox::critical(0, qApp->tr("Cannot open database"),
//							  qApp->tr("Unable to establish a database connection.\n"
//									   "Click Cancel to exit."), QMessageBox::Cancel);
//		return false;
//	}

//	executeQueriesFromFile(" baseball_stadiums.sql",query);
//	return true;
//}



//	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","./baseball_stadiums.sqlite");
//	db.setHostName("localhost");
//	db.setUserName("root");
//	db.setPassword("CS1D");
//	db.setDatabaseName("baseball_stadiums");

//	QSqlTableModel tableMdl_souvenirs;
//	QSqlTableModel* tableMdl_stadiums = new QSqlTableModel;
//	QModelIndex tableIndx_stadiums;
//	QModelIndex tableIndx_souvenirs;

//	if(db.open())
//	{
//		qDebug() << "Opened";
//		qDebug() << " Database: " << db.databaseName();
//		tableMdl_souvenirs.setTable("Souvenirs");
//		tableMdl_stadiums->setTable("Stasdfsdafdsafhdjsgajlfkdsjhagfdjskadiums");

//		//		tableMdl_stadiums->setEditStrategy(QSqlTableModel::OnManualSubmit);

//		tableMdl_souvenirs.select();
//		tableMdl_stadiums->select();

//		tableMdl_stadiums->setHeaderData(0, Qt::Horizontal, tr("stadiumName"));

//		QTableView *viewTable = new QTableView;

//		viewTable->setModel(tableMdl_stadiums);
//		viewTable->show();
//	}
//	else
//	{
//		qDebug() << "Database failed to open";
//	}


#endif // CONNECTDATABASE

