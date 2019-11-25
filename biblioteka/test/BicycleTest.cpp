#include <boost/test/unit_test.hpp>
#include "model/bicycle.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(BicyclePriceCase)
{
    Bicycle bike(100, "123412");
    BOOST_REQUIRE_EQUAL(bike.getPrice(), 100);
}

BOOST_AUTO_TEST_CASE(BicycleRegistrationNumberCase)
{
    Bicycle bike(100, "123412");
    BOOST_REQUIRE_EQUAL(bike.getRegistrationNumber(), "123412");
}

BOOST_AUTO_TEST_CASE(BicycleVehicleInfoCase)
{
    string chain;
    Bicycle bike(100, "123412");
    chain = "BICYCLE: Registration number :" + bike.getRegistrationNumber() + ". Price: " + to_string(bike.getPrice());
    BOOST_REQUIRE_EQUAL(bike.vehicleInfo(), chain);
}


BOOST_AUTO_TEST_SUITE_END()
