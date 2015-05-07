#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include "MainHeader.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

    createConnection();
    QSqlTableModel model;
    initializeModel(&model);
    QTableView *table = createView(&model, QObject::tr("Stadium Info"));

    table->show();

    w.show();


	return a.exec();
}



//	/////// TEMP GRAPH TESTING /////////
//	Graph<QString,int> graph4(12, UNDIRECTED_GRAPH); // 12 vertices
//	graph4.insert("Seattle", "San Francisco", 807);
//	graph4.insert("Seattle", "Denver", 1331);
//	graph4.insert("Chicago", "Seattle", 2097);
//	graph4.insert("Chicago", "Boston", 983);
//	graph4.insert("Denver","San Francisco", 1267);
//	graph4.insert("Denver", "Chicago", 1003);
//	graph4.insert("San Francisco", "Los Angeles", 381);
//	graph4.insert("Los Angeles", "Denver", 1015);
//	graph4.insert("Kansas City","Los Angeles", 1663);
//	graph4.insert("Kansas City", "Chicago", 533);
//	graph4.insert("Kansas City", "Denver", 599);
//	graph4.insert("Kansas City", "New York", 1260);
//	graph4.insert("Kansas City", "Atlanta", 864);
//	graph4.insert("Dallas", "Los Angeles", 1435);
//	graph4.insert("Dallas", "Kansas City", 496);
//	graph4.insert("Dallas", "Atlanta", 781);
//	graph4.insert("New York", "Chicago", 787);
//	graph4.insert("New York", "Atlanta", 888);
//	graph4.insert("Houston", "Dallas", 239);
//	graph4.insert("Houston", "Atlanta", 810);
//	graph4.insert("Miami", "Houston", 1187);
//	graph4.insert("Boston", "New York", 214);
//	graph4.insert("Atlanta", "Miami", 661);

    //	Display is too messy b/c no set(w) in QT
//	graph4.display();

//	graph4.Dijkstra("Seattle");
