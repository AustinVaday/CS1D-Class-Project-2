#ifndef SOUVENIRS_H
#define SOUVENIRS_H

#include <QObject>

class souvenirs : public QObject
{
    Q_OBJECT
public:
    explicit souvenirs(QObject *parent = 0);
    ~souvenirs();
    void addSouvenir(qstring name, int price);
    void deleteSouvenir(qstring name);
    void setSouvenirName(qstring name, qstring souvenirName);
    void setSouvenirPrice(qstring price, qstring souvenirName);

signals:

public slots:
};

#endif // SOUVENIRS_H
