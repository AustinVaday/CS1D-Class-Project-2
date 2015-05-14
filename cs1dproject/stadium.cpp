#include "stadium.h"

//Constructor
stadium::stadium()
{
	stadiumIndex = -1;
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
	this->stadiumIndex = stadiumNum;
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
	return stadiumIndex;
}

vector<vertexEdgeStruct> stadium::getVertexEdgeStructVector()
{
	return vertexEdgeVector;
}

QString stadium::getStadiumQuery(int keyIndex)
{
	QString queryString;
	queryString.append("('");
//	queryString.append(QString::number(keyIndex));
//	queryString.append("'', '");
	queryString.append(stadiumName);
	queryString.append("', '");
	queryString.append(teamName);
	queryString.append("', '");
	queryString.append(street);
	queryString.append("', '");
	queryString.append(city);
	queryString.append("', '");
	queryString.append(state);
	queryString.append("', '");
	queryString.append(QString::number(zip));
	queryString.append("', '");
	queryString.append(boxOfficeNum);
	queryString.append("', '");
	queryString.append(dateOpened);
	queryString.append("', '");
	queryString.append(capacity);
	queryString.append("', '");
	queryString.append(league);
	queryString.append("', '");
	queryString.append(surface);
	queryString.append("', '");
	queryString.append(returnFormatedEdges());
	queryString.append("')");

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
	stadiumIndex = number;
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
#if DEUBG
qDebug() <<	"Formatted string is: " << formattedString << endl;
#endif
	return formattedString;


}
