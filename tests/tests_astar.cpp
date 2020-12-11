#include "../Astar/astar.h"
#include "../Graph.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Astar simple test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "2");
        REQUIRE(path[2].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar multiple paths test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_multiple_paths_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar cycle test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_cycle_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "2");
        REQUIRE(path[2].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar disjoint start at A test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "2");
        REQUIRE(path[2].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar disjoint start at D test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "4");

    Airport end = g.get_airport_by_ID("5");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 2);
        REQUIRE(astar.count_open == 2);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "4");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "5");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "4");
        REQUIRE(path[1].get_OpenFlightID() == "5");
    }
}

TEST_CASE("Astar disjoint no path test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("5");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "-1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "-1");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "-1");
    }
}

TEST_CASE("Astar round trip test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_roundtrip_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "2");
        REQUIRE(path[2].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar all disjoint test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_empty_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 1);
        REQUIRE(astar.count_open == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "-1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "-1");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "-1");
    }
}

TEST_CASE("Astar complex test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_complex_airport_data.csv",
            "Data/test_complex_route_data.csv", "1");

    Airport end = g.get_airport_by_ID("3");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 3);
        REQUIRE(astar.count_open == 4);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "5");
        REQUIRE(path[2].get_OpenFlightID() == "3");
    }
}

TEST_CASE("Astar test on actual data", "[part=astar]") {
    Astar astar;
    Graph g("Data/airport_data.csv", "Data/route_data.csv", "1");

    Airport end = g.get_airport_by_ID("5");

    vector<Airport> path = astar.astarPath(g, g.start_airport, end);

    SECTION("Check visited correct number of airports") {
        REQUIRE(astar.count_closed == 5);
        REQUIRE(astar.count_open == 15);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(path[path.size() - 1].get_OpenFlightID() == "5");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(path[0].get_OpenFlightID() == "1");
        REQUIRE(path[1].get_OpenFlightID() == "5");
    }
}