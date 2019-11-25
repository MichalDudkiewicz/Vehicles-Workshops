#ifndef addressClass
#define addressClass
#include <string>

using namespace std;

class Address
{
private:
    string street;
    int houseNumber;
public:
    Address(const string&, const int&);
    string getAddress() const;
    void setAddress(const string&, const int&);
};

#endif