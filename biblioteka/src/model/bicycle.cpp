#include "model/bicycle.h"


Bicycle::Bicycle(const int& price_, const string& registrationNumber_)
: Vehicle(price_, registrationNumber_)
{
}

string Bicycle::vehicleInfo() const
{
    string chain;
    chain = "BICYCLE: " + Vehicle::vehicleInfo() + ". Price: " + to_string(getPrice());
    return chain;
}

int Bicycle::getPrice() const
{
    return Vehicle::getPrice();
}

