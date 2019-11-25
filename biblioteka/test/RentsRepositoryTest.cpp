#include <boost/test/unit_test.hpp>
#include "model/rentsRepository.h"
#include "model/bicycle.h"
#include <sstream>
#include "model/rent.h"
#include "model/client.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(RepositoryReportCase)
    {
        ostringstream chain;
        RentsRepository repository;
        VehiclePtr FatBike = make_shared<Bicycle>(100, "FB123");
        VehiclePtr FatBike2 = make_shared<Bicycle>(100, "FB103");
        ClientPtr client1 = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientPtr client2 = make_shared<Client>("Bogdan", "Kowalski", "123A90", "adres", 2, "adres2", 5);
        RentPtr r = make_shared<Rent>(client1, FatBike);
        repository.createRent(r);
        RentPtr r2 = make_shared<Rent>(client2, FatBike2);
        chain << r->rentInfo();
        chain << r2->rentInfo();
        repository.createRent(r2);
        BOOST_REQUIRE_EQUAL(repository.rentReport(), chain.str());
    }

BOOST_AUTO_TEST_SUITE_END()
