#include "model/car.h"


Car::Car(const int& price, const string& registrationNumber, const float& engineDisplacement, const char& segment_)
: MotorVehicle(price, registrationNumber, engineDisplacement), segment(segment_)
{
}

string Car::vehicleInfo() const
{
    string chain;
    chain = "CAR: " + MotorVehicle::vehicleInfo() + ". Price: " + to_string(getPrice()) + ". Car class: " + segment;
    return chain;
}

double Car::getWage() const
{
    float wage = 0;
    if(segment == 'A')
    {
        wage = 1;
    }
    else if(segment == 'B')
    {
        wage = 1.1;
    }
    else if(segment == 'C')
    {
        wage = 1.2;
    }
    else if(segment == 'D')
    {
        wage = 1.3;
    }
    else if(segment == 'E')
    {
        wage = 1.5;
    }
    return wage;
}

int Car::getPrice() const
{
    return MotorVehicle::getPrice() * getWage();
}
