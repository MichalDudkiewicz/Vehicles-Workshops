#include "model/clientSilver.h"

float ClientSilver::discount()
{
    return 0.2;
}

int ClientSilver::vehicleLimit()
{
    return 3;
}

string ClientSilver::getType()
{
    return "SILVER";
}