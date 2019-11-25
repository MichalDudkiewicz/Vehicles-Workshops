#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include <sstream>
#include <algorithm>
#include "model/vehicleRepositoryException.h"


void VehicleRepository::addVehicle(const VehiclePtr &v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    for(const auto &vehicle : vehicleRepository)
    {
        if(vehicle -> getRegistrationNumber() == v -> getRegistrationNumber())
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    vehicleRepository.push_back(v);
}

void VehicleRepository::removeVehicle(const VehiclePtr &v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    bool found = (find(vehicleRepository.begin(), vehicleRepository.end(), v) != vehicleRepository.end());
    if (!found) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    vehicleRepository.remove(v);
}

string VehicleRepository::getVehicle(const unsigned int &index) const
{
    if (index > vehicleRepository.size()) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    unsigned int i = 1;
    string chain;
    for(const auto& v : vehicleRepository)
    {
        if(i == index)
        {
            chain = v->vehicleInfo();
        }
        i ++;
    }
    return chain;
}

string VehicleRepository::vehicleRaport() const
{
    ostringstream chain;
    unsigned int i = 1;
    for(const auto& v : vehicleRepository)
    {
        chain<<i<< "- ";
        chain<<v->vehicleInfo()<<endl;
        i++;
    }
    return chain.str();
}

