#ifndef repositoryClass
#define repositoryClass

#include <memory>

using namespace std;

template <class T>
class Repository
{
public:
    virtual void create(const shared_ptr<T>&)= 0;
    virtual void remove()= 0;
    virtual void update()= 0;
    virtual void getAll()= 0;
    virtual void search(const unsigned int&)= 0;
    virtual ~Repository()= default;
};

#endif