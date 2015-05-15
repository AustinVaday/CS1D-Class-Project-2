#include "souvenirs.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

void createSouvenirs(QVector <souvenirs> souvenirList){
	QSqlQuery query;
	query.exec("Select * from souvenirs");

	while(query.next()){
		souvenirs object;
		object.setItem(query.value(0).toString());
		object.setPrice(query.value(1).toString());

		//        souvenirList.push_back(object);
	}
}


void MainWindow::on_button_manageSouviner_clicked()
{
	souvenirModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	souvenirModel->select();
	ui->tableView_adminSouviner->hideColumn(0);
	ui->tableView_adminSouviner->setModel(souvenirModel);
	ui->tableView_adminSouviner->setSortingEnabled(true);
	ui->page_adminMainMenu->hide();
	ui->page_addSouvenir->show();
}

void MainWindow::on_pushButton_back_manageSouvenir_clicked()
{
	ui->page_addSouvenir->hide();
	ui->page_adminMainMenu->show();
}

void MainWindow::on_pushButton_admin_submit_clicked()
{
	souvenirModel->submitAll();
	qDebug() << souvenirModel->lastError();
	souvenirModel->select();
}

void MainWindow::on_pushButton_admin_deleteSouvenir_clicked()
{
	bool ok;
	QModelIndex index;

	//	qDebug() << "Delete Souvenir: " << ui->lineEdit_deleteSouvenir->text();
	//	qDebug() << "Delete Souvenir INTEGER: " << ui->lineEdit_deleteSouvenir->text().toInt(&ok,10);
	qDebug() << "Field Index : " <<	souvenirModel->fieldIndex(ui->lineEdit_deleteSouvenir->text());
	//	souvenirModel->removeRow(souvenirModel->
	souvenirModel->submitAll();
	qDebug() << souvenirModel->lastError();
	souvenirModel->select();
}

void MainWindow::on_pushButton_admin_addSouvenir_clicked()
{
	QSqlQuery tempQuery;
	//	souvenirModel->insertRow(initModel->rowCount());
	tempQuery.exec("INSERT INTO `souvenirs` VALUES (null, null, 0, 'team name','item name', 0.0)");
	//	setKeyIndex = souvenirModel->rowCount();

	souvenirModel->select();

}
