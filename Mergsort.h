// Author: Scott Ng
// DESC  : This variation of Merge Sort utilizes indices instead of arrays.
//       : Each array is indexed to a sublist size, which increases accordingly by pass
#pragma once
#include <iostream>
using namespace std;

class MergeSort
{
	int  user_array[MAXSIZE],
	     user_size,
		 step_count,
		 prefix,
		 suffix,
	     state,
		 sub_list_size;
	char sort_name;

public:

	MergeSort();
	int get_state();
	int step();
	int (&get_array())[MAXSIZE];
	int get_step_count();
	int get_user_size();
	char get_sort_name();

	void swap(int i, int j);
	void populate(int argv_array[], int n);
};

MergeSort::MergeSort()
{
	// constructor
	// sub_list_size will be 2^n
	prefix = 0;
	suffix = 1;
	sub_list_size = 1;
	state = 0;
	sort_name = 'M';

	// initializing contents to 0
	for(int i = 0; i < 12; i++)
		user_array[i] = 0;
}

void MergeSort::populate(int argv_array[], int n)
{
	// n is size of array
	// passing argv into obj array

	user_size = n;
	step_count = 0;

	for(int i = 0; i < user_size; i++)
		user_array[i] = argv_array[i];
};

void MergeSort::swap(int i, int j)
{
	// swaps the two locations of variables
	// temp holds the user_array[i]

	int temp = user_array[i];
	user_array[i] = user_array[j];
	user_array[j] = temp;
	state = 2;
};

char MergeSort::get_sort_name()
{
	return sort_name;
};

int MergeSort::get_state()
{
	return state;
}

int (&MergeSort::get_array())[MAXSIZE]
{
	return user_array;
};

int MergeSort::get_user_size()
{
	return user_size;
};

int MergeSort::get_step_count()
{
	return step_count;
};

int MergeSort::step()
{
	// sorting from least to greatest
	/*if(suffix == prefix && suffix >= (user_size - 1))
	{
		state = 1;
		return state;
	};*/

	//suffix starts one past prefix

	if(user_array[prefix] > user_array[suffix] && suffix != prefix)
	{
		// if prefix > suffix value
		swap(prefix, suffix);
		step_count++;
		prefix++;
	}

	if(prefix == suffix && suffix <= (user_size - 1))
	{
		// if ever equal, time to move onto next sublist
		suffix += (2*sub_list_size);
		prefix += (sub_list_size);
		step_count++;
	}

	else if(user_array[prefix] < user_array[suffix])
	{
		// if smaller, then increment prefix
		step_count++;
		prefix++;
	}

	if(suffix > user_size - 1)
	{
		// concludes length of sub_list merge
		sub_list_size *= 2;
		suffix = sub_list_size;
		prefix = 0;
	};

	if(suffix >= (user_size))
	{
		state = 1;
	};

	return state;
}