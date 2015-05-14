  #include "mainwindow.h"
  #include "ui_mainwindow.h"

void MainWindow::initializeShoppingCart(QSqlTableModel *cartModel, bool editField)
{
    cartModel->setTable("shoppingCart");
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
	cartModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Team"), 0);
	cartModel->setHeaderData(3, Qt::Horizontal, QObject::tr("Item"), 0);
	cartModel->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"), 0);
}

void MainWindow::shoppingCartNext()
{

}
