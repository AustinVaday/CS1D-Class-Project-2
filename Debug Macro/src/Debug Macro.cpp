/**************************************************************************
 * Austin Vaday
 *************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Output a variable's name and the variable's content
#define DEBUG(x) cerr << "[Debug] " << left << setw(10) << #x << " : " << x << endl;

int main()
{

	int myInt = 4;
	string myName = "Austin";
	bool myBool = false;


	DEBUG(myInt);
	DEBUG(myName);
	DEBUG(myBool);

	return 0;
}
