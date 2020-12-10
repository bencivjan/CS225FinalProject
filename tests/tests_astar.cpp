#include "../Astar/astar.h"
#include "../Graph.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Astar test example", "[part=astar]") {
    Astar astar;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");

    // astar.astarPath(g, g.start_airport, Airport);

    // SECTION("Check visited correct number of airports") {
    //     REQUIRE(bfs.count == 3);
    // }

    // SECTION("Check visited correct airport first") {
    //     REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    // }

    // SECTION("Check visited correct airport last") {
    //     REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    // }

    // SECTION("Visited airports in correct order") {
    //     REQUIRE(bfs.visited_airport_ids.at(0) == "1");
    //     REQUIRE(bfs.visited_airport_ids.at(1) == "2");
    //     REQUIRE(bfs.visited_airport_ids.at(2) == "3");
}
}