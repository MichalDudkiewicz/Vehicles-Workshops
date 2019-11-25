cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
    src/model/client.cpp
    src/model/address.cpp
    src/model/vehicle.cpp
    src/model/rent.cpp
    src/model/motorVehicle.cpp
    src/model/car.cpp
    src/model/moped.cpp
    src/model/bicycle.cpp
    src/model/rentsRepository.cpp
    src/model/vehicleRepository.cpp
    src/model/clientBronze.cpp
    src/model/clientSilver.cpp
    src/model/clientGold.cpp
    src/model/clientRepository.cpp
    src/model/rentsManager.cpp
    src/model/clientException.cpp
    src/model/vehicleException.cpp
    src/model/rentException.cpp
    src/model/addressException.cpp
    src/model/clientRepositoryException.cpp
    src/model/rentsRepositoryException.cpp
    src/model/vehicleRepositoryException.cpp
    src/model/clientManager.cpp
    src/model/vehicleManager.cpp
        )
#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/include
 ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
 test/master.cpp
 test/ClientTest.cpp
 test/AddressTest.cpp
 test/RentTest.cpp
 test/BicycleTest.cpp
 test/CarTest.cpp
 test/MopedTest.cpp
 test/RentsRepositoryTest.cpp
 test/VehicleRepositoryTest.cpp
 test/ClientRepositoryTest.cpp
 test/RentsManagerTest.cpp
 test/ExceptionTest.cpp
 test/VehicleManagerTest.cpp
 test/ClientManagerTest.cpp
        )

add_executable (TestBibl ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (TestBibl
 Biblioteka
 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
 )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele. 
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestBibl
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
