#ifndef clientTypeClass
#define clientTypeClass
#include <string>

using namespace std;

class ClientType
{
public:
    virtual float discount()=0;
    virtual int vehicleLimit()=0;
    virtual ~ClientType()= default;
    virtual string getType()=0;
};

#endif