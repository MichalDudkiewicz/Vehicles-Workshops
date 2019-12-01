#ifndef clientRepositoryClass
#define clientRepositoryClass
#include <list>
#include <string>
#include <memory>
#include "model/repository.h"

using namespace std;
class Client;
class Rent;
class ClientType;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;

class ClientRepository : public Repository<Client>
{
private:
    list<ClientPtr> allClients{};
public:
    void create(const ClientPtr&) override;
    void remove(const ClientPtr&) override;
    void remove(const unsigned int&);
    void changeType(const ClientPtr&, const ClientTypePtr&);
    string getAll() const override;
    const ClientPtr& search(const unsigned int&) const override;
    const list<ClientPtr>& getRepository() const override;
};

#endif