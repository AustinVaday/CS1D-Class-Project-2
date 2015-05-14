#include "souvenirs.h"


souvenirs::souvenirs(QObject *parent, QSqlDatabase *db) : QObject(parent)
{

    QSqlDatabase temp;

    try
    {
//        query = QSqlQuery::QSqlQuery(temp);

    }
    catch(...)
    {
        qDebug() << "Souvenirs Constructor" << endl;
    }
}

souvenirs::~souvenirs()
{

}

void souvenirs::setItem(QString name){
	query.exec("Update Souvenirs set Souvenir = " + name + " where souvenir = " + name_ + ";");
	name_ = name;
}

void souvenirs::setPrice(QString price){
    query.exec("Update Souvenirs set price = " + price + " where souvenir = " + name_ + ";");
    price_ = price.toFloat();
}

QString souvenirs::getName(){
	return name_;
}
float souvenirs::getPrice(){
	return price_;
}
