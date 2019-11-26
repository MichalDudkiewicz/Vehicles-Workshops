#include "model/clientRepository.h"
#include <sstream>
#include "model/clientType.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"
#include <algorithm>

using namespace std;

void ClientRepository::addClient(const ClientPtr &client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    for(const auto &c : allClients)
    {
        if(client -> getPersonalID() == c -> getPersonalID())
        {
            throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
        }
    }
    allClients.push_back(client);
}

void ClientRepository::removeClient(const ClientPtr &client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    bool found = (find(allClients.begin(), allClients.end(), client) != allClients.end());
    if (!found) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    allClients.remove(client);
}

void ClientRepository::removeClient(const unsigned int &i)
{
    unsigned int counter = 1;
    if (i > allClients.size()) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    for (auto& client : allClients)
    {
        if(counter == i)
        {
            allClients.remove(client);
            break;
        }
    }
}

void ClientRepository::changeType(const ClientPtr &clientToChange, const ClientTypePtr &newType)
{
    if (clientToChange == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    (*clientToChange).setClientType(newType);
}

string ClientRepository::clientRepositoryInfo() const
{
    ostringstream chain;
    unsigned int i = 1;
    for (const auto& client : allClients)
    {
        chain << i << ". " << client->getFullName();
        if (client->getClientType() != nullptr)
        {
            chain << " [" << client->getClientType()->getType() << "]" << endl;
        }
        else
        {
            chain << endl;
        }
        i ++;
    }
    return chain.str();
}

unsigned int ClientRepository::getNumberOfClients() const
{
    return allClients.size();
}

const list<ClientPtr>& ClientRepository::getAllClients() const
{
    return allClients;
}