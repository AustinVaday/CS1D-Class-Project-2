#include "stadium.h"

//Constructor
stadium::stadium()
{
    stadiumNumber = -1;
    stadiumName.clear();
    teamName.clear();
    street.clear();
    city.clear();
    state.clear();
    zip = -1;
    boxOfficeNum.clear();
    dateOpened.clear();
    capacity.clear();
    league.clear();
    surface.clear();



//    visited       = false;
}
//Deconstructor
stadium::~stadium()
{

}
stadium::stadium (int stadiumNum,
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
         )
{
    this->stadiumNumber = stadiumNum;
    this->stadiumName = stadiumName;
    this->teamName = teamName;
    this->street = street;
    this->city = city;
    this->state = state;
    this->zip = zipCode;
    this->boxOfficeNum = boxOfficeNum;
    this->dateOpened = dateOpened;
    this->capacity = capacity;
    this->league = league;
    this->surface = surface;
    this->vertexEdgeVector = vertexEdgeVector;
}

QString stadium::getCity()
{
    return city;
}

QString stadium::getPlayingSurface()
{
    return surface;
}

QString stadium::getStadiumName()
{
    return stadiumName;
}

int stadium::getStadiumNumber()
{
    return stadiumNumber;
}

vector<vertexEdgeStruct> stadium::getVertexEdgeStructVector()
{
    return vertexEdgeVector;
}

QString stadium::getTeamName()
{
    return teamName;
}

//bool stadium::getVisited()
//{
//    return visited;
//}

bool stadium::operator==(stadium& otherStadium)
{
    if (this->getStadiumName()   == otherStadium.getStadiumName()
/*     && this->getStadiumNumber() == otherStadium.getStadiumNumber()*/)
     {
        return true;
     }
    else
     {
        return false;
     }
}

// overloaded extraction operator to display some data..
QDebug operator<<(QDebug out, stadium& displayStadium)
{
    out << displayStadium.getStadiumName();

    return out;
}

void stadium::setCity(QString cityN)
{
    city = cityN;
}

void stadium::setPlayingSurface(QString grassTypeN)
{
    surface = grassTypeN;
}

void stadium::setStadiumName(QString stadiumNameN)
{
    stadiumName = stadiumNameN;
}

void stadium::setStadiumNumber(int number)
{
    stadiumNumber = number;
}

void stadium::setState(QString stateN)
{
    state = stateN;
}

void stadium::setTeamName(QString teamNameN)
{
    teamName = teamNameN;
}

//void stadium::setVisited(bool visitedN)
//{
//    visited = visitedN;
//}

