#include "souvenirs.h"

souvenirs::souvenirs(QObject *parent) : QObject(parent)
{

}

souvenirs::~souvenirs()
{

}

void souvenirs:: addSouvenir(qstring name, int price){
    QsqlQuery query;
    query.execute("Insert into Souvenirs (souvenir, price) VALUES (name,price);" );
}

void souvenirs:: deleteSouvenir(qstring name){
    QsqlQuery query;
    query.execute("Delete from Souvenirs where souvenir = name;");
}

//Name = new name, souvenirName = name of souvenir you want to change
qstring souvenir:: setSouvenirName(qstring name, qstring souvenirName){
    QsqlQuery query;
    query.execute("Update Souvenirs set souvenir = name where souvenir = souvenirName;");
}
//souvenirName = name of souvenir you want to modify
qstring souvenir:: setSouvenirPrice(int price, qstring souvenirName){
    QsqlQuery query;
    query.execute("Update Souvenirs set price = price where name = souvenirName;");
}
