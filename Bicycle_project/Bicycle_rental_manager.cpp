#include "Bicycle_rental_manager.h"

using namespace std;


Bicycle_rental_manager::Bicycle_rental_manager(vector<string> bicycle_description)
{
	for (int i = 0; i < bicycle_description.size(); i++)
	{
		bicycles.push_back(new Bicycle(bicycle_description[i]));
	}
}


Bicycle_rental_manager::~Bicycle_rental_manager()
{
	for (int i = 0; i < bicycles.size(); i++)
	{
		delete bicycles[i];
	}

	bicycles.clear();
}


Bicycle Bicycle_rental_manager::add_bicycle(string bicycle_description)
{
	mutex.lock();

	Bicycle bicycle(bicycle_description);
	cout << "Number of bikes before adding is: " << bicycles.size() << endl;
	bicycles.push_back(new Bicycle(bicycle_description));
	cout << "We bought a new bike described by: " << bicycle.get_description() << endl;
	cout << "Number of bikes after adding is: " << bicycles.size() << endl;
	
	mutex.unlock();

	return bicycle;
}


Bicycle* Bicycle_rental_manager::rent_bicycle(int client_id)
{
	mutex.lock();
	Bicycle* rented_bike = nullptr;

	if (bicycles.size() > 0)
	{
		cout << "Client # " << client_id << " has popped the bike!" << endl;
		rented_bike = bicycles[bicycles.size() - 1];

		bicycles.pop_back();
		cout << "Client # " << client_id << " rented a bike described by: " << rented_bike->get_description() << endl;
		cout << "After renting by client # " << client_id << ", number of bicycles is: " << bicycles.size() << endl;
	}

	mutex.unlock();

	return rented_bike;
}


void Bicycle_rental_manager::return_bicycle(Bicycle* returned_bicycle, int client_id)
{
	mutex.lock();

	bicycles.push_back(returned_bicycle);
	cout << "After returning by client # " << client_id << ", number of bicycles is: " << bicycles.size() << endl;

	mutex.unlock();
}
