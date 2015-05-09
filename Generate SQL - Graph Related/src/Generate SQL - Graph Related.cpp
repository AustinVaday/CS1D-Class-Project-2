//============================================================================
// Name        : Generate.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ofstream oFile;
	ifstream inFile;
	string data;

	vector<string> stringVector;
	oFile.open("oFileSQL.txt");
	inFile.open("inFile.txt");

	while (!inFile.eof())
	{
		// get rid of first line (it's meaningless)
		getline(inFile, data);
		getline(inFile, data);

		stringVector.push_back(data);
	}


	for (unsigned int i = 0; i < stringVector.size(); i++)
	{
		oFile << "UPDATE Stadiums SET verticesAndEdges='";
		oFile << stringVector[i];
		oFile << "'  WHERE PrimaryKey=" << i+1 << ";\n";
	}

	oFile.close();
	inFile.close();



	return 0;
}
