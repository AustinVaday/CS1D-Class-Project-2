#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DEBUG 1
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

// Project includes
#include "graph.h"
#include "querydatatable.h"
#include "stadium.h"
#include "MainHeader.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

//        QString queryData(stadium stadiumTable);

//        // SQL Methods for retrieving and configuring data in the SQL database

//        void sendData(const stadium& data);

//        void initializeModel(QSqlTableModel *model);

//        QTableView* createView(QSqlTableModel *model, const QString &title = "");

		bool createConnection();
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

    private:
        Ui::MainWindow *ui;
		QSqlDatabase db;

};

#endif // MAINWINDOW_H
