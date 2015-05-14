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
	refresh();
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
