#ifndef PROJSQLMODEL_H
#define PROJSQLMODEL_H
#include <QSqlQueryModel>
#include <QModelIndex>

//![0]
class projsqlmodel : public QSqlQueryModel
{
	Q_OBJECT
	public:

		projsqlmodel(QObject *parent = 0);
		QVariant data(const QModelIndex &item, int role) const Q_DECL_OVERRIDE;

};
//![0]

#endif // PROJSQLMODEL_H
