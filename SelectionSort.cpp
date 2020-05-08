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

//Simplest methos of sorting
//0th is comared of the rest like wise, 1st is comared with rest, at the end of 1st iteraton the smallest at the begining
// selection sort o(n^2) best, worst and avg complexity
#if 0
int main()
{
	int arr[5] = { 25,17,31,13,2 };


	for (int i = 0; i <= 3; i++)
	{
		for (int j = i+1; j <= 4; j++)
		{

			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}

	for (int i = 0; i <= 4; i++)
		cout << arr[i] << endl;

	return 0;
}
#endif

//std::cin.get();