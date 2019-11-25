#include "model/vehicleManager.h"
#include "model/rent.h"
#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include "model/vehicleRepositoryException.h"


VehicleManager::VehicleManager()
        : currentVehicles(new VehicleRepository), archiveVehicles(new VehicleRepository)
{
}

void VehicleManager::addVehicle(const VehiclePtr &vehicle)
{
    for(const auto& v : currentVehicles->vehicleRepository)
    {
        if(vehicle -> getRegistrationNumber() == v->getRegistrationNumber())
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    for(const auto& v : archiveVehicles->vehicleRepository)
    {
        if(vehicle->getRegistrationNumber() == v->getRegistrationNumber())
        {
            archiveVehicles -> removeVehicle(vehicle);
            break;
        }
    }
    currentVehicles -> addVehicle(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle)
{
    currentVehicles -> removeVehicle(vehicle);
    archiveVehicles -> addVehicle(vehicle);
}

int VehicleManager::getNumberOfCurrentVehicles() const
{
    return currentVehicles -> vehicleRepository.size();
}

int VehicleManager::getNumberOfArchVehicles() const
{
    return archiveVehicles -> vehicleRepository.size();
}

