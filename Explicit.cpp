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

class Test
{

public:
	//Without explicit Test obj = 1; will call the following cstr 
	explicit Test(int x)
	{
		cout << " CSTR" << endl;
	}
};
#if 0
int main()
{
	Test obj = 1;

	return 0;
}
#endif
//std::cin.get();