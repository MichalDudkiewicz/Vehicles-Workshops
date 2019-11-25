#ifndef rentsManagerClass
#define rentsManagerClass
#include <memory>
#include <vector>
#include <string>

using namespace std;
class RentsRepository;
class Rent;
class Client;
class ClientRepository;
class Vehicle;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<ClientRepository> ClientRepoPtr;
typedef shared_ptr<Vehicle> VehiclePtr;

class RentsManager{
    shared_ptr<RentsRepository> currentRents;
    shared_ptr<RentsRepository> archiveRents;
    ClientRepoPtr clientRepository;
public:
    RentsManager();
    void returnVehicle(const RentPtr&);
    void rentVehicle(const RentPtr&);
    const vector<RentPtr>& getAllClientRents(const ClientPtr&) const;
    string getClientForRentedVehicle(const VehiclePtr&) const;
    int getNumberOfCurrentRents() const;
    int getNumberOfArchRents() const;
    void changeClientType(const ClientPtr&);
    int checkClientRentBalance(const ClientPtr&) const;
};

#endif