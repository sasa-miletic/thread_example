#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <ctime>

#include "Bicycle.h"
#include "Bicycle_rental_manager.h"

using namespace std;


void use_bicycle(Bicycle_rental_manager* rental_manager, int client_id)
{
    if (rental_manager == nullptr)
    {
        cout << "Nonexistent rental manager." << endl;
    }

    Bicycle* rented_bicycle = rental_manager->rent_bicycle(client_id);
    if (rented_bicycle == nullptr)
    {
        cout << "Unsuccessful renting. No free bikes. Client # " << client_id << " sleeping a bit and trying again." << endl;
        this_thread::sleep_for(chrono::seconds(3));
        rented_bicycle = rental_manager->rent_bicycle(client_id);
    }

    cout << "Client # " << client_id << ": I have a bike now!" << endl;
    srand((unsigned)time(0));
    int n = (rand() % 3) + 1;
    this_thread::sleep_for(chrono::seconds(n));

    rental_manager->return_bicycle(rented_bicycle, client_id);
    cout << "Bicycle is returned by client # " << client_id << "!!!" << endl;
}

int main()
{
    vector<string> bicycle_description;
    bicycle_description.push_back("Mirage");
    bicycle_description.push_back("Matrix");

    Bicycle_rental_manager rental_agency(bicycle_description);

    thread clients[5];
    for (int i = 0; i < 5; i++)
    {
        clients[i] = thread(use_bicycle, &rental_agency, i);
    }

    for (int i = 0; i < 5; i++)
    {
        clients[i].join();
    }

    rental_agency.add_bicycle("Tsunami");

    return 0;
}
