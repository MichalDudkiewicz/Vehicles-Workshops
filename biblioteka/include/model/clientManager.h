#ifndef clientManagerClass
#define clientManagerClass
#include <memory>
#include <vector>
#include <string>

using namespace std;
class Client;
class ClientRepository;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<ClientRepository> ClientRepoPtr;

class ClientManager{
    ClientRepoPtr currentClients;
    ClientRepoPtr archiveClients;
public:
    ClientManager();
    void addClient(const ClientPtr&);
    void removeClient(const ClientPtr&);
    int getNumberOfArchClients() const;
    int getNumberOfCurrentClients() const;
};

#endif