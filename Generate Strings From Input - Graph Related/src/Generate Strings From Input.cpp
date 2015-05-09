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
	string vertex;
	string v1;
	string v2;
	string weight;
	vector<string> stadiums;
	bool firstIteration = false;

	oFile.open("oFile.txt");
	inFile.open("inFile.txt");

	while (!inFile.eof())
	{
		getline(inFile, vertex);

		stadiums.push_back(vertex);
	}


	cout << "Begin Program -- type next to proceed to next stadium\n";
	cout << "========================================================\n";

	for (unsigned int i = 0; i < stadiums.size(); i++)
	{

		v1 = stadiums[i];
		firstIteration = true;

		while (v2 != "next")
		{
			cout << "Currently at " << v1 << ".\n";
			cout << "Connects to [enter next when done]: ";
			getline(cin, v2);

			if (v2 != "next")
			{
				cout << "With weight: ";
				getline(cin, weight);
			}

			if (v2 != "next" && weight != "next")
			{
				// write to file..
				if (firstIteration)
				{
					oFile << "Add the below to " << v1 << endl;
					firstIteration = false;
				}
				else
				{
					// add a tilde to separate subsequent iterations
					oFile << '~';
				}

				// special concatenated expression (separated by delimiters)
				oFile << v2 << ';' << weight;
			}

		}

		oFile << endl;
		v2 = "";
	}

	oFile.close();
	inFile.close();



	return 0;
}
