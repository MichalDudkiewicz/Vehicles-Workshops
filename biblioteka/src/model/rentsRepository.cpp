#include "model/rentsRepository.h"
#include "model/rent.h"
#include "model/rentsRepositoryException.h"
#include <algorithm>

void RentsRepository::create(const RentPtr &r)
{
    if (r == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    for(const auto &rent : rentRepositoryList)
    {
        if(*rent == *r)
        {
            throw RentsRepositoryException(RentsRepositoryException::exceptionRentExist);
        }
    }
    rentRepositoryList.push_back(r);
}

void RentsRepository::remove(const RentPtr &rent)
{
    if (rent == nullptr) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNullPtr);
    if (find_if(rentRepositoryList.begin(), rentRepositoryList.end(), FindByID((*rent).getID())) == rentRepositoryList.end())
        throw RentsRepositoryException(RentsRepositoryException::exceptionRentNotExist);
    rentRepositoryList.remove(rent);
}

string RentsRepository::getAll() const
{
    ostringstream chain;
    for(const auto& rent : rentRepositoryList)
    {
        chain<<rent->rentInfo();
    }
    return chain.str();
}

const list<RentPtr>& RentsRepository::getRepository() const
{
    return rentRepositoryList;
}

const RentPtr& RentsRepository::search(const unsigned int& index) const
{
    if (index > rentRepositoryList.size()) throw RentsRepositoryException(RentsRepositoryException::exceptionRentNotExist);
    unsigned int i = 1;
    string chain;
    for(const auto& c : rentRepositoryList)
    {
        if(i == index)
        {
            return c;
        }
        i ++;
    }
    throw RentsRepositoryException(RentsRepositoryException::exceptionRentNotExist);
}


