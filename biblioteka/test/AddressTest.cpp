#include <boost/test/unit_test.hpp>
#include "model/client.h"
#include "model/address.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(AddressGetAddressCase)
{
    Address adres("street1", 10);
    BOOST_REQUIRE_EQUAL(adres.getAddress(), "street1 10");
}

BOOST_AUTO_TEST_CASE(AddressSetAddressCase)
{
    Address adres("street1", 10);
    adres.setAddress("street2", 1);
    BOOST_REQUIRE_EQUAL(adres.getAddress(), "street2 1");
}

BOOST_AUTO_TEST_CASE(AddressClientCompositionCase)
{
    Address adres("street1", 10);
    Client klient1("Michal", "Dudkiewicz", "12345", "street1", 10, "street1", 10);
    Client klient2("Mateusz", "Dudkiewicz", "125", "street1", 10, "street1", 10);
    adres.setAddress("street2", 1);
    BOOST_REQUIRE_EQUAL(klient1.getAddress(), klient2.getAddress());
}

BOOST_AUTO_TEST_SUITE_END()
