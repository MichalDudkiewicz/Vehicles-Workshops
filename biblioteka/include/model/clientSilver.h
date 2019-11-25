#ifndef clientSilverClass
#define clientSilverClass
#include "model/clientType.h"

class ClientSilver : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};

#endif