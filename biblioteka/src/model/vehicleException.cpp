#include "model/vehicleException.h"

VehicleException::VehicleException(const string& arg) : logic_error(arg)
{
}

const string VehicleException::exceptionPrice = "INVALID PRICE";
const string VehicleException::exceptionRegistration = "INVALID REGISTRATION NUMBER";