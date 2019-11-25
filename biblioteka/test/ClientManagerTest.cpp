#include <boost/test/unit_test.hpp>
#include "model/clientManager.h"
#include "model/bicycle.h"
#include "model/car.h"
#include <sstream>
#include "model/client.h"
#include <boost/test/output_test_stream.hpp>
#include "model/clientGold.h"
#include "model/clientBronze.h"
#include "model/clientSilver.h"
#include "model/rent.h"
#include <string>

using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerCreateClientCase)
    {
        ClientManager m;
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        m.addClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 1);
    }

    BOOST_AUTO_TEST_CASE(RepositoryRemoveClientCase)
    {
        ClientManager m;
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        m.addClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 1);
        m.removeClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 0);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchClients(), 1);
    }


    BOOST_AUTO_TEST_CASE(RepositorySameIDCase)
    {
        ClientManager m;
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        m.addClient(client);
        BOOST_REQUIRE_THROW(m.addClient(client), logic_error);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerFromArchToCurrentCase)
    {
        ClientManager m;
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        m.addClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 1);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchClients(), 0);
        m.removeClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 0);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchClients(), 1);
        m.addClient(client);
        BOOST_REQUIRE_EQUAL(m.getNumberOfCurrentClients(), 1);
        BOOST_REQUIRE_EQUAL(m.getNumberOfArchClients(), 0);
    }

    BOOST_AUTO_TEST_CASE(ClientManagerRemoveNULLClientCase)
    {
        ClientPtr client = make_shared<Client>("Jan", "Kowalski", "1234567890", "adres", 2, "adres2", 5);
        ClientPtr client2 = make_shared<Client>("Jan", "Kowalski", "123456337890", "adres", 2, "adres2", 5);
        ClientManager m;
        m.addClient(client);
        BOOST_REQUIRE_THROW(m.removeClient(client2), logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()
