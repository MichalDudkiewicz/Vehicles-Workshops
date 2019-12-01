#include "model/clientManager.h"
#include "model/clientGold.h"
#include "model/rent.h"
#include "model/clientRepository.h"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"


ClientManager::ClientManager()
        : currentClients(new ClientRepository), archiveClients(new ClientRepository)
{}

void ClientManager::addClient(const ClientPtr &client)
{
    for(const auto& c : currentClients->getRepository())
    {
        if(*client == *c)
        {
            throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
        }
    }
    for(const auto& c : archiveClients->getRepository())
    {
        if(*client == *c)
        {
            archiveClients->remove(client);
            break;
        }
    }
    currentClients->create(client);
}

void ClientManager::removeClient(const ClientPtr &client)
{
    currentClients->remove(client);
    archiveClients->create(client);
}

int ClientManager::getNumberOfCurrentClients() const
{
    return currentClients->getRepository().size();
}

int ClientManager::getNumberOfArchClients() const
{
    return archiveClients->getRepository().size();
}

