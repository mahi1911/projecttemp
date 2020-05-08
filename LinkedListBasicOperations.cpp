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

void Append(struct node **p, int num);
void AddAtBegining(struct node **p, int num);
void AddAfter(struct node *p, int Afterlocations, int num);
void Display(struct node *p);
int count(struct node *p);
void DeleteElem(struct node **p, int numTobeDeleted);
#if 0
int main()
{
	struct node *listOfElem = NULL;

	Append(&listOfElem, 5);
	Append(&listOfElem, 3);
	Append(&listOfElem, 8);
	Append(&listOfElem, 7);
	Append(&listOfElem, 6);

	AddAtBegining(&listOfElem, 20);
	AddAtBegining(&listOfElem, 39);
	AddAtBegining(&listOfElem, 11);


	AddAfter(listOfElem, 5, 121);
	AddAfter(listOfElem, 11, 129);
	AddAfter(listOfElem, 1, 223);
	AddAfter(listOfElem, 0, 349);

	DeleteElem(&listOfElem, 5);
	DeleteElem(&listOfElem, 11);
	DeleteElem(&listOfElem, 121);

	Display(listOfElem);
	int numOfelems = count(listOfElem);
	cout << "num of elems: " << numOfelems << endl;

	return 0;
}
#endif
void Append(struct node **p, int num)
{
	if (*p == NULL)
	{
		struct node *temp = new(struct node);
		temp->num = num;
		temp->next = NULL;
		*p = temp;
	}
	else
	{
		struct node *counter = *p;
		while (counter->next != NULL)
			counter = counter->next;

		struct node *temp = new(struct node);
		temp->num = num;
		temp->next = NULL;
		counter->next = temp;
	}	
}

void AddAtBegining(struct node **p, int num)
{
	struct node *temp = new(struct node);
	temp->num = num;
	temp->next = *p;
	*p = temp;
}

void AddAfter(struct node *p, int Afterlocations, int num)
{
	struct node *temp = p;

	for (int i = 0; i < Afterlocations; i++)
	{
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "don't have that many locations" << endl;
			return;
		}
	}

	struct node *elem = new(struct node);
	elem->num = num;
	elem->next = temp->next;
	temp->next = elem;
}

void DeleteElem(struct node **p, int numTobeDeleted)
{
	struct node *temp = *p, *old = *p;
	while (temp != NULL)
	{
		if (temp->num == numTobeDeleted)
		{
			if (temp == *p)//First elem getting deleted			
				*p = temp->next;
			else
				old->next = temp->next;

			delete(temp);
			return;
		}
		else
		{
			old = temp;
			temp = temp->next;
		}
	}

	cout << endl << numTobeDeleted << " element not found" << endl;
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