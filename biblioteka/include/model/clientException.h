#ifndef clientExceptionClass
#define clientExceptionClass
#include <stdexcept>

using namespace std;

class ClientException : public logic_error
{
public:
    explicit ClientException(const string&);
    static const string exceptionFirstName;
    static const string exceptionLastName;
    static const string exceptionPersonalID;
    static const string exceptionAddress;
    static const string exceptionRegisteredAddress;
};

#endif
