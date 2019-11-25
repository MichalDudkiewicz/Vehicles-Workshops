#ifndef mopeClass
#define mopeClass
#include <string>
#include "model/motorVehicle.h"

using namespace std;

class Moped : public MotorVehicle
{
public:
    Moped(const int&, const string&, const float&);
    string vehicleInfo() const override;
};

#endif