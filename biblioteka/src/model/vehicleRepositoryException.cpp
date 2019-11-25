#include "model/vehicleRepositoryException.h"

VehicleRepositoryException::VehicleRepositoryException(const string& arg) : logic_error(arg)
{}

const string VehicleRepositoryException::exceptionVehicleNotFound = "THIS VEHICLE CANNOT BE FOUND IN THE REPOSITORY";
const string VehicleRepositoryException::exceptionVehicleNullPtr = "INVALID VEHICLE (NULL)";
const string VehicleRepositoryException::exceptionVehicleExists = "THIS VEHICLE ALREADY EXISTS IN THE REPOSITORY";