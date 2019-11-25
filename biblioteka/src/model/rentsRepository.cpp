#include "model/rentsRepository.h"
#include <sstream>
#include "model/rent.h"
#include "model/rentsRepositoryException.h"
#include <algorithm>
#include <boost/uuid/uuid.hpp>

void RentsRepository::createRent(const RentPtr &r)
{
    if (r == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    for(const auto &rent : rentRepositoryList)
    {
        if(r -> getID() == rent -> getID())
        {
            throw RentsRepositoryException(RentsRepositoryException::exceptionRentExist);
        }
    }
    rentRepositoryList.push_back(r);
}

void RentsRepository::removeRent(const RentPtr &r)
{
    if (r == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    bool found = (find(rentRepositoryList.begin(), rentRepositoryList.end(), r) != rentRepositoryList.end());
    if (!found) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNotExist);
    rentRepositoryList.remove(r);
}

string RentsRepository::rentReport() const
{
    ostringstream chain;
    for(const auto& rent : rentRepositoryList)
    {
        chain<<rent->rentInfo();
    }
    return chain.str();
}

int RentsRepository::getNumberOfRents() const
{
    return rentRepositoryList.size();
}


