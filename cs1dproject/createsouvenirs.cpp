#include "souvenirs.h"
#include <QVector>

void createSouvenirs(QVector <souvenirs> souvenirList){
    QSqlQuery query;
    query.exec("Select * from souvenirs");

    while(query.next()){
        souvenirs object;
        object.setItem(query.value(0).toString());
        object.setPrice(query.value(1).toString());

//        souvenirList.push_back(object);
    }
}
