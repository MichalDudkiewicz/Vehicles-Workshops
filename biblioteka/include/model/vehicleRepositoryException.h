#ifndef vehicleRepositoryExceptionClass
#define vehicleRepositoryExceptionClass
#include <stdexcept>

using namespace std;

class VehicleRepositoryException : public logic_error
{
public:
    explicit VehicleRepositoryException(const string&);
    static const string exceptionVehicleNotFound;
    static const string exceptionVehicleNullPtr;
    static const string exceptionVehicleExists;
};

#endif
