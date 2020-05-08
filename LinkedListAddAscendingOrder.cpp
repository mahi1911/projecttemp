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

struct node
{
	int num;
	struct node *next;
};

void AddInorder(struct node **p, int num);
void static Display(struct node *p);
int static count(struct node *p);
#if 0
int main()
{
	struct node *listOfElem = NULL;

	AddInorder(&listOfElem, 3); 
	AddInorder(&listOfElem, 5);	
	AddInorder(&listOfElem, 8);
	AddInorder(&listOfElem, 7);
	AddInorder(&listOfElem, 6);
	AddInorder(&listOfElem, 20);

	Display(listOfElem);
	int numOfelems = count(listOfElem);
	cout << "num of elems: " << numOfelems << endl;

	return 0;
}
#endif
void AddInorder(struct node **q, int num)
{
	struct node *temp = new(struct node);
	temp->num = num;

	if (*q == NULL || (*q)->num  >= num)
	{
		temp->next = *q;
		*q = temp;
	}
	else
	{
		struct node *counter = *q;
		while (counter != NULL)
		{
			if (counter->num <= num && (counter->next == NULL|| counter->next->num > num) )
			{
				temp->next = counter->next;
				counter->next = temp;
				return;
			}
			counter = counter->next;
		}
	}
}

void Display(struct node *p)
{
	while (p != NULL)
	{
		cout << p->num << " ";
		p = p->next;
	}
	cout << endl;
}

int count(struct node *p)
{
	int tempCount = 0;
	while (p != NULL)
	{
		tempCount++;
		p = p->next;
	}

	return tempCount;
}