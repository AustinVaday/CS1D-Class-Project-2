#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DEBUG 0

#include <QMainWindow>
#include <QDebug>

// Database includes --------->
#include <QtSql>
// --------------------------->
namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		Ui::MainWindow *ui;

		bool createDatabaseConnection();


QSqlError addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port);
};

#endif // MAINWINDOW_H
