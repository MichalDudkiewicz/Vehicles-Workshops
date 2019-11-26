#include <iostream>
#include "model/client.h"
#include <memory>
#include "model/clientType.h"
#include "model/clientRepository.h"
#include "model/clientGold.h"

using namespace std;

int main() {
    ClientPtr klient = make_shared<Client>("Michal", "Dudkiewicz", "1234", "a", 2, "b", 3);
    cout << (*klient).getDiscount();
    cout << (*klient).getVehicleLimit();
    ClientTypePtr typeOfClient(new ClientGold);
    (*klient).setClientType(typeOfClient);
    cout << (*klient).getDiscount();
    cout << (*klient).getVehicleLimit();
    ClientRepository repo;
    repo.addClient(klient);
    cout << endl;
    ClientPtr klient2 = make_shared<Client>("Jacek", "Dudkiewicz", "12334", "a", 2, "b", 3);
    ClientPtr klient3 = make_shared<Client>("Andrzej", "Dudkiewicz", "12w34", "a", 2, "b", 3);
    ClientPtr klient4 = make_shared<Client>("Anna", "Dudkiewicz", "12134", "a", 2, "b", 3);
    repo.addClient(klient2);
    repo.addClient(klient3);
    repo.addClient(klient4);
    cout << repo.clientRepositoryInfo()<<endl;
    repo.changeType(klient2, typeOfClient);
    cout << repo.clientRepositoryInfo()<<endl;
    repo.removeClient(klient3);
    cout << repo.clientRepositoryInfo()<<endl;
    repo.removeClient(1);
    cout << repo.clientRepositoryInfo()<<endl;
    return 0;
}

