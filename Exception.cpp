#include"stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <exception> // std::exception
using namespace std;

#if 0
struct ooops : std::exception
{
	const char* what() const noexcept 
	{ 
		return "Ooops!\n"; 
	}
};

int main()
{
	try 
	{
	//	throw ooops(); or following

		ooops e;

		throw e;
	}

	catch (std::exception& ex) 
	{
		std::cout << ex.what();
	}

	return 0;
}
#endif

#if 0
/* Define the exception here */
class BadLengthException :public exception
{
	string exce;

public:
	BadLengthException(int n)
	{
		exce = to_string(n);
	}

	virtual const char* what() const noexcept
	{
		return exce.c_str();
	}

};

bool checkUsername(string username) 
{
	bool isValid = true;
	int n = username.length();

	if (n < 5)
	{
		BadLengthException e(n);

		throw e;
		//throw BadLengthException e(n);
	}

	for (int i = 0; i < n - 1; i++) 
	{
		if (username[i] == 'w' && username[i + 1] == 'w')
		{
			isValid = false;
		}
	}

	return isValid;
}

int main() 
{
	int T; 
	cin >> T;

	while (T--)
	{
		string username;
		cin >> username;

		try
		{
			bool isValid = checkUsername(username);
			if (isValid)
			{
				cout << "Valid" << '\n';
			}
			else
			{
				cout << "Invalid" << '\n';
			}
		}

		catch (BadLengthException e)
		{
			cout << "Too short: " << e.what() << '\n';
		}

	}
	
	return 0;
}
#endif