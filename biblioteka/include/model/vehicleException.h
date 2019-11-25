#ifndef vehicleExceptionClass
#define vehicleExceptionClass
#include <stdexcept>

using namespace std;

class VehicleException : public logic_error
{
public:
    explicit VehicleException(const string&);
    static const string exceptionPrice;
    static const string exceptionRegistration;
};

#endif
