/*
In Factory pattern, we create object without exposing the creation logic to client and the client use the same common interface to create new type of object.
*/

#include"stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#if 0
enum VehicleType {
	VT_TwoWheeler, VT_ThreeWheeler, VT_FourWheeler
};

// Library classes 
class Vehicle 
{
public:
	virtual void printVehicle() = 0;
	static Vehicle* Create(VehicleType type);
};

class TwoWheeler : public Vehicle 
{
public:
	void printVehicle() 
	{
		cout << "I am two wheeler" << endl;
	}
};

class ThreeWheeler : public Vehicle 
{
public:
	void printVehicle() 
	{
		cout << "I am three wheeler" << endl;
	}
};

class FourWheeler : public Vehicle
{
public:
	void printVehicle() 
	{
		cout << "I am four wheeler" << endl;
	}
};

// Factory method to create objects of different types. 
// Change is required only in this function to create a new object type 
Vehicle* Vehicle::Create(VehicleType type) 
{
	if (type == VT_TwoWheeler)
		return new TwoWheeler();
	else if (type == VT_ThreeWheeler)
		return new ThreeWheeler();
	else if (type == VT_FourWheeler)
		return new FourWheeler();
	else return NULL;
}

// Client class 
class Client
{
public:

	// Client doesn't explicitly create objects 
	// but passes type to factory method "Create()" 
	Client()
	{
		VehicleType type = VT_ThreeWheeler;
		pVehicle = Vehicle::Create(type);
	}
	~Client() 
	{
		if (pVehicle)
		{
			delete[] pVehicle;
			pVehicle = NULL;
		}
	}
	Vehicle* getVehicle()
	{
		return pVehicle;
	}

private:
	Vehicle *pVehicle;
};

// Driver program 
int main() 
{
	Client *pClient = new Client();

	Vehicle * pVehicle = pClient->getVehicle();

	pVehicle->printVehicle();
	return 0;
}
#endif
#if 0
class Stooge
{
public:
	// Factory Method
	virtual void slap_stick() = 0;
	static Stooge *make_stooge(int choice);
};

class Larry : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Larry: poke eyes\n";
	}
};

class Moe : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Moe: slap head\n";
	}
};

class Curly : public Stooge
{
public:
	void slap_stick()
	{
		cout << "Curly: suffer abuse\n";
	}
};

Stooge *Stooge::make_stooge(int choice)
{
	if (choice == 1)
		return new Larry;
	else if (choice == 2)
		return new Moe;
	else
		return new Curly;
}

int main()
{
	std::vector<Stooge*> roles;
	int choice;
	while (true)
	{
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;

		roles.push_back(Stooge::make_stooge(choice));
	}

	for (int i = 0; i < roles.size(); i++)
		roles[i]->slap_stick();

	for (int i = 0; i < roles.size(); i++)
		delete roles[i];

	return 0;
}
#endif