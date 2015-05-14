#include "ui_mainwindow.h"
#include "mainwindow.h"

void MainWindow::on_button_search0_clicked()
{
QSqlTableModel* searchModel = new QSqlTableModel(0,db);
ui->tableView_stadiumList->hide();

searchModel->setTable(ui->lineEdit_searchLine0->text());

ui->tableView_stadiumList->setModel(searchModel);
	ui->tableView_stadiumList->show();
}

void MainWindow::on_lineEdit_searchLine0_textEdited(const QString &arg1)
{

	initModel->setFilter(ui->lineEdit_searchLine0->text());
	ui->tableView_stadiumList->hide();
	ui->tableView_stadiumList->show();
}

