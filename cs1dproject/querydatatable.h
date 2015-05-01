#ifndef QUERYDATATABLE_H
#define QUERYDATATABLE_H

#include <QSqlQueryModel>

class queryDataTable : public QSqlQueryModel
{
		Q_OBJECT

	public:
		queryDataTable(QObject *parent = 0);

		Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
		bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;

	private:
		bool setFirstName(int personId, const QString &firstName);
		bool setLastName(int personId, const QString &lastName);
		void refresh();
};

#endif // QUERYDATATABLE_H
