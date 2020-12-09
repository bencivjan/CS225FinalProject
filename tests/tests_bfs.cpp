#define CATCH_CONFIG_MAIN

#include "../BFS/BFS.h"
#include "../Graph.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("BFS traversal on simple graph", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3);
    }

    // SECTION("Check visited correct numver of airports") {
    //     REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    // }

    // SECTION("Check visited correct numver of airports") {
    //     REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    // }

    // SECTION("Check visited correct numver of airports") {
    //     REQUIRE(bfs.count == 3);
    // }
}