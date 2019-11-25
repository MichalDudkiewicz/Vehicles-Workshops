#include "model/address.h"
#include "model/addressException.h"
#include <sstream>

Address::Address(const string& street_, const int& houseNumber_)
: street(street_), houseNumber(houseNumber_)
{
    if (street.empty()) throw AddressException(AddressException::exceptionStreet);
    if (houseNumber <= 0) throw AddressException(AddressException::exceptionHouseNumber);
}

string Address::getAddress() const
{
    ostringstream chain;
    chain << street << " " << houseNumber;
    return chain.str();
}

void Address::setAddress(const string& newStreet, const int& newNumber)
{
    if (newStreet.empty()) throw AddressException(AddressException::exceptionStreet);
    street = newStreet;
    if (newNumber <= 0) throw AddressException(AddressException::exceptionHouseNumber);
    houseNumber = newNumber;
}

