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

void static Append(struct node **p, int num);
void static Display(struct node *p);
int static count(struct node *p);
void static selectionSort(struct node *start, int count);
#if 0
int main()
{
	struct node *p = nullptr;

	Append(&p, 27);
	Append(&p, 7);
	Append(&p, 99);
	Append(&p, 3);
	Display(p);

	int c = count(p);
	bubbleSort(p, c);
	cout << "after sorting" << endl;
	Display(p);

	return 0;
}
#endif

void  selectionSort(struct node *start, int count)
{
	struct node *p, *q;

	p = start;
	for (int i =0; i<count - 1;i++)
	{
		q = p->next;
		for (int j = i + 1; j < count; j++)
		{
			if (p->num > q->num)
			{
				swap(p->num, q->num);
			}
			q = q->next;
		}
		p = p->next;
	}
}

void  bubbleSort(struct node *start, int count)
{
	struct node *p, *q;

	p = start;
	for (int i = 0; i<count - 1; i++)
	{
		q = p->next;
		for (int j = i + 1; j < count; j++)
		{
			if (p->num > q->num)
			{
				swap(p->num, q->num);
			}
			q = q->next;
		}
		p = p->next;
	}

}

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