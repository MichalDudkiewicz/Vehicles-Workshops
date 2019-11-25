#ifndef bicycleClass
#define bicycleClass
#include <string>
#include "model/vehicle.h"

using namespace std;

class Bicycle : public Vehicle
{
public:
    Bicycle(const int&, const string&);
    string vehicleInfo() const override;
    int getPrice() const override;
};

#endif