// Author: Scott Ng
// DESC  : RaceMgr calls step functions in the same while loop
//       : the algorithm's step will stop by returning a true value
#pragma once
#include <string>
#include <sstream>
#include "Bubblesort.h"
#include "Mergsort.h"

using namespace std;

const int MAX_INT = 12;
const int MAX_STR = 24;

class RaceMgr  
{
	BubbleSort BS;
	MergeSort  MS;

public:
	// Member Functions()
	RaceMgr(int argv_arry[], int n);
	void run();
	void print(int argv_array[], int step_count, int array_size, char sort_name);
	void print_helper();
	
};

RaceMgr::RaceMgr(int argv_arry[], int n)
{ 
	// n is size of the array
	// moves user input into each array object
	BS.populate(argv_arry, n);
	MS.populate(argv_arry, n);
};

void RaceMgr::print(int *argv_array, int step_count, int array_size, char sort_name)
{
	cout << "# " << step_count << " " << sort_name <<": [";
	for(int i = 0; i < array_size; i++)
		cout << argv_array[i] << ' ';
	cout << "]\n\n";
};

void RaceMgr::run()
{
	// there are 3 states
	// 0 = not done
	// 1 = done
	// 2 = moved value

	// continues to call step until both functions are done
	// when one is done, part of the function will cease

	while(BS.get_state() != 1 && BS.get_state() != 1)
	{
		if(BS.get_state() != 1)
		{
			BS.step();
			if(BS.get_state() == 2)
				print(BS.get_array(), BS.get_step_count(), BS.get_user_size(), BS.get_sort_name());
		};

		if(MS.get_state() != 1)
		{
			MS.step();
			if(MS.get_state() == 2)
				print(MS.get_array(), MS.get_step_count(), MS.get_user_size(), MS.get_sort_name());
		}
	};

};