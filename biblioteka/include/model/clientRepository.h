#ifndef clientRepositoryClass
#define clientRepositoryClass
#include <list>
#include <string>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Client;
class Rent;
class ClientType;
class ClientManager;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;

class ClientRepository
{
private:
    list<ClientPtr> allClients{};
    friend class ClientManager;
public:
    void addClient(const ClientPtr&);
    void removeClient(const ClientPtr&);
    void removeClient(const unsigned int&);
    void changeType(const ClientPtr&, const ClientTypePtr&);
    string clientRepositoryInfo() const;
    unsigned int getNumberOfClients() const;
};

#endif