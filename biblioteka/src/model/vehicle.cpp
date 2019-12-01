#include "model/vehicle.h"
#include "model/vehicleException.h"


Vehicle::Vehicle(const int& price_, const string& registrationNumber_): price(price_), registrationNumber(registrationNumber_)
{
    if (price <= 0) throw VehicleException(VehicleException::exceptionPrice);
    if (registrationNumber.empty()) throw VehicleException(VehicleException::exceptionRegistration);
}

string Vehicle::vehicleInfo() const
{
    string chain;
    chain = "Registration number :" + registrationNumber;
    return chain;
}

int Vehicle::getPrice() const
{
    return price;
}
const string& Vehicle::getRegistrationNumber() const
{
    return registrationNumber;
}

bool Vehicle::operator== (const Vehicle &v) const
{
    return v.registrationNumber == registrationNumber;
}

FindByRegistration::FindByRegistration(const string &n) : registrationNumber(n)
{}

bool FindByRegistration::operator()(const VehiclePtr &v) const
{
    return (*v).getRegistrationNumber() == registrationNumber;
}