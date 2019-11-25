#include <boost/test/unit_test.hpp>
#include "model/car.h"
#include <string>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(CarPriceCase)
{
    Car RenaultMegane(1000, "EL 92013", 2000, 'C');
    float eps = 0.001;
    BOOST_TEST(abs(RenaultMegane.getPrice() - 1800) <= eps);
}

BOOST_AUTO_TEST_CASE(CarRegistrationNumberCase)
{
    Car RenaultMegane(1000, "EL 92013", 2000, 'C');
    BOOST_REQUIRE_EQUAL(RenaultMegane.getRegistrationNumber(), "EL 92013");
}

BOOST_AUTO_TEST_CASE(CarEngineDisplacementCase)
{
    Car RenaultMegane(1000, "EL 92013", 2000, 'C');
    BOOST_REQUIRE_EQUAL(RenaultMegane.getEngineDisplacement(), 2000);
}

BOOST_AUTO_TEST_CASE(CarVehicleInfoCase)
{
    string chain;
    Car RenaultMegane(1000, "EL 92013", 2000, 'C');
    chain = "CAR: Registration number :" + RenaultMegane.getRegistrationNumber() + ". Engine displacement: " + to_string(RenaultMegane.getEngineDisplacement()) + ". Price: " + to_string(RenaultMegane.getPrice()) + ". Car class: C";
    BOOST_REQUIRE_EQUAL(RenaultMegane.vehicleInfo(), chain);
}



BOOST_AUTO_TEST_SUITE_END()
