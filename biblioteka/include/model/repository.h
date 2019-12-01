#ifndef repositoryClass
#define repositoryClass
#include <memory>
#include <string>
#include <list>

using namespace std;


template <class T>
class Repository
{
public:
    virtual void create(const shared_ptr<T>&)= 0;
    virtual void remove(const shared_ptr<T>&)= 0;
    virtual string getAll() const= 0;
    virtual const shared_ptr<T>& search(const unsigned int&) const= 0;
    virtual const list<shared_ptr<T>>& getRepository() const= 0;
    virtual ~Repository()= default;
};

#endif