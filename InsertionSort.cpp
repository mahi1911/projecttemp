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
// Insertion sort n-1 best, o(n^2) worst and avg complexity
#if 0
int main()
{
	int arr[5] = { 31,17,25,13,2 };
	//17 31 25 13 2
	//17 25 31 13 2

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				//std::swap(arr[j], arr[i]);
				int temp,k;
				temp = arr[j];
				arr[j] = arr[i];


				for (k = i; k > j; k--)
					arr[k] = arr[k - 1];

				arr[k + 1] = temp;

			}
		}
		int k = 10;
	}

	for (int i = 0; i <= 4; i++)
		cout << arr[i] << endl;

	return 0;
}
#endif
//std::cin.get();