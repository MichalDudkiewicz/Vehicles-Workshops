#ifndef addressExceptionClass
#define addressExceptionClass
#include <stdexcept>

using namespace std;

class AddressException : public logic_error
{
public:
    explicit AddressException(const string&);
    static const string exceptionStreet;
    static const string exceptionHouseNumber;
};

#endif
