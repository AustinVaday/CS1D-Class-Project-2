#ifndef SOUVENIRS_H
#define SOUVENIRS_H

#include <QObject>
#include <QString>

class souvenirs : public QObject
{
    Q_OBJECT
public:
    /**************************************************************************
     * Default Constructor
     *************************************************************************/
    explicit souvenirs(QObject *parent = 0);
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
    QString getItem();

    /**************************************************************************
     * Returns the price of souvenir
     *************************************************************************/
    double getPrice();

private:
    QString name_;
    int price_;
signals:

public slots:
};

#endif // SOUVENIRS_H
