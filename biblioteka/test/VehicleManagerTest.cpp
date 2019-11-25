#include <boost/test/unit_test.hpp>
#include "model/vehicleManager.h"
#include "model/bicycle.h"
#include <boost/test/output_test_stream.hpp>


using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleManagerCreateVehicleCase)
    {
        VehicleManager m;
        VehiclePtr vehicle = make_shared<Bicycle>(100, "FB123");
        VehiclePtr vehicle2 = make_shared<Bicycle>(100, "FB103");
        m.addVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 1);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRemoveVehicleCase)
    {
        VehicleManager m;
        VehiclePtr vehicle = make_shared<Bicycle>(100, "FB123");
        VehiclePtr vehicle2 = make_shared<Bicycle>(100, "FB103");
        m.addVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 1);
        m.removeVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 0);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchVehicles(), 1);
    }


    BOOST_AUTO_TEST_CASE(VehicleManagerSameRegistrationCase)
    {
        VehicleManager m;
        VehiclePtr vehicle = make_shared<Bicycle>(100, "FB103");
        VehiclePtr vehicle2 = make_shared<Bicycle>(100, "FB103");
        m.addVehicle(vehicle);
        BOOST_REQUIRE_THROW(m.addVehicle(vehicle2), logic_error);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerFromArchToCurrentCase)
    {
        VehicleManager m;
        VehiclePtr vehicle = make_shared<Bicycle>(100, "FB103");
        VehiclePtr vehicle2 = make_shared<Bicycle>(100, "FB103");
        m.addVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 1);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchVehicles(), 0);
        m.removeVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 0);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchVehicles(), 1);
        m.addVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 1);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchVehicles(), 0);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerRemoveNULLVehicleCase)
    {
        VehicleManager m;
        VehiclePtr vehicle = make_shared<Bicycle>(100, "FB123");
        VehiclePtr vehicle2 = make_shared<Bicycle>(100, "FB103");
        m.addVehicle(vehicle);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentVehicles(), 1);
        BOOST_REQUIRE_THROW( m.removeVehicle(vehicle2), logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()
