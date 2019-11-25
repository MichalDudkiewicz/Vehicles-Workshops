#ifndef repositoryClass
#define repositoryClass

using namespace std;

template <class T>
class Repository
{
public:
    virtual void create()= 0;
    virtual void remove()= 0;
    virtual void update()= 0;
    virtual void getAll()= 0;
    virtual void find()= 0;
    virtual ~Repository()= default;
};

#endif