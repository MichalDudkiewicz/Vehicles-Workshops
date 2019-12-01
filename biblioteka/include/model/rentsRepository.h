#ifndef rentsRepositoryClass
#define rentsRepositoryClass
#include <string>
#include <list>
#include <memory>
#include "model/repository.h"

using namespace std;
class Rent;
class RentsManager;
typedef shared_ptr<Rent> RentPtr;

class RentsRepository : Repository<Rent>
{
private:
    list<RentPtr> rentRepositoryList{};
public:
    void create(const RentPtr& rent) override;
    void remove(const RentPtr& rent) override;
    string getAll() const override;
    const list<RentPtr>& getRepository() const override;
    const RentPtr& search(const unsigned int&) const override;
};

#endif