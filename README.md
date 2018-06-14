# CPSC335_Algorithms_HW1CPSC335_Project1_SortRace
Team Name : SLK
Members   : Scott Ng    - 891217754
          : Luis Rangel - 
          : Kavit       -
Contents  : source.cpp, MergSortAlg.h, Bubblesort.h, RaceMgr.h

*Intro

*BubbleSort Algorithm
This variation of bubblesort utilizes a sorted prefix and unsorted suffix. The first value of the suffix will compare with each value of the prefix until a swap occurs. When the prefix reaches right before the stuffix and the suffix is less than the last entry of prefix, then suffix entry is moved to the end of prefix by incrementing suffix pointer.

*MergeSort Algorithm
This variation of Merge Sort utilizes indices instead of arrays. Each array is indexed to a sublist size, which increases accordingly by pass. Sublists merge when they are swapped. Sublists increase when suffix > array size

*Sample
Enter Integer array to be sorted (MAX: 12): 42 24 56 65 82 25

# 2 M: [24 42 56 65 82 25 ]
# 4 B: [56 24 42 65 82 25 ]
# 3 M: [24 42 56 65 82 25 ]
# 7 B: [56 42 24 65 82 25 ]
# 4 M: [24 42 56 65 82 25 ]
# 9 B: [65 42 24 56 82 25 ]
# 6 M: [24 42 56 65 25 82 ]
# 11 B: [65 56 24 42 82 25 ]
# 7 M: [24 42 56 65 25 82 ]
# 14 B: [65 56 42 24 82 25 ]
# 8 M: [24 42 56 65 25 82 ]
# 16 B: [82 56 42 24 65 25 ]
# 9 M: [24 42 56 65 25 82 ]
# 18 B: [82 65 42 24 56 25 ]
# 10 M: [24 42 56 65 25 82 ]
# 20 B: [82 65 56 24 42 25 ]
# 11 M: [24 25 56 65 42 82 ]
# 23 B: [82 65 56 42 24 25 ]
# 12 M: [24 25 42 65 56 82 ]
# 29 B: [82 65 56 42 25 24 ]
Press any key to continue . . .
