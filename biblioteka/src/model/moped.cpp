#include "model/moped.h"


Moped::Moped(const int& price, const string& registrationNumber, const float& engineDisplacement)
        : MotorVehicle(price, registrationNumber, engineDisplacement)
{
}

string Moped::vehicleInfo() const
{
    string chain;
    chain = "MOPED: " + MotorVehicle::vehicleInfo() + ". Price: " + to_string(getPrice());
    return chain;
}