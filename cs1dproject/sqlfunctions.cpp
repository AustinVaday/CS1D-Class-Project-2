#include "MainHeader.h"

void initializeModel(QSqlTableModel *model)
{
    model->setTable("Stadium");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Stadium Names"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Team Names"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("State"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Zip"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Box Office Number"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Opened"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("League"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Surface"));
}

QTableView* createView(QSqlTableModel *model, const QString &title)
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle(title);

    return view;
}

