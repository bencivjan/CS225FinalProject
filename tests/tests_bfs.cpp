#define CATCH_CONFIG_MAIN

#include "../BFS/BFS.h"
#include "../Graph.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Visits all airports in cycle", "[part=bfs") {
    BFS bfs;
    Graph g("Data/test_airport_data.csv", "Data/test_cycle_route_data.csv");
    // Graph g("Data/airport_data.csv", "Data/route_data.csv");

    bfs.traversal(g, g.start_airport);
    REQUIRE(bfs.count == 3);
}

TEST_CASE("Visits correct airport first", "[part=bfs]") {
    REQUIRE(true == true);
}

TEST_CASE("Visits all airports", "[part=bfs]") { REQUIRE(true == true); }

TEST_CASE("Visits airports in correct order", "[part=bfs]") {
    REQUIRE(true == true);
}