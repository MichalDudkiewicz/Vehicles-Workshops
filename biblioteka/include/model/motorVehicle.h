#ifndef motorVehicleClass
#define motorVehicleClass
#include <string>
#include "vehicle.h"

using namespace std;

class MotorVehicle : public Vehicle
{
private:
    float engineDisplacement;
    double getWage() const;
public:
    MotorVehicle(const int&, const string&, const float&);
    virtual ~MotorVehicle()= default;
    const float& getEngineDisplacement() const;
    string vehicleInfo() const override;
    int getPrice() const override;
};

#endif