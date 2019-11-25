#ifndef rentsRepositoryExceptionClass
#define rentsRepositoryExceptionClass
#include <stdexcept>

using namespace std;

class RentsRepositoryException : public logic_error
{
public:
    explicit RentsRepositoryException(const string&);
    static const string exceptionRentNotExist;
    static const string exceptionRentNullPtr;
    static const string exceptionRentExist;
    static const string exceptionLimitExceeded;
    static const string exceptionVehicleRented;
};

#endif
