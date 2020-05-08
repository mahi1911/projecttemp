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

void static AddInorder(struct node **p, int num);
void static Display(struct node *p);
int static count(struct node *p);
void static Merge(struct node *p, struct node *q, struct node **s);
#if 0
int main()
{
	struct node *first = nullptr, *second = nullptr, *third = nullptr;

	AddInorder(&first, 9);
	AddInorder(&first, 12);
	AddInorder(&first, 14);
	AddInorder(&first, 17);
	AddInorder(&first, 35);
	AddInorder(&first, 61);
	AddInorder(&first, 79);
	cout << "First list" << endl;
	Display(first);

	AddInorder(&second, 12);
	AddInorder(&second, 17);
	AddInorder(&second, 24);
	AddInorder(&second, 36);
	AddInorder(&second, 59);
	AddInorder(&second, 64);
	AddInorder(&second, 87);
	cout << "Second list" << endl;
	Display(second);

	Merge(first, second, &third);

	struct node *temp = first;
	while (first != nullptr)
	{
		first = first->next;
		delete temp;
		temp = first;
	}

	temp = second;
	while (second != nullptr)
	{
		second = second->next;
		delete temp;
		temp = second;
	}

	cout << "Merged list" << endl;
	Display(third);
	int numOfelems = count(third);
	cout << "num of elems: " << numOfelems << endl;

	return 0;
}
#endif

void Merge(struct node *p, struct node *q, struct node **s)
{
	struct node *z = nullptr;

	if (p == nullptr && q == nullptr)
		return;
	
	while (p != nullptr && q != nullptr)
	{
		if (*s == nullptr)
		{
			*s = new(struct node);
			z = *s;
		}
		else
		{
			z->next = new(struct node);
			z = z->next;
		}

		if (p->num < q->num)
		{
			z->num = p->num;
			p = p->next;

		}
		else
		{
			if (q->num < p->num)
			{
				z->num = q->num;
				q = q->next;

			}
			else if(p->num == q->num)
			{
				z->num = p->num;
				p = p->next;
				q = q->next;
			}
		}
	}

	while (p != nullptr)
	{
		z->next = new(struct node);
		z = z->next;
		z->num = p->num;		
		p = p->next;
	}

	while (q != nullptr)
	{
		z->next = new(struct node);
		z = z->next;
		z->num = q->num;
		q = q->next;
	}

	z->next = nullptr;
}

void AddInorder(struct node **q, int num)
{
	struct node *temp = new(struct node);
	temp->num = num;

	if (*q == nullptr || (*q)->num >= num)
	{
		temp->next = *q;
		*q = temp;
	}
	else
	{
		struct node *counter = *q;
		while (counter != nullptr)
		{
			if (counter->num <= num && (counter->next == nullptr || counter->next->num > num))
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