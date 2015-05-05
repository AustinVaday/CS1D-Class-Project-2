#ifndef SOUVENIRS_H
#define SOUVENIRS_H

#include <QObject>
#include <QString>
#include <MainHeader.h>
#include <QSqlQuery>
#include <QSql>
class souvenirs : public QObject
{
    Q_OBJECT
public:
    /**************************************************************************
     * Default Constructor
     *************************************************************************/
	explicit souvenirs(QObject *parent = 0,QSqlDatabase *db = 0);
    ~souvenirs();

    /**************************************************************************
     * Set name of souvenir
     *************************************************************************/
	void setItem(QString name);

    /**************************************************************************
     * Set price of souvenir
     *************************************************************************/
    void setPrice(QString price);

    /**************************************************************************
     * Returns the name of souvenir
     *************************************************************************/
	QString getName();

    /**************************************************************************
     * Returns the price of souvenir
     *************************************************************************/
	QString getPrice();

private:
    QString name_;
	QSqlQuery query;
	QString price_;
signals:

public slots:
};

#endif // SOUVENIRS_H
