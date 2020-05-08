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

//Adjusent elements are comared, at the end of 1st iteration the largest is at the end
// Bubble sort o(n^2) best, worst and avg complexity
#if 0
int main()
{
	int arr[5] = { 25,17,31,13,2 };


	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3 - i; j++)
		{

			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}

	for (int i = 0; i <= 4; i++)
		cout << arr[i] << endl;

	return 0;
}
#endif

//std::cin.get();