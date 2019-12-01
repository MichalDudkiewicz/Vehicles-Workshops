#ifndef vehicleRepositoryClass
#define vehicleRepositoryClass
#include <string>
#include <list>
#include <memory>
#include "model/repository.h"

using namespace std;
class Vehicle;
class VehicleManager;
typedef shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository : Repository<Vehicle>
{
private:
    list<VehiclePtr> vehicleRepository{};
public:
    void create(const VehiclePtr&) override;
    void remove(const VehiclePtr&) override;
    const VehiclePtr& search(const unsigned int&) const override;
    string getAll() const override;
    const list<VehiclePtr>& getRepository() const override;
};

#endif