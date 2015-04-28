#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define DEBUG 0

#include <QMainWindow>
#include <QDebug>
#include <QFont>
#include <googleComputeInterface.h>

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

		bool addConnection();


//QSqlError addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &passwd, int port);
};

#endif // MAINWINDOW_H
