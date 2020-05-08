#include"stdafx.h"
#include<iostream> 
#include <exception>
#include <vector>
#include <map>
#include <iostream> 
using namespace std;


// Class representing a shared pointer 
template <typename T>

class Shared_ptr {

	// Reference counter 
	int* m_counter;

	// Shared pointer 
	T* m_ptr;

public:
	// Constructor 
	explicit Shared_ptr(T* ptr = nullptr)
	{
		m_ptr = ptr;
		m_counter = new int();
		if (ptr) {
			(*m_counter)++;
		}
	}

	// Copy constructor 
	Shared_ptr(Shared_ptr<T>& sp)
	{
		cout << "copy constr??" << endl;
		m_ptr = sp.m_ptr;
		m_counter = sp.m_counter;
		(*m_counter)++;
	}

	// Destructor 
	~Shared_ptr()
	{
		(*m_counter)--;
		if (*m_counter == 0)
		{
			delete m_counter;
			delete m_ptr;
		}
	}

	// Get the pointer 
	T* get()
	{
		return m_ptr;
	}

	T& operator*() const { return *m_ptr; }


	friend ostream& operator<<(ostream& os, Shared_ptr<T>& sp)
	{
		os << "Address pointed : "
			<< sp.get() << endl;
		cout << *(sp.m_counter) << endl;

		return os;
	}
};

class MyCls
{
public:
	void print() { cout << "MyCls" << endl; }
};
#if 0
int main()
{
	// ptr1 pointing to an integer. 
	Shared_ptr<int> ptr1(new int(151));
	Shared_ptr<int> ptr5(new int(134));
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;


	{
		// ptr2 pointing to same integer 
		// which ptr1 is pointing to 
		// Shared pointer reference counter 
		// should have increased now to 2. 
		Shared_ptr<int> ptr2 = ptr1;
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;

		{
			// ptr3 pointing to same integer 
			// which ptr1 and ptr2 are pointing to. 
			// Shared pointer reference counter 
			// should have increased now to 3. 
			Shared_ptr<int> ptr3(ptr2);
			Shared_ptr<int> ptr6(ptr5);
			cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
			cout << ptr1;
			cout << ptr2;
			cout << ptr3;

			cout << "--- Shared pointers ptr5, ptr6 ---\n";
			cout << ptr5;
			cout << ptr6;
		}

		// ptr3 and ptr6 are out of scope. 
		// It would have been destructed. 
		// So shared pointer reference counter 
		// should have decreased now to 2. 
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;

		cout << "--- Shared pointers  ptr5 ---\n";
		cout << ptr5;
	}

	// ptr2 is out of scope. 
	// It would have been destructed. 
	// So shared pointer reference counter 
	// should have decreased now to 1. 
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;

	Shared_ptr<MyCls> myclsPtr(new MyCls());
	myclsPtr.get()->print();
	return 0;
}





#endif