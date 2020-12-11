#include "../Airport.h"
#include "../Dijkstra/Dijkstra.h"
#include "../Graph.h"
#include "../Route.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Dijkstras Algorithm on simple graph", "[part=dijkstras]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(dijk.SSSP.size() == 3);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(dijk.SSSP["Airport A"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport B"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport C"] != INT32_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on complex graph", "[part=dijkstras]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(dijk.SSSP.size() == 8);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(dijk.SSSP["Airport A"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport B"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport C"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport D"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport E"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport F"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport G"] != INT32_MAX);
        REQUIRE(dijk.SSSP["Airport H"] != INT32_MAX);
    }
}