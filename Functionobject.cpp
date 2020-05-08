#include"stdafx.h"
#include<iostream> 


// generate algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

using namespace std;

// function generator:
int RandomNumber() { return (std::rand() % 100); }

// class generator:
struct c_unique {
	int current;
	c_unique() { current = 0; }
	int operator()() { return ++current; }
} UniqueNumber;
#if 0
int main() {
	std::srand(unsigned(std::time(0)));

	std::vector<int> myvector(8);

	std::generate(myvector.begin(), myvector.end(), RandomNumber);// function pointer as a gen algo

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::generate(myvector.begin(), myvector.end(), UniqueNumber);//Function object as gen also

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
#endif