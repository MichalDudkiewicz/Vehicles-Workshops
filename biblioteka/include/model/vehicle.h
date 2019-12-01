#ifndef vehicleClass
#define vehicleClass
#include <string>
#include <memory>

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
    bool operator== (const Vehicle&) const;
};

typedef shared_ptr<Vehicle> VehiclePtr;

struct FindByRegistration
{
    string registrationNumber;
    explicit FindByRegistration(const string&);
    bool operator()(const VehiclePtr&) const;
};

#endif