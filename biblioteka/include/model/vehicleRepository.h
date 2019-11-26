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
    void create(const VehiclePtr&);
    void remove(const VehiclePtr&);
    string search(const unsigned int& index) const;
    string getAll() const;
    const list<VehiclePtr>& getVehicleRepository() const;
};

#endif