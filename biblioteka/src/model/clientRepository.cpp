#include "model/clientRepository.h"
#include <sstream>
#include "model/clientType.h"
#include "model/client.h"
#include "model/clientRepositoryException.h"
#include <algorithm>

using namespace std;

void ClientRepository::create(const ClientPtr &client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    for(const auto &c : allClients)
    {
        if(*client == *c)
        {
            throw ClientRepositoryException(ClientRepositoryException::exceptionClientExist);
        }
    }
    allClients.push_back(client);
}

void ClientRepository::remove(const ClientPtr &client)
{
    if (client == nullptr) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNullPtr);
    if (find_if(allClients.begin(), allClients.end(), FindByPersonalID((*client).getPersonalID())) == allClients.end())
        throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    allClients.remove(client);
}

void ClientRepository::remove(const unsigned int &index)
{
    unsigned int counter = 1;
    if (index > allClients.size()) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    for (auto& client : allClients)
    {
        if(counter == index)
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

string ClientRepository::getAll() const
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

const list<ClientPtr>& ClientRepository::getRepository() const
{
    return allClients;
}

const ClientPtr& ClientRepository::search(const unsigned int& index) const
{
    if (index > allClients.size()) throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
    unsigned int i = 1;
    string chain;
    for(const auto& c : allClients)
    {
        if(i == index)
        {
            return c;
        }
        i ++;
    }
    throw ClientRepositoryException(ClientRepositoryException::exceptionClientNotExist);
}