#include"stdafx.h"
#include<iostream> 
#include <exception>
#include <vector>
#include <map>
#include <list>
#include <iostream> 
using namespace std;

class Hash
{
	int BUCKET;				  // No. of buckets 
	using MyData = list<int>; // My data is list of integers

	MyData *hashTable;  // hashTable is a pointer and each element in a pointer is a list 

public:
	Hash(int V);  // Constructor 

				  // inserts a key into hash hashTable 
	void insertItem(int x);

	// deletes a key from hash hashTable 
	void deleteItem(int key);

	// hash function to map values to key 
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	BUCKET = b;
	hashTable = new MyData[BUCKET];
	//hashTable = new list<int>[BUCKET];
	//*list<int> = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	hashTable[index].push_back(key);
}

void Hash::deleteItem(int key)
{
	// get the hash index of key 
	int index = hashFunction(key);

	// find the key in (inex)th list 
	list <int> ::iterator i;
	for (i = hashTable[index].begin();
		i != hashTable[index].end(); i++) {
		if (*i == key)
			break;
	}

	// if key is found in hash hashTable, remove it 
	if (i != hashTable[index].end())
		hashTable[index].erase(i);
}

// function to display hash hashTable 
void Hash::displayHash() {
	for (int i = 0; i < BUCKET; i++) {
		cout << i;
		for (auto x : hashTable[i])
			cout << " --> " << x;
		cout << endl;
	}
}

#if 0
// Driver program  
int main()
{	
	// array that contains keys to be mapped 
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	// insert the keys into the hash hashTable 
	Hash h(7);   // 7 is count of buckets in 
				 // hash hashTable 
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);

	// delete 12 from hash hashTable 
	h.deleteItem(12);

	// display the Hash hashTable 
	h.displayHash();

	return 0;
}
#endif


