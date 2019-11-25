#ifndef rentExceptionClass
#define rentExceptionClass
#include <stdexcept>

using namespace std;

class RentException : public logic_error
{
public:
    explicit RentException(const string&);
    static const string exceptionClientNullPtr;
    static const string exceptionVehicleNullPtr;
    static const string exceptionDays;
    static const string exceptionRentalPeriod;
};

#endif
