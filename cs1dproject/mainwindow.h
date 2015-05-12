											#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define SQL_DEBUG 1
#define DEBUG 0
// Standard Qt Includes
#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QApplication>
#include <QtGui>
#include <QMessageBox>

// Qt Sql includes, database, query and table display
#include <QTableView>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QAbstractItemView>
#include <QAbstractItemModel>

// Project includes
#include "graph.h"
#include "stadium.h"
#include "MainHeader.h"
//#include "hashTable.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		bool createConnection(bool restart = false);
		void showTableView();
		void fillGraph();

		void refresh();
		bool setState(int stadiumId, const QString &state);
		bool setTeamName(int stadiumId, const QString &teamName);
		bool setSurface(int stadiumId, const QString &playingSurface);
		bool setCity(int stadiumId, const QString &city);
		bool setStadiumName(); // <----- EXAMPLE & Demo for functionality
		bool setStadiumName(int stadiumId,const QString &teamName);

		void initializeModel(QSqlTableModel *initModel, bool editField = true);

		QTableView* createView(QSqlTableModel *initModel, const QString &title);
		// This method will take a model foo and give it a title foobar.
		//	MAKE SURE TO DEALLOCATE MEMORY for model foo



        stadium searchForStadium(string searchKey);



		bool setStreet(int stadiumId, const QString& street);
		void submit(QSqlTableModel* model);
		bool addStadium(stadium stadiumData);

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

		void on_button_login_clicked();

		void on_button_back_adminMainMenu_clicked();

		void on_button_continueAddStadium_clicked();

		void on_button_backAddStadium_clicked();

		void on_button_addStadium0_clicked();

        void on_button_quickTrip0_clicked();

        void on_button_confirm_clicked();

        void on_button_cancel_clicked();

        void on_button_finish_clicked();

        void on_button_customTrip0_clicked();

        void on_pushButton_customTripGo_clicked();

        void on_button_customTripBack_clicked();

private:
		Ui::MainWindow *ui;
		QSqlDatabase db;
		QSqlTableModel* initModel;
		QTableView* viewModel;
		/*
		 * Vertex: stadium
		 * Edge: float (could be int, but let's make it generic)
		 */
		Graph<stadium,float> graph;
        QHash<QString,stadium> stadiumHash;
        QHash<QString,stadium>::iterator stadiumIt;
};

#endif // MAINWINDOW_H
