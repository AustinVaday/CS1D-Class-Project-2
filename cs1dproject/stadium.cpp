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

QString stadium::getStadiumQuery()
{
	QString queryString;

	queryString = ", '" + stadiumName + "', '"
				+ teamName + "', '"
				+ street + "', '"
				+ city + "', '"
				+ state + "', '"
				+ zip + "', '"
				+ boxOfficeNum + "', '"
				+ dateOpened + "', '"
				+ capacity + "', '"
				+ league + "', '"
                + surface + "', '" + returnFormatedEdges() + "')";

	return queryString;
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

//Used to send data to the database
QString stadium::returnFormatedEdges()
{

    vector<vertexEdgeStruct>::iterator it;
    QString formattedString;


    for(it = vertexEdgeVector.begin(); it != vertexEdgeVector.end(); it++)
    {
        formattedString += (*it).otherVertex + ";" + QString::number((*it).edge);

        it++;
        if(it != vertexEdgeVector.end())
        {
            formattedString += "~";
        }
        it--;
    }

    return formattedString;
}

QString stadium::getStreetName()
{
    return street;
}

QString stadium::getZip()
{
    return QString::number(zip);
}

QString stadium::getBoxOfficeNum()
{
    return boxOfficeNum;
}

QString stadium::getDateOpened()
{
    return dateOpened;
}
QString stadium::getCapacity()
{
    return capacity;
}
QString stadium::getGrassType()
{
    return surface;
}

QString stadium::getLeague()
{
    return league;
}
void stadium::operator=(stadium otherStadium)
{
      this->stadiumName = otherStadium.stadiumName;
      this->stadiumNumber = otherStadium.stadiumNumber;
      this->state         = otherStadium.state;
      this->street        = otherStadium.street;
    this->zip            = otherStadium.zip;
      this->surface       = otherStadium.surface;
      this->teamName      = otherStadium.teamName;
    this->boxOfficeNum    = otherStadium.boxOfficeNum;
    this->league          = otherStadium.league;
    this->dateOpened      = otherStadium.dateOpened;
    this->capacity        = otherStadium.capacity;
//    this->vertexEdgeVector= otherStadium.vertexEdgeVector;
}

QString stadium::getState()
{
    return state;
}
