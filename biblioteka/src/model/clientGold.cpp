#include "model/clientGold.h"

float ClientGold::discount()
{
    return 0.3;
}

int ClientGold::vehicleLimit()
{
    return 4;
}

string ClientGold::getType()
{
    return "GOLD";
}