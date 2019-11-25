#ifndef clientGoldClass
#define clientGoldClass
#include "model/clientType.h"

class ClientGold : public ClientType
{
public:
    float discount() override;
    int vehicleLimit() override;
    string getType() override;
};

#endif