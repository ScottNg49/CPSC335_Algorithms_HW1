// CPSC335-04_Project1_SortRace
// Team Name   : SLK
// Contents    : Source.cpp, Mergsort.h, Bubblesort.h, RaceMgr.h
// Team Members: Scott Ng
//             : Luis Rangel
//             : Kavit
#include "RaceMgr.h"

int main()
{
	string InputArray;

	int myarry[12];
	cout << "Enter Integer array to be sorted (MAX: 12): ";
	getline(cin, InputArray);

	stringstream ss(InputArray);
	string s;
	int i = 0;
	
	//parses string by delimiter whitespace
	while (getline(ss, s, ' ')) {
		myarry[i] = stoi(s);
		i++;
	}
	int array_size = i;
	
	if(array_size > 1)
	{
		// if size is one, then it is sorted
		RaceMgr Mgr(myarry, array_size);
		Mgr.run();
	}
	else
	{
		// single element is already sorted
		cout << "The array is already sorted\n";
	}

	system("pause");
	return 0;
};