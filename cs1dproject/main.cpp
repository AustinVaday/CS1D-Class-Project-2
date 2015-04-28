#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow w;
	googleComputeInterface computeServer;

    w.show();

    return a.exec();
}
