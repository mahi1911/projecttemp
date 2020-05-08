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

void static AddAtBegining(struct node **p, int num);
void static Reverse(struct node **p);
void static Display(struct node *p);
int static count(struct node *p);
#if 0
int main()
{
	struct node *listOfElem = nullptr;

	AddAtBegining(&listOfElem, 7);
	AddAtBegining(&listOfElem, 43);
	AddAtBegining(&listOfElem, 17);
	AddAtBegining(&listOfElem, 3);
	AddAtBegining(&listOfElem, 23);
	AddAtBegining(&listOfElem, 5);


	Display(listOfElem);

	cout << "After Reversing links: " << endl;
	Reverse(&listOfElem);
	Display(listOfElem);

	return 0;
}
#endif

void static Reverse(struct node **x)
{
	struct node *q, *r, *s;
	
	q = *x;
	r = nullptr;
	while (q != nullptr)
	{
		s = r;
		r = q;
		q = q->next;
		r->next = s;
	}

	*x = r;

}  

void AddAtBegining(struct node **p, int num)
{
	struct node *temp = new(struct node);
	temp->num = num;
	temp->next = *p;
	*p = temp;
}

void Display(struct node *p)
{
	while (p != nullptr)
	{
		cout << p->num << " ";
		p = p->next;
	}
	cout << endl;
}

int count(struct node *p)
{
	int tempCount = 0;
	while (p != nullptr)
	{
		tempCount++;
		p = p->next;
	}

	return tempCount;
}