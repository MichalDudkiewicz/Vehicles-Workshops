#include <boost/test/unit_test.hpp>
#include "model/rentsManager.h"
#include "model/bicycle.h"
#include "model/car.h"
#include <sstream>
#include "model/client.h"
#include <boost/test/output_test_stream.hpp>
#include "model/clientSilver.h"
#include "model/rent.h"
#include <string>
#include <iostream>

using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(RentManagerCreateRentCase)
    {
        RentsManager m;
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, FatBike);
        m.rentVehicle(r);
        BOOST_REQUIRE_EQUAL(m.getClientForRentedVehicle(FatBike), client->clientInfo());
    }

BOOST_AUTO_TEST_CASE(RepositoryRemoveRentCase)
    {
        RentsManager m;
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, FatBike);
        m.rentVehicle(r);
        m.returnVehicle(r);
        BOOST_REQUIRE_EQUAL(m.getClientForRentedVehicle(FatBike), "");
    }


BOOST_AUTO_TEST_CASE(RepositorySameRegistrationCase)
    {
        RentsManager m;
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        ClientPtr client1 = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientPtr client2 = make_shared<Client>("Bogdan", "Kowalski", "123A90", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client1, FatBike);
        m.rentVehicle(r);
        RentPtr r2 = make_shared<Rent>(client2, FatBike);
        BOOST_REQUIRE_THROW(m.rentVehicle(r2), logic_error);
    }

BOOST_AUTO_TEST_CASE(RepositoryVehicleLimitExceededCase)
    {
        ostringstream chain;
        RentsManager m;
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr FatBike2 = make_shared<Bicycle>(100, "FB103");
        ClientPtr client1 = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client1, FatBike);
        RentPtr r2 = make_shared<Rent>(client1, FatBike2);
        m.rentVehicle(r);
        BOOST_CHECK_THROW(m.rentVehicle(r2), logic_error);
    }

BOOST_AUTO_TEST_CASE(ManagerAddRentCase)
    {
        output_test_stream output1;
        VehiclePtr v = make_shared<Car>(100, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, v);
        output1 << r->rentInfo()<<endl;
        RentsManager m;
        m.rentVehicle(r);
        BOOST_TEST(output1.is_equal(client->allRents()));
    }

BOOST_AUTO_TEST_CASE(ManagerRemoveClientRentCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(100, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientTypePtr typeOfClient(new ClientSilver);
        (*client).setClientType(typeOfClient);
        RentPtr r = make_shared<Rent>(client, v);
        RentPtr r2 = make_shared<Rent>(client, FatBike);
        RentsManager m;
        m.rentVehicle(r);
        m.rentVehicle(r2);
        m.returnVehicle(r);
        BOOST_REQUIRE_EQUAL((*client).getNumberOfRents(), 1);
        BOOST_REQUIRE_EQUAL((*client).getNumberOfArchRents(), 1);
    }

BOOST_AUTO_TEST_CASE(ManagerArchivisationCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(100, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientTypePtr typeOfClient(new ClientSilver);
        (*client).setClientType(typeOfClient);
        RentPtr r = make_shared<Rent>(client, v);
        RentPtr r2 = make_shared<Rent>(client, FatBike);
        RentsManager m;
        m.rentVehicle(r);
        m.rentVehicle(r2);
        m.returnVehicle(r);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentRents(), 1);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchRents(), 1);
    }

BOOST_AUTO_TEST_CASE(ManagerChangeTypeClientCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(1000, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, v);
        RentsManager m;
        m.rentVehicle(r);
        float d = client->getDiscount();
        m.returnVehicle(r);
        BOOST_TEST(client->getDiscount() > d);
    }
BOOST_AUTO_TEST_CASE(ManagerCheckClientRentBallanceCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(1000, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, v);
        RentPtr r1 = make_shared<Rent>(client, v);
        RentPtr r2 = make_shared<Rent>(client, v);
        RentsManager m;
        m.rentVehicle(r);
        m.returnVehicle(r);
        m.rentVehicle(r1);
        m.returnVehicle(r1);
        m.rentVehicle(r2);
        m.returnVehicle(r2);
        BOOST_CHECK_EQUAL(m.checkClientRentBalance(client), 3121);
    }
BOOST_AUTO_TEST_CASE(ManagerClientGetAllArchivedRentsCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(1000, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, v);
        RentPtr r1 = make_shared<Rent>(client, v);
        RentsManager m;
        m.rentVehicle(r);
        m.returnVehicle(r);
        m.rentVehicle(r1);
        m.returnVehicle(r1);
        BOOST_CHECK_EQUAL(m.getAllClientRents(client).size(), 2);
    }

    BOOST_AUTO_TEST_CASE(RentseManagerRemoveNULLRentCase)
    {
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr v = make_shared<Car>(1000, "ABC", 1232, 'A');
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client, v);
        RentPtr r1 = make_shared<Rent>(client, v);
        RentsManager m;
        m.rentVehicle(r);
        BOOST_REQUIRE_THROW(m.returnVehicle(r1), logic_error);
    }


BOOST_AUTO_TEST_SUITE_END()
