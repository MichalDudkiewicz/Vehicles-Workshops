#include "model/rent.h"
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp> // generators
#include "boost/date_time/local_time/local_time.hpp"
#include "model/vehicle.h"
#include "model/client.h"
#include "model/rentException.h"

using namespace boost::gregorian;

static time_zone_ptr timeZone(new posix_time_zone("CET+0"));

Rent::Rent(const ClientPtr &klient, const VehiclePtr &pojazd, int minusNumberOfDays)
: ID(random_generator()()), rentDateTime(new local_date_time(second_clock::local_time(), timeZone)), endDateTime(nullptr), totalPrice(0), vehicle(pojazd), client(klient)
{
    if (minusNumberOfDays > 0) *rentDateTime -= days(minusNumberOfDays);
    if (client == nullptr) throw RentException(RentException::exceptionClientNullPtr);
    if (vehicle == nullptr) throw RentException(RentException::exceptionVehicleNullPtr);
    if (minusNumberOfDays < 0) throw RentException(RentException::exceptionDays);
}

Rent::Rent(const Rent &r)
:ID(r.ID), rentDateTime(new local_date_time(*r.rentDateTime)),
endDateTime(new local_date_time(*r.endDateTime)), totalPrice(r.totalPrice), vehicle(new Vehicle(*r.vehicle)), client(new Client(*r.client))
{
}

Rent::~Rent()
{
    delete rentDateTime;
    delete endDateTime;
}

void Rent::endRent()
{
    ptime lt(second_clock::local_time());
    endDateTime = new local_date_time(lt, timeZone);
    if (*endDateTime < *rentDateTime) throw RentException(RentException::exceptionRentalPeriod);
    totalPrice =  ((getPeriod() + 1) * vehicle -> getPrice()) * (1 - client -> getDiscount());
}

int Rent::getPeriod() const
{
    int daysOfRental;
    ptime lt(second_clock::local_time());
    local_date_time *nowTime = new local_date_time(lt, timeZone);
    time_duration period = local_time_period(*rentDateTime, *nowTime).length();
    daysOfRental = period.hours()/24;
    return daysOfRental;
}

string Rent::rentInfo() const
{
    ostringstream chain;
    int margin = 20;
    chain << endl << "_________________________________________________" <<endl;
    chain << "Rental info:" <<endl;
    chain.width(margin); chain << left << "UUID: ";
    chain << ID << endl;
    chain.width(margin); chain << left << "Rental Date: ";
    chain << (*rentDateTime).local_time()<<endl;
    if (endDateTime != nullptr)
    {
        chain.width(margin); chain << left << "End of rental: ";
        chain << (*endDateTime).local_time()<<endl;
    }
    chain.width(margin); chain << left <<  "Period: ";
    chain << getPeriod() <<endl;
    chain.width(margin); chain << left << "Client: ";
    chain << client->getFullName()<<endl;
    chain.width(margin); chain << left << "Vehicle: ";
    chain << vehicle->getRegistrationNumber()<<endl;
    return chain.str();
}

const int& Rent::getTotalPrice() const
{
    return totalPrice;
}

const ClientPtr& Rent::getClient() const
{
    return client;
}

const local_date_time& Rent::getRentDate() const
{
    return *rentDateTime;
}

const local_date_time& Rent::getEndDate() const
{
    return *endDateTime;
}

const uuid& Rent::getID() const
{
    return ID;
}

const string& Rent::getRegistrationNumber() const
{
    return vehicle -> getRegistrationNumber();
}

bool Rent::operator== (const Rent &r) const
{
    return r.ID == ID;
}

FindByID::FindByID(const uuid &id) : ID(id)
{}

bool FindByID::operator()(const RentPtr &r) const
{
    return (*r).getID() == ID;
}