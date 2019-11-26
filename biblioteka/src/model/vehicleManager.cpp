#include "model/vehicleManager.h"
#include "model/rent.h"
#include "model/vehicleRepository.h"
#include "model/vehicle.h"
#include "model/vehicleRepositoryException.h"


VehicleManager::VehicleManager()
        : currentVehicles(new VehicleRepository), archiveVehicles(new VehicleRepository)
{}

void VehicleManager::addVehicle(const VehiclePtr &vehicle)
{
    for(const auto& v : currentVehicles->getVehicleRepository())
    {
        if(vehicle -> getRegistrationNumber() == v->getRegistrationNumber())
        {
            throw VehicleRepositoryException(VehicleRepositoryException::exceptionVehicleExists);
        }
    }
    for(const auto& v : archiveVehicles->getVehicleRepository())
    {
        if(vehicle->getRegistrationNumber() == v->getRegistrationNumber())
        {
            archiveVehicles->remove(vehicle);
            break;
        }
    }
    currentVehicles->create(vehicle);
}

void VehicleManager::removeVehicle(const VehiclePtr &vehicle)
{
    currentVehicles->remove(vehicle);
    archiveVehicles->create(vehicle);
}

int VehicleManager::getNumberOfCurrentVehicles() const
{
    return currentVehicles -> getVehicleRepository().size();
}

int VehicleManager::getNumberOfArchVehicles() const
{
    return archiveVehicles -> getVehicleRepository().size();
}

