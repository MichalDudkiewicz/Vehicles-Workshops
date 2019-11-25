#include <boost/test/unit_test.hpp>
#include "model/moped.h"
#include <string>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(MopedPriceCase)
{
    Moped skuter4(120, "EL 231", 500);
    float eps = 0.001;
    BOOST_TEST(abs(skuter4.getPrice() - 120) <= eps);
}

BOOST_AUTO_TEST_CASE(MopedRegistrationNumberCase)
{
    Moped skuter4(120, "EL 231", 500);
    BOOST_REQUIRE_EQUAL(skuter4.getRegistrationNumber(), "EL 231");
}

BOOST_AUTO_TEST_CASE(MopedEngineDisplacementCase) {
    Moped skuter4(120, "EL 231", 500);
    BOOST_REQUIRE_EQUAL(skuter4.getEngineDisplacement(), 500);
}

BOOST_AUTO_TEST_CASE(MopedVehicleInfoCase) {
    string chain;
    Moped skuter4(120, "EL 231", 500);
    chain = "MOPED: Registration number :" + skuter4.getRegistrationNumber() + ". Engine displacement: " + to_string(skuter4.getEngineDisplacement()) + ". Price: " + to_string(skuter4.getPrice());
    BOOST_REQUIRE_EQUAL(skuter4.vehicleInfo(), chain);
}



BOOST_AUTO_TEST_SUITE_END()
