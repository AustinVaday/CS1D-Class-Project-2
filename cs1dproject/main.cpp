#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>
#include "MainHeader.h"

int main(int argc, char *argv[])
{
//    try
//    {
        QApplication a(argc, argv);
        MainWindow w;

        w.show();

        return a.exec();

    }
//    catch (const OutOfRange&)
//   {
//       qDebug() << "Inside Catch -- OutOfRange\n";

//   }
//   catch (const NotFound&)
//   {
//       qDebug() << "Inside Catch -- NotFound\n";

//   }
//   catch (const Full&)
//   {
//       qDebug() << "Inside Catch -- Full\n";

//   }
//   catch (const Empty&)
//   {
//       qDebug() << "Inside Catch -- Empty\n";

//   }
//   catch (const NoParent&)
//   {
//       qDebug() << "Inside Catch -- No Parent\n";

//   }
//   catch (const ExternalNode&)
//   {
//       qDebug() << "Inside Catch -- External Node\n";

//   }
//   catch (const RootAlreadyExists&)
//   {
//       qDebug() << "Inside Catch -- Root Already Exists\n";

//   }
//   catch (const TreeError&)
//   {
//       qDebug() << "Inside Catch -- Tree Error\n";
//       qDebug() << "Check your tree insertions and/or deletions\n";

//   }
//   catch (const BadHash&)
//   {
//       qDebug() << "Inside Catch -- Bad Hash\n";
//       qDebug() << "Please check your hashing class!\n";
//   }
//   catch (const IndexNotSet&)
//   {
//       qDebug() << "Inside Catch -- IndexNotSet\n";
//       qDebug() << "Please check your Vertex class!\n";
//   }
//   catch(...)
//   {
//       qDebug() << "Inside Catch All\n";
//   }


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
