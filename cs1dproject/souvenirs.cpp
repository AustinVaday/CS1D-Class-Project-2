#include "souvenirs.h"


souvenirs::souvenirs(QObject *parent) : QObject(parent)
{

}

souvenirs::~souvenirs()
{

}

QString souvenir:: setItem(QString name){
    QsqlQuery query;
    query.execute("Update Souvenirs set souvenir = " + name + " where souvenir = " + this.name_ + ";");
    this.name_ = name;
}

QString souvenir:: setPrice(int price){
    QsqlQuery query;
    query.execute("Update Souvenirs set price = " + price + " where souvenir = " + this.name_ + ";");
    this.price_ = price;
}

QString souvenir:: getName(){
    return name_;
}
int souvenir:: getPrice(){
    return price_;
}
