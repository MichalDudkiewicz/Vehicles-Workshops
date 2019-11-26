#ifndef rentClass
#define rentClass
#include <string>
#include <memory>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/uuid.hpp>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::uuids;
class Client;
class Vehicle;
class RentsManager;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Vehicle> VehiclePtr;

class Rent
{
private:
    uuid ID;
    local_date_time *rentDateTime;
    local_date_time *endDateTime;
    float totalPrice;
    VehiclePtr vehicle;
    ClientPtr client;
    int rentalLength;
public:
    Rent(const ClientPtr&, const VehiclePtr&, int=0);
    Rent(const Rent&);
    Rent& operator= (const Rent&) = default;
    ~Rent();
    string rentInfo() const;
    void endRent();
    int getPeriod() const;
    const float& getPrice() const;
    const ClientPtr& getClient() const;
    const local_date_time& getRentDate() const;
    const local_date_time& getEndDate() const;
    const int& getRentalLength() const;
    int getTotalPrice() const;
    const uuid& getID() const;
    const string& getRegistrationNumber() const;
};

#endif