#include "model/motorVehicle.h"


MotorVehicle::MotorVehicle(const int& price, const string& registrationNumber, const float& engineCapacity)
: Vehicle(price, registrationNumber), engineDisplacement(engineCapacity)
{
}

const float& MotorVehicle::getEngineDisplacement() const
{
    return engineDisplacement;
}

string MotorVehicle::vehicleInfo() const
{
    string chain;
    chain = Vehicle::vehicleInfo() + ". Engine displacement: " + to_string(engineDisplacement);
    return chain;
}

double MotorVehicle::getWage() const
{
    double wage = 0;
    if (engineDisplacement < 1000)
    {
        wage = 1;
    }
    else if (engineDisplacement >= 1000 and engineDisplacement < 2000)
    {
        wage = 1 + (engineDisplacement - 1000) / 1000 * 0.5;
    }
    else if (engineDisplacement >= 2000)
    {
        wage = 1.5;
    }
    return wage;
}

int MotorVehicle::getPrice() const
{
    return Vehicle::getPrice() * getWage();
}
