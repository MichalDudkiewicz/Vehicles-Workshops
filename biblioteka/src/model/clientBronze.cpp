#include "model/clientBronze.h"

float ClientBronze::discount()
{
    return 0.1;
}

int ClientBronze::vehicleLimit()
{
    return 2;
}

string ClientBronze::getType()
{
    return "BRONZE";
}
