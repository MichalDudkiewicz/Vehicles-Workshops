#include "model/client.h"
#include <sstream>
#include "model/address.h"
#include "model/rent.h"
#include "model/clientType.h"
#include "model/clientException.h"


Client::Client(const string& firstName_, const string& lastName_, const string& personalID_, const string& street_, const int& houseNumber_, const string& street__, const int& houseNumber__)
:firstName(firstName_), lastName(lastName_), personalID(personalID_), address(new Address(street_, houseNumber_)), registeredAddress(new Address(street__, houseNumber__)),
clientType(nullptr), balance(0)
{
    if (firstName.empty()) throw ClientException(ClientException::exceptionFirstName);
    if (lastName.empty()) throw ClientException(ClientException::exceptionLastName);
    if (personalID.empty()) throw ClientException(ClientException::exceptionPersonalID);
    if (address == nullptr or street_.empty() or houseNumber__ < 1) throw ClientException(ClientException::exceptionAddress);
    if (registeredAddress == nullptr or street__.empty() or houseNumber__ < 1) throw ClientException(ClientException::exceptionRegisteredAddress);
}

Client::Client(const Client &c)
:firstName(c.firstName), lastName(c.lastName), personalID(c.personalID), address(new Address(*c.address)), registeredAddress(new Address(*c.registeredAddress)),
 clientType(c.clientType), balance(c.balance)
{
}

string Client::clientInfo() const
{
    ostringstream chain;
    int margin = 20;
    chain << endl << "_________________________________________________" <<endl;
    chain << "Client Info:"<<endl;
    chain.width(margin); chain << left <<  "Name: ";
    chain << getFullName() <<endl;
    chain.width(margin); chain  << left << "Personal ID: ";
    chain << personalID <<endl;
    if (address != nullptr)
    {
        chain.width(margin); chain << left << "Address: ";
        chain << address->getAddress() <<endl;
    }
    if (registeredAddress != nullptr)
    {
        chain.width(20); chain << left << "Registered Address: ";
        chain << registeredAddress->getAddress() <<endl;
    }
    chain << allRents();
    return chain.str();
}

void Client::setLastName(const string& newLastName)
{
    if (newLastName.empty()) throw ClientException(ClientException::exceptionLastName);
    lastName = newLastName;
}

void Client::setAddress(const string& street, const int& number)
{
    address->setAddress(street, number);
}

void Client::setRegisteredAddress(const string& street, const int& number)
{
    registeredAddress->setAddress(street, number);
}

const string& Client::getPersonalID() const
{
    return personalID;
}

string Client::getAddress() const
{
    return address -> getAddress();
}

string Client::getRegisteredAddress() const
{
    return registeredAddress -> getAddress();
}

void Client::archiveRent(const RentPtr &r)
{
    archivedRents.push_back(r);
}

string Client::allRents() const
{
    ostringstream chain;
    for (const auto &rent : currentRents)
    {
        chain<<rent->rentInfo()<<endl;
    }
    for (const auto &rent : archivedRents)
    {
        chain<<rent->rentInfo()<<endl;
    }
    return chain.str();
}

string Client::getFullName() const
{
    return firstName + " " + lastName;
}

void Client::setClientType(const ClientTypePtr &typeOfClient)
{
    clientType = ClientTypePtr(typeOfClient);
}

float Client::getDiscount() const
{
    if (clientType == nullptr)
    {
        return 0;
    }
    return clientType->discount();
}

int Client::getVehicleLimit() const
{
    if (clientType == nullptr)
    {
        return 1;
    }
    return clientType->vehicleLimit();
}

void Client::addCurrentRent(const RentPtr &r)
{
    currentRents.push_back(r);
}

void Client::removeArchiveRent(const RentPtr &r)
{
    currentRents.remove(r);
    archiveRent(r);
    setBalance(r);
}

int Client::getNumberOfRents() const
{
    return currentRents.size();
}

const int& Client::getBalance() const
{
    return balance;
}

void Client::setBalance(const RentPtr &r)
{
    balance += r -> getTotalPrice();
}

int Client::getNumberOfArchRents() const
{
    return archivedRents.size();
}

const vector<RentPtr>& Client::getAllClientRents() const
{
    return archivedRents;
}

const ClientTypePtr& Client::getClientType() const
{
    return clientType;
}