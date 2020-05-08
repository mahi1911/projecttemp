/*
Calls fn (with args as arguments) at some point, returning without waiting for the execution of fn to complete.

The value returned by fn can be accessed through the future object returned (by calling its member future::get).

The second version (2) lets the caller select a specific launching policy, while the first version (1) uses automatic selection, as if calling (2) with launch::async|launch::deferred as policy
*/

// launch::async vs launch::deferred
#include"stdafx.h"
#include <iostream>     // std::cout
#include <future>       // std::async, std::future, std::launch
#include <chrono>       // std::chrono::milliseconds
#include <thread>       // std::this_thread::sleep_for

using namespace std;
void print_ten(char c, int ms) {
	for (int i = 0; i<10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		std::cout << c;
	}
}
#if 0
int main()
{
	std::cout << "with launch::async:\n";
	std::future<void> foo = std::async(std::launch::async, print_ten, '*', 100);//launching policy async
	std::future<void> bar = std::async(std::launch::async, print_ten, '@', 200);//launching policy async
	// async "get" (wait for foo and bar to be ready):
	foo.get();
	bar.get();
	std::cout << "\n\n";

	std::cout << "with launch::deferred:\n";
	foo = std::async(std::launch::deferred, print_ten, '*', 100); //launching policy deferred
	bar = std::async(std::launch::deferred, print_ten, '@', 200); //launching policy deferred
	// deferred "get" (perform the actual calls):
	foo.get();
	bar.get();
	std::cout << '\n';

	return 0;
}
#endif