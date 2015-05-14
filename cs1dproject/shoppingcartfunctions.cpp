#include "mainwindow.h"

void MainWindow::initializeShoppingCart(QSqlTableModel *cartModel, bool editField)
{
    cartModel->setTable("souvenirs");
    // Defaulted to be false!!
    if(editField)
    {
        cartModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    }
    else
    {
        cartModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    }
    cartModel->select();
    cartModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Qty"));
    cartModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Team"));
    cartModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Item"));
    cartModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
}

