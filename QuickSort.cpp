#include"stdafx.h"
#include<iostream> 
#include <exception>
#include <vector>
#include <map>
#include <list>
#include <iostream> 
#include <thread>
#include <mutex>
#include <string>
#include <regex>
#include <algorithm>
#include <numeric>
#include <future>
#include <type_traits>
#include <future>         // std::async, std::future

using namespace std;

// Quick sort, also known as partition exchange sort
// Very popular  and faster sorting technic. Works based on divide and conquer technique
// o(n^2) worst case. log n base 2 best and avg complexity

void quickSort(int *, int, int);
int split(int *, int, int);
#if 0
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	quickSort(arr, 0, 9);
	
	for (int i = 0; i <= 9; i++)
		cout << arr[i] << endl;

	return 0;
}

#endif

void quickSort(int arr[], int lower, int upper)
{
	int middle;
	if (upper > lower)
	{
		middle = split(arr, lower, upper);
		quickSort(arr, lower, middle - 1);
		quickSort(arr, middle + 1, upper);
	}
}

int split(int arr[], int lower, int upper)
{
	int pivotElement, lowerIndex, upperIndex;

	pivotElement = arr[lower];

	lowerIndex = lower + 1;
	upperIndex = upper;
	
	while (upperIndex >= lowerIndex)
	{
		while (arr[lowerIndex] > pivotElement)
			lowerIndex++;
		while (arr[upperIndex] < pivotElement)
			upperIndex--;

		if (upperIndex > lowerIndex)
			std::swap(arr[lowerIndex], arr[upperIndex]);
	}	

	swap(arr[lower], arr[upperIndex]);	//Fix the pivotelement position

	return upperIndex;
}
//std::cin.get();