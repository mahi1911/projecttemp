#include"stdafx.h"
#include<iostream> 
#include <exception>
#include <vector>
#include <map>
#include <iostream> 
using namespace std;

class INonCopyable
{
public:
	INonCopyable() = default;
	INonCopyable(const INonCopyable& ref) = delete;
	INonCopyable& operator=(const INonCopyable& ref) = delete;
};

class MyClass :INonCopyable // INonCopyableis nothing to do with deep copy, it is just showing default and delete usage
{
	int* ptr;
public:
	MyClass() { ptr = new int(0); }
	MyClass(int val) { ptr = new int(val); }
	MyClass(const MyClass& ref)//with out defining you can't use copy constructor as base deleted this
	{
		cout << "Copy CSTR" << endl;
		ptr = new int(*ref.ptr);
	}
	MyClass& operator =(const MyClass& ref)////with out defining you can't use assign as base deleted this
	{
		if (&ref != this)//making sure that this is not already having the ref 
		{
			ptr = new int(*ref.ptr);
		}

		cout << "Assignment Operator" << endl;
		return *this;
	}

};
#if 0
int main()
{
	MyClass cls;
	MyClass cls1 = cls;

	return 0;
}
#endif