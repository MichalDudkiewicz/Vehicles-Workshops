#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"
#include "model/rent.h"
#include "model/car.h"
#include "model/bicycle.h"
#include <boost/test/output_test_stream.hpp>
#include "master.cpp"
#include "model/rentsManager.h"
#include "model/clientGold.h"
#include "model/clientBronze.h"
#include "model/clientSilver.h"

using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(ClientFirstNameCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_REQUIRE_EQUAL(client.getFullName(), "Jan Kowalski");
}

BOOST_AUTO_TEST_CASE(ClientLastNameCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_REQUIRE_EQUAL(client.getFullName(), "Jan Kowalski");
}

BOOST_AUTO_TEST_CASE(ClientPersonalIDCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_CHECK_EQUAL(client.getPersonalID(), "1234567890");
}

BOOST_AUTO_TEST_CASE(ClientAddressCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_CHECK_EQUAL(client.getAddress(), "adres 2");
}

BOOST_AUTO_TEST_CASE(ClientRegisteredAddressCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "adres2 5");
}

BOOST_AUTO_TEST_CASE(ClientSetNewAddressCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    client.setAddress("new adres", 333);
    BOOST_CHECK_EQUAL(client.getAddress(), "new adres 333");
}

BOOST_AUTO_TEST_CASE(ClientSetNewRegisteredAddressCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    client.setRegisteredAddress("new adres", 333);
    BOOST_CHECK_EQUAL(client.getRegisteredAddress(), "new adres 333");
}

BOOST_AUTO_TEST_CASE(ClientSetLastNameCase)
{
    Client client("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    client.setLastName("Duuuu");
    BOOST_CHECK_EQUAL(client.getFullName(), "Jan Duuuu");
}

BOOST_AUTO_TEST_CASE(ClientGetDefaultDiscountCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    float eps = 0.001;
    BOOST_TEST((*client).getDiscount() - 0 < eps);
}

BOOST_AUTO_TEST_CASE(ClientGetDefaultLimitCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 1);
}

BOOST_AUTO_TEST_CASE(ClientGetBronzeDiscountCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientBronze);
    (*client).setClientType(typeOfClient);
    float eps = 0.001;
    BOOST_TEST((*client).getDiscount() - 0.1< eps);
}

BOOST_AUTO_TEST_CASE(ClientGetBronzeLimitCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientBronze);
    (*client).setClientType(typeOfClient);
    BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 2);
}

BOOST_AUTO_TEST_CASE(ClientGetSilverDiscountCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientSilver);
    (*client).setClientType(typeOfClient);
    float eps = 0.001;
    BOOST_TEST((*client).getDiscount() - 0.2 < eps);
}

BOOST_AUTO_TEST_CASE(ClientGetSilverLimitCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientSilver);
    (*client).setClientType(typeOfClient);
    BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 3);
}

BOOST_AUTO_TEST_CASE(ClientGetGoldDiscountCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientGold);
    (*client).setClientType(typeOfClient);
    float eps = 0.001;
    BOOST_TEST((*client).getDiscount() -0.3 < eps);
}

BOOST_AUTO_TEST_CASE(ClientGetGoldLimitCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientGold);
    (*client).setClientType(typeOfClient);
    BOOST_CHECK_EQUAL((*client).getVehicleLimit(), 4);
}

BOOST_AUTO_TEST_CASE(ClientAddCurrentRentCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientGold);
    VehiclePtr v1 = make_shared<Bicycle>(100, "FB123");
    VehiclePtr v2 = make_shared<Bicycle>(120, "CD321");
    VehiclePtr v3 = make_shared<Car>(500, "EL 63821", 1300, 'A');
    VehiclePtr v4 = make_shared<Car>(800, "EZG 12351", 1600, 'B');
    VehiclePtr v5 = make_shared<Car>(1000, "EL 92013", 2000, 'C');
    (*client).setClientType(typeOfClient);
    RentPtr r1 = make_shared<Rent>(client, v1);
    RentPtr r2 = make_shared<Rent>(client, v2);
    RentPtr r3 = make_shared<Rent>(client, v3);
    (*client).addCurrentRent(r1);
    (*client).addCurrentRent(r2);
    (*client).addCurrentRent(r3);
    BOOST_CHECK_EQUAL((*client).getNumberOfRents(), 3);
}

BOOST_AUTO_TEST_CASE(ClientRemoveArchiveRentCase)
{
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
    ClientTypePtr typeOfClient(new ClientGold);
    VehiclePtr v1 = make_shared<Bicycle>(100, "FB123");
    VehiclePtr v2 = make_shared<Bicycle>(120, "CD321");
    VehiclePtr v3 = make_shared<Car>(500, "EL 63821", 1300, 'A');
    VehiclePtr v4 = make_shared<Car>(800, "EZG 12351", 1600, 'B');
    VehiclePtr v5 = make_shared<Car>(1000, "EL 92013", 2000, 'C');
    (*client).setClientType(typeOfClient);
    RentPtr r1 = make_shared<Rent>(client, v1);
    RentPtr r2 = make_shared<Rent>(client, v2);
    RentPtr r3 = make_shared<Rent>(client, v3);
    (*client).addCurrentRent(r1);
    (*client).addCurrentRent(r2);
    (*client).addCurrentRent(r3);
    (*client).removeArchiveRent(r2);
    BOOST_CHECK_EQUAL((*client).getNumberOfRents(), 2);
}


BOOST_AUTO_TEST_SUITE_END()
