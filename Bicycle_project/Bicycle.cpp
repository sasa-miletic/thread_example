#include "Bicycle.h"


Bicycle::Bicycle(string description)
{
	this->description = description;
}


Bicycle::~Bicycle()
{

}


string Bicycle::get_description()
{
	return description;
}

ostream& operator<<(ostream& os, Bicycle& b)
{
	os << "Bicycle: " << b.description; 
	return os;
}
