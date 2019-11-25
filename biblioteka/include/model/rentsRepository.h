#ifndef rentsRepositoryClass
#define rentsRepositoryClass
#include <string>
#include <list>
#include <memory>
//#include "model/repository.h"

using namespace std;
class Rent;
class RentsManager;
typedef shared_ptr<Rent> RentPtr;

class RentsRepository
{
private:
    list<RentPtr> rentRepositoryList{};
    friend class RentsManager;
public:
    void createRent(const RentPtr&);
    void removeRent(const RentPtr&);
    string rentReport() const;
    int getNumberOfRents() const;
};

#endif