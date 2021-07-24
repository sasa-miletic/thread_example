#pragma once
#include <mutex>
#include <vector>
#include <io.h>
#include "Bicycle.h"


class Bicycle_rental_manager
{
	vector<Bicycle*> bicycles;
	mutex mutex;

public:
	Bicycle_rental_manager(vector<string> bicycle_description);
	~Bicycle_rental_manager();

	Bicycle add_bicycle(string bicycle_description);
	Bicycle* rent_bicycle(int client_id);
	void return_bicycle(Bicycle* returned_bicycle, int client_id);
};

