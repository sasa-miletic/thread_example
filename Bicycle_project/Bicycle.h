#pragma once
#include <iostream>
#include <string>

using namespace std;


class Bicycle
{
	string description;

public:

	Bicycle(string description);
	~Bicycle();

	string get_description();

	friend ostream& operator<<(ostream& os, Bicycle& b);
};

ostream& operator<<(ostream& os, Bicycle& b);
