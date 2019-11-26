#ifndef vehicleRepositoryClass
#define vehicleRepositoryClass
#include <string>
#include <list>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Vehicle;
class VehicleManager;
typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository
{
private:
    list<VehiclePtr> vehicleRepository{};
public:
    void addVehicle(const VehiclePtr&);
    void removeVehicle(const VehiclePtr&);
    string getVehicle(const unsigned int& index) const;
    string vehicleRaport() const;
    const list<VehiclePtr>& getVehicleRepository() const;
};

#endif