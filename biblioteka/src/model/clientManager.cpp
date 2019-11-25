#include "model/clientManager.h"
#include "model/clientGold.h"
#include "model/rent.h"
#include "model/clientRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"


ClientManager::ClientManager()
        : currentClients(new ClientRepository), archiveClients(new ClientRepository)
{
}

void ClientManager::addClient(const ClientPtr &client)
{
    for(const auto& c : currentClients->allClients)
    {
        if(client->getPersonalID() == c->getPersonalID())
        {
            throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
        }
    }
    for(const auto& c : archiveClients->allClients)
    {
        if(client->getPersonalID() == c->getPersonalID())
        {
            archiveClients -> removeClient(client);
            break;
        }
    }
    currentClients -> addClient(client);
}

void ClientManager::removeClient(const ClientPtr &client)
{
    currentClients -> removeClient(client);
    archiveClients -> addClient(client);
}

int ClientManager::getNumberOfCurrentClients() const
{
    return currentClients -> allClients.size();
}

int ClientManager::getNumberOfArchClients() const
{
    return archiveClients -> allClients.size();
}

