#include "souvenirs.h"


souvenirs::souvenirs(QObject *parent, QSqlDatabase *db) : QObject(parent)
{
query = QSqlQuery::QSqlQuery(*db);
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
	price_ = price;
}

QString souvenirs::getName(){
	return name_;
}
QString souvenirs::getPrice(){
	return price_;
}
