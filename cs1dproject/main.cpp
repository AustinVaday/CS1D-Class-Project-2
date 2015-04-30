#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtSql>

#include "connection.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	w.show();

	return a.exec();
}
