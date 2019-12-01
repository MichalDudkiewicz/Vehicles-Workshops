#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include <sstream>
#include <algorithm>
#include "model/vehicleRepositoryException.h"


void VehicleRepository::create(const VehiclePtr &v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    for(const auto &vehicle : vehicleRepository)
    {
        if(*vehicle == *v)
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    vehicleRepository.push_back(v);
}

void VehicleRepository::remove(const VehiclePtr &v)
{
    if (v == nullptr) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNullPtr);
    if (find_if(vehicleRepository.begin(), vehicleRepository.end(), FindByRegistration((*v).getRegistrationNumber()))  == vehicleRepository.end())
        throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    vehicleRepository.remove(v);
}

const VehiclePtr& VehicleRepository::search(const unsigned int &index) const
{
    if (index > vehicleRepository.size()) throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
    unsigned int i = 1;
    string chain;
    for(const auto& v : vehicleRepository)
    {
        if(i == index)
        {
            return v;
        }
        i ++;
    }
    throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleNotFound);
}

string VehicleRepository::getAll() const
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

const list<VehiclePtr>& VehicleRepository::getRepository() const
{
    return vehicleRepository;
}
