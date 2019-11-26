#ifndef clientClass
#define clientClass
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;
class Rent;
class ClientType;
class Address;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<ClientType> ClientTypePtr;
typedef shared_ptr<Address> AddressPtr;

class Client
{
private:
    string firstName;
    string lastName;
    string personalID;
    AddressPtr address;
    AddressPtr registeredAddress;
    ClientTypePtr clientType;
    vector<RentPtr> archivedRents{};
    list<RentPtr> currentRents{};
    int balance;
public:
    Client(const string&, const string&, const string&, const string&, const int&, const string&, const int&);
    Client(const Client &c);
    string clientInfo() const;
    void setLastName(const string&);
    void setAddress(const string&, const int&);
    void setRegisteredAddress(const string&, const int&);
    const string& getPersonalID() const;
    string getAddress() const;
    string getRegisteredAddress() const;
    void archiveRent(const RentPtr&);
    string allRents() const;
    string getFullName() const;
    void setClientType(const ClientTypePtr&);
    float getDiscount() const;
    int getVehicleLimit() const;
    int getNumberOfRents() const;
    void addCurrentRent(const RentPtr&);
    void removeArchiveRent(const RentPtr&);
    const int& getBalance() const;
    void setBalance(const RentPtr&);
    int getNumberOfArchRents() const;
    const vector<RentPtr>& getAllClientRents() const;
    const ClientTypePtr& getClientType() const;
};

#endif