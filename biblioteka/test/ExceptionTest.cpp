#include <boost/test/unit_test.hpp>
#include "model/rent.h"
#include "model/client.h"
#include "model/vehicle.h"
#include "model/address.h"
#include "model/rentsRepository.h"
#include "model/clientRepository.h"
#include "model/vehicleRepository.h"
#include "model/rentsManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(RentNullPtrExceptionCase)
{
    ClientPtr client = make_shared<Client>("Michal", "Dudkiewicz", "123", "Woronicza", 7, "Cicha", 33);
    VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "A11112");
    BOOST_REQUIRE_THROW(RentPtr wypozyczenie = make_shared<Rent>(client, nullptr, 10), logic_error);
    BOOST_REQUIRE_THROW(RentPtr wypozyczenie = make_shared<Rent>(nullptr, pojazd, 10), logic_error);
}

BOOST_AUTO_TEST_CASE(RentSameUIDExceptionCase)
{
    ClientPtr client = make_shared<Client>("Michal", "Dudkiewicz", "123", "Woronicza", 7, "Cicha", 33);
    VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "A11112");
    RentPtr wypozyczenie = make_shared<Rent>(client, pojazd, 10);
    RentsManager m;
    m.rentVehicle(wypozyczenie);
    BOOST_REQUIRE_THROW(m.rentVehicle(wypozyczenie), logic_error);
}
BOOST_AUTO_TEST_CASE(ClientSameIDExceptionCase)
{
    ClientPtr client = make_shared<Client>("Michal", "Dudkiewicz", "123", "Woronicza", 7, "Cicha", 33);
    ClientPtr client2 = make_shared<Client>("Mich2al", "Dudks", "123", "Woronicza", 7, "Cicha", 33);
    ClientRepository r;
    r.addClient(client);
    BOOST_REQUIRE_THROW(r.addClient(client2), logic_error);
}

BOOST_AUTO_TEST_CASE(VehicleSameRegExceptionCase)
{
    VehiclePtr pojazd = make_shared<Vehicle>(1010.2, "A11112");
    VehiclePtr pojazd2 = make_shared<Vehicle>(10210.2, "A11112");
    VehicleRepository v;
    v.create(pojazd);
    BOOST_REQUIRE_THROW(v.create(pojazd2), logic_error);
}

BOOST_AUTO_TEST_CASE(AddressExceptionCase)
{
    BOOST_REQUIRE_THROW(Address("", 1), logic_error);
    BOOST_REQUIRE_THROW(Address("sss", -1), logic_error);
}

BOOST_AUTO_TEST_CASE(ClientExceptionCase)
{
    BOOST_REQUIRE_THROW(Client("", "aaa", "aaa", "aa", 3, "ss", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("a", "", "aaa", "aa", 3, "ss", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("aaa", "aaa", "", "aa", 3, "ss", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("s", "aaa", "aaa", "", 3, "ss", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("a", "aaa", "aaa", "aa", 3, "", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("aa", "aaa", "aaa", "aa", -3, "ss", 4), logic_error);
    BOOST_REQUIRE_THROW(Client("", "aaa", "aaa", "aa", 3, "ss", -4), logic_error);
}
BOOST_AUTO_TEST_CASE(ClientDifferentIDCase)
{
    ClientPtr client1 = make_shared<Client>("Michal", "Dudkiewicz", "1234", "Woronicza", 7, "Cicha", 33);
    ClientPtr client2 = make_shared<Client>("Michal", "Dudkiewicz", "1235", "Woronicza", 7, "Cicha", 33);
    ClientPtr client3 = make_shared<Client>("Michal", "Dudkiewicz", "1236", "Woronicza", 7, "Cicha", 33);
    ClientPtr client4 = make_shared<Client>("Michal", "Dudkiewicz", "1237", "Woronicza", 7, "Cicha", 33);
    ClientPtr client5 = make_shared<Client>("Michal", "Dudkiewicz", "1238", "Woronicza", 7, "Cicha", 33);
    ClientPtr client6 = make_shared<Client>("Michal", "Dudkiewicz", "1239", "Woronicza", 7, "Cicha", 33);
    ClientPtr client7 = make_shared<Client>("Michal", "Dudkiewicz", "1230", "Woronicza", 7, "Cicha", 33);
    ClientPtr client8 = make_shared<Client>("Michal", "Dudkiewicz", "1243", "Woronicza", 7, "Cicha", 33);
    ClientPtr client9 = make_shared<Client>("Michal", "Dudkiewicz", "1123", "Woronicza", 7, "Cicha", 33);
    ClientPtr client10 = make_shared<Client>("Michal", "Dudkiewicz", "1253", "Woronicza", 7, "Cicha", 33);
    ClientPtr tablica[10];
    tablica[0] = client1;
    tablica[1] = client2;
    tablica[2] = client3;
    tablica[3] = client4;
    tablica[4] = client5;
    tablica[5] = client6;
    tablica[6] = client7;
    tablica[7] = client8;
    tablica[8] = client9;
    tablica[9] = client10;
    ClientRepository repozytorium;
    for(const auto& client : tablica)
    {
        repozytorium.addClient(client);
    }
    BOOST_REQUIRE_EQUAL(repozytorium.getNumberOfClients(), 10);
}


BOOST_AUTO_TEST_SUITE_END()
