#include"mainwindow.h"
#include"ui_mainwindow.h"


void MainWindow::initCustomTripTable(QSqlTableModel *souvenirModel, bool editField)
{
    souvenirModel->setTable("souvenirs");
    // Defaulted to be false!!
    if(editField)
    {
        souvenirModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    }
    else
    {
        souvenirModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    }
    souvenirModel->select();
    souvenirModel->setHeaderData(1, Qt::Horizontal, QObject::tr("stadium_id"));
    souvenirModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Qty"));
    souvenirModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Team"));
    souvenirModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Item"));
    souvenirModel->setHeaderData(5, Qt::Horizontal, QObject::tr("Price"));
}

void MainWindow::on_label_customTripStadiumName_windowIconTextChanged(const QString &iconText)
{
    QSqlTableModel *model = new QSqlTableModel(0,db);
    QSqlQuery query;
    int id;
//    qDebug() << iconText << " " << endl;
    qDebug() << query.exec("Select stadium_id from stadiums where stadiumName = " + iconText);
    id = query.value(0).toInt();
    qDebug() << "THE STADIUM_ID is " << id;
    initCustomTripTable(model, true);

    //Obtains only the rows of souvenirs belonging to a stadium
    query.exec("Insert into shoppingCart "
               "Select * from souvenirs where stadium_id = " + QString::number(id));
ui->listView_customSouvenirView->hide();
model->select();
    ui->listView_customSouvenirView->setModel(model);
    model->select();
    ui->listView_customSouvenirView->show();
//    ui->listView_customSouvenirView->hideColumn(0);
    //ui->tableView_customSouvenirView->hideColumn(2);

    refresh();
}
