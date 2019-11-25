#ifndef clientRepositoryExceptionClass
#define clientRepositoryExceptionClass
#include <stdexcept>

using namespace std;

class ClientRepositoryException : public logic_error
{
public:
    explicit ClientRepositoryException(const string&);
    static const string exceptionClientNotExist;
    static const string exceptionClientNullPtr;
    static const string exceptionClientExist;
};

#endif
