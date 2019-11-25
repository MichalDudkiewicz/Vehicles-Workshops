#ifndef vehicleClass
#define vehicleClass
#include <string>

using namespace std;

class Vehicle
{
private:
    int price;
    string registrationNumber;
public:
    Vehicle(const int&, const string&);
    virtual ~Vehicle()= default;
    virtual string vehicleInfo() const;
    virtual int getPrice() const;
    const string& getRegistrationNumber() const;
};

#endif