#include "stadium.h"

//Constructor
stadium::stadium()
{
    stadiumName.clear();
    teamName.clear();
    city.clear();
    state.clear();
    grassType.clear();
    stadiumNumber = -1;
    visited       = false;
}
//Deconstructor
stadium::~stadium()
{

}

QString stadium::getCity()
{
    return city;
}

QString stadium::getPlayingSurface()
{
    return grassType;
}

QString stadium::getStadiumName()
{
    return stadiumName;
}

int stadium::getStadiumNumber()
{
    return stadiumNumber;
}

QString stadium::getTeamName()
{
    return teamName;
}

bool stadium::getVisited()
{
    return visited;
}

bool stadium::operator==(stadium& otherStadium)
{
    if (this->getStadiumName()   == otherStadium.getStadiumName()
     && this->getStadiumNumber() == otherStadium.getStadiumNumber())
     {
        return true;
     }
    else
     {
        return false;
     }
}

void stadium::setCity(QString cityN)
{
    city = cityN;
}

void stadium::setPlayingSurface(QString grassTypeN)
{
    grassType = grassTypeN;
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

void stadium::setVisited(bool visitedN)
{
    visited = visitedN;
}
