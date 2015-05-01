#include <QtSql>

#include "querydatatable.h"

queryDataTable::queryDataTable(QObject *parent)
	: QSqlQueryModel(parent)
{
}

//! [0]
Qt::ItemFlags queryDataTable::flags(
		const QModelIndex &index) const
{
	Qt::ItemFlags flags = QSqlQueryModel::flags(index);
	if (index.column() == 1 || index.column() == 2)
		flags |= Qt::ItemIsEditable;
	return flags;
}
//! [0]

//! [1]
bool queryDataTable::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
	if (index.column() < 1 || index.column() > 2)
		return false;

	QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
	int id = data(primaryKeyIndex).toInt();

	clear();

	bool ok;
	if (index.column() == 1) {
		ok = setFirstName(id, value.toString());
	} else {
		ok = setLastName(id, value.toString());
	}
	refresh();
	return ok;
}
//! [1]

void queryDataTable::refresh()
{
	setQuery("select * from person");
	setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
	setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
}

//! [2]
bool queryDataTable::setFirstName(int personId, const QString &firstName)
{
	QSqlQuery query;
	query.prepare("update person set firstname = ? where id = ?");
	query.addBindValue(firstName);
	query.addBindValue(personId);
	return query.exec();
}
//! [2]

bool queryDataTable::setLastName(int personId, const QString &lastName)
{
	QSqlQuery query;
	query.prepare("update person set lastname = ? where id = ?");
	query.addBindValue(lastName);
	query.addBindValue(personId);
	return query.exec();
}
