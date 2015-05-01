#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DEBUG 1

#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QFile>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void executeQueriesFromFile(QFile *file, QSqlQuery* query);
		// Does not work at the moment, considering removing from project.
		//	only keeping if I get the chance to implement

		QString getQStringData(QModelIndex *index, QString dataField);
		// Will return a QString of the data from the QModelIndex

		int getIntData(QModelIndex *index, QString dataField);
		// Returns integer data at the model index
		float getFloatData(QModelIndex *index, QString dataField);
		// Returns float data at the model index
		char getCharData(QModelIndex *index, QString dataField);
		// Returns chara data at the model index

	private slots:
		void on_button_back0_clicked();

		void on_button_planATrip0_clicked();

		void on_button_searchForStadiums0_clicked();

		void on_button_mainMenu0_clicked();

		void on_button_back1_clicked();

		void on_button_mainMenu1_clicked();

		void on_button_mainMenu2_clicked();

		void on_button_back2_clicked();

		void on_button_mainMenu3_clicked();

		void on_button_back3_clicked();

		void on_button_mainMenu4_clicked();

		void on_button_back4_clicked();

		void on_button_viewStadiums_clicked();

		void on_button_shop0_clicked();

		void on_button_adminAccess0_clicked();

		void on_button_mainMenu5_clicked();

	private:
		Ui::MainWindow *ui;
		QSqlDatabase database;
};

#endif // MAINWINDOW_H
