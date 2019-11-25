#ifndef clientBronzeClass
#define clientBronzeClass
#include "model/clientType.h"

class ClientBronze : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};

#endif