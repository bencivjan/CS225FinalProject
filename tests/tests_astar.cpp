#include "../Astar/astar.h"
#include "../Graph.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Astar test example", "[part=astar]") {
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