#include "model/rentsManager.h"
#include "model/clientGold.h"
#include "model/clientBronze.h"
#include "model/clientSilver.h"
#include "model/rent.h"
#include "model/clientRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/rentsRepository.h"
#include "model/rentsRepositoryException.h"


RentsManager::RentsManager()
: currentRents(new RentsRepository), archiveRents(new RentsRepository), clientRepository(new ClientRepository)
{
}

void RentsManager::rentVehicle(const RentPtr &r)
{
    bool found = (find(currentRents -> getRentRepository().begin(), currentRents -> getRentRepository().end(), r) != currentRents -> getRentRepository().end());
    if (found) throw RentsRepositoryException(RentsRepositoryException::exceptionVehicleRented);
    for(const auto& rent : currentRents->getRentRepository())
    {
        if(r->getRegistrationNumber() == rent->getRegistrationNumber())
        {
            throw RentsRepositoryException(RentsRepositoryException::exceptionVehicleRented);
        }
    }
    if(r -> getClient() -> getNumberOfRents() < r -> getClient() -> getVehicleLimit())
    {
        currentRents -> createRent(r);
        r -> getClient() -> addCurrentRent(r);
    }
    else
    {
        throw RentsRepositoryException(RentsRepositoryException::exceptionLimitExceeded);
    }
}

void RentsManager::returnVehicle(const RentPtr &r)
{
    r -> getClient() -> removeArchiveRent(r);
    r -> endRent();
    currentRents -> removeRent(r);
    archiveRents -> createRent(r);
    changeClientType(r -> getClient());
}

string RentsManager::getClientForRentedVehicle(const VehiclePtr &v) const
{
    string clientInfo;
    for(const auto& rent : currentRents->getRentRepository())
    {
        if(rent->getRegistrationNumber() == v -> getRegistrationNumber())
        {
            clientInfo = rent -> getClient() -> clientInfo();
            break;
        }
    }
    return clientInfo;
}

int RentsManager::getNumberOfCurrentRents() const
{
    return currentRents -> getRentRepository().size();
}

int RentsManager::getNumberOfArchRents() const
{
    return archiveRents -> getRentRepository().size();
}

void RentsManager::changeClientType(const ClientPtr &client)
{
    if(client -> getDiscount() != 0.3)
    {
        int b = checkClientRentBalance(client);
        if (b >= 1000 and b < 3000)
        {
            ClientTypePtr bronze = make_shared<ClientBronze>();
            clientRepository -> changeType(client, bronze);
        }
        else if (b >= 3000 and b < 10000)
        {
            ClientTypePtr silver = make_shared<ClientSilver>();
            clientRepository -> changeType(client, silver);
        }
        else if (b >= 10000)
        {
            ClientTypePtr gold = make_shared<ClientGold>();
            clientRepository -> changeType(client, gold);
        }
    }
}

int RentsManager::checkClientRentBalance(const ClientPtr &client) const
{
    return client -> getBalance();
}

const vector<RentPtr>& RentsManager::getAllClientRents(const ClientPtr &client) const
{
    return client -> getAllClientRents();
}
