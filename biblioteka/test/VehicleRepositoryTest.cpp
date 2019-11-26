#include <boost/test/unit_test.hpp>
#include "model/vehicleRepository.h"
#include "model/bicycle.h"
#include "model/car.h"
#include "model/moped.h"
#include <sstream>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(VehicleRepositoryRaportCase)
    {
        VehiclePtr tablica[10];
        tablica[0] = make_shared<Bicycle>(100, "FB123");
        tablica[1] = make_shared<Bicycle>(120, "CD321");
        tablica[2] = make_shared<Car>(500, "EL 63821", 1300, 'A');
        tablica[3] = make_shared<Car>(800, "EZG 12351", 1600, 'B');
        tablica[4] = make_shared<Car>(1000, "EL 92013", 2000, 'C');
        tablica[5] = make_shared<Car>(1500, "EZG 71273", 2400, 'E');
        tablica[6] = make_shared<Moped>(200, "EL 723", 800);
        tablica[7] = make_shared<Moped>(300, "EL 923", 1100);
        tablica[8] = make_shared<Moped>(150, "EL 823", 700);
        tablica[9] = make_shared<Moped>(120, "EL 231", 500);
        VehicleRepository repozytorium;
        ostringstream chain;
        for(unsigned int i = 0; i<10; i++)
        {
            repozytorium.create(tablica[i]);
            chain << i+1 << "- " << tablica[i]->vehicleInfo()<<endl;
        }
        BOOST_REQUIRE_EQUAL(repozytorium.getAll(), chain.str());
    }

BOOST_AUTO_TEST_CASE(VehicleRepositoryGetVehicleCase)
    {
        VehiclePtr tablica[10];
        tablica[0] = make_shared<Bicycle>(100, "FB123");
        tablica[1] = make_shared<Bicycle>(120, "CD321");
        tablica[2] = make_shared<Car>(500, "EL 63821", 1300, 'A');
        tablica[3] = make_shared<Car>(800, "EZG 12351", 1600, 'B');
        tablica[4] = make_shared<Car>(1000, "EL 92013", 2000, 'C');
        tablica[5] = make_shared<Car>(1500, "EZG 71273", 2400, 'E');
        tablica[6] = make_shared<Moped>(200, "EL 723", 800);
        tablica[7] = make_shared<Moped>(300, "EL 923", 1100);
        tablica[8] = make_shared<Moped>(150, "EL 823", 700);
        tablica[9] = make_shared<Moped>(120, "EL 231", 500);
        VehicleRepository repozytorium;
        ostringstream chain;
        for(unsigned int i = 0; i<10; i++)
        {
            repozytorium.create(tablica[i]);
            if(i==3)
            {
                chain << tablica[i]->vehicleInfo();
            }
        }
        BOOST_REQUIRE_EQUAL(repozytorium.search(4), chain.str());
    }


BOOST_AUTO_TEST_SUITE_END()
