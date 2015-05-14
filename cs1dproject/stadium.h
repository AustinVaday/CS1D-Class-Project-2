#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include "souvenirs.h"
#include "MainHeader.h"
#include <vector>

class stadium
{
public:
    //Constructor
    stadium();
    //Destructor
    ~stadium();
    stadium (int stadiumNum,
             QString stadiumName,
             QString teamName,
             QString street,
             QString city,
             QString state,
             int zipCode,
             QString boxOfficeNum,
             QString dateOpened,
             QString capacity,
             QString league,
             QString surface,
             vector<vertexEdgeStruct> vertexEdgeVector
             );

    //Accessors
    QString getStadiumName();
    QString getTeamName();
    QString getCity();
    QString getState();
    QString getPlayingSurface();
    QString getStreetName();
    QString getZip();
    int     getStadiumNumber();
    QString getBoxOfficeNum();
    QString getDateOpened();
    QString getGrassType();
    QString getCapacity();
    QString getLeague();
    vector<vertexEdgeStruct> getEdgeVector();
    vector<vertexEdgeStruct> getVertexEdgeStructVector();
    //getDate()
    //    bool getVisited();
	QString getStadiumQuery();
    QString returnFormatedEdges();

    // should pass by const reference, but does
    // not work with this implementation because
    // the accessors are not const.....
    bool operator==(stadium& otherStadium);
    void operator = (stadium otherStadium);

    // overloaded extraction operator to display some data..
    friend QDebug operator<<(QDebug out, stadium& displayStadium);

    //Mutators
    void setStadiumName(QString stadiumName);
    void setStadiumNumber(int number);
    void setTeamName(QString teamName);
    void setPlayingSurface(QString grassType);
    void setCity(QString city);



//    void setBoxOfficeNum(QString bO);
    void setState(QString state);
//    void setEdgeVector(vector<vertexEdgeStruct> vec);
//    void setZipCode(int zipCode);
//    void setDateOpened();
//    void setStreetName(QString name);
//    void setLeague(QString league);
//    void setSurface(QString surface);


void getZipInt();
    //    void setVisited(bool visited);
    //void resetTrip()

private:
    int               stadiumNumber;
    QString           stadiumName;
    QString           teamName;
    QString           street;
    QString           city;
    QString           state;
    int               zip;
    QString           boxOfficeNum;
    QString           dateOpened;
    QString           capacity;
    QString           league;
    QString           surface;
    vector<vertexEdgeStruct> vertexEdgeVector;

};



#endif // STADIUM_H
