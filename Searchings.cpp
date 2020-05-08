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
#if 0
//Binary search,  log n base 2 to find an element
int main() {
	int arr[10] = { 1,2,3,9,11,13,17,25,57,90 };
	int lower = 0, higher = 9, num = 95;
	bool isFound = false;

	if (num > arr[lower] && num < arr[higher])
	{
		for (int middle = (lower + higher) / 2; lower <= higher; middle = (lower + higher) / 2)
		{
			if (arr[middle] = num)
			{
				cout << "Number found" << endl;
				isFound = true;
				break;
			}
			if (num > arr[middle])
				lower = middle + 1;
			else
				higher = middle - 1;
		}
	}

	if (!isFound)
		cout << "Not found"<<endl;

	return 0;
}
#endif
#if 0
//Linear search on a unsorted array, o(n) to find an element
int main() {
	int arr[10] = { 11,2,9,13,57,25,17,1,90,3 };
	int num = 25;

	for (auto index = 0; index <= 9; index++)
	{
		if (num == arr[index])
		{
			cout << "Found"<<endl;
			break;
		}
	}

	return 0;
}
#endif
#if 0
//Linear search on a sorted array, o(n) to find an element
int main() {
	int arr[10] = { 1,2,3,9,11,13,17,25,57,90 };
	int num = 4;
	bool found = false;

	if (num > arr[0] && num < arr[9])
	{
		for (auto index = 0; index <= 9; index++)
		{
			if (num == arr[index])
			{
				cout << "Found" << endl;
				found = true;
				break;
			}
			if (arr[index] > num)
			{
				break;
			}
		}
	}

	if (!found)
		cout << "Not found" << endl;

	return 0;
}
#endif