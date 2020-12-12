#include "../Airport.h"
#include "../Dijkstra/Dijkstra.h"
#include "../Graph.h"
#include "../Route.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Dijkstras Algorithm on simple graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_simple_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on cycle graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_cycle_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on disjoint graph", "[part=dijkstra]") {
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
        REQUIRE(test["Airport D"] != DBL_MAX);
        REQUIRE(test["Airport E"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on disjoint graph start at d",
          "[part=dijkstra]") {
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "4");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 2);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
        REQUIRE(test["Airport D"] != DBL_MAX);
        REQUIRE(test["Airport E"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on empty graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_empty_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on multiple paths graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_multpile_paths_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on no outpath graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_no_outpath_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on roundtrip graph", "[part=dijkstra]") {
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_roundtrip_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
    }
}

TEST_CASE("Dijkstras Algorithm on complex graph", "[part=dijkstra]") {
    Graph g("Data/test_complex_airport_data.csv",
            "Data/test_complex_route_data.csv", "1");
    Dijkstra dijk = Dijkstra(g, g.start_airport);

    std::unordered_map<std::string, double> test = dijk.algorithm();

    SECTION("Check visited correct number of airports") {
        REQUIRE(test.size() == 7);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(test["Airport A"] == 0);
    }

    SECTION("Visited airports without a cycle") {
        REQUIRE(test["Airport A"] != DBL_MAX);
        REQUIRE(test["Airport B"] != DBL_MAX);
        REQUIRE(test["Airport C"] != DBL_MAX);
        REQUIRE(test["Airport D"] != DBL_MAX);
        REQUIRE(test["Airport E"] != DBL_MAX);
        REQUIRE(test["Airport F"] != DBL_MAX);
        REQUIRE(test["Airport G"] != DBL_MAX);
        REQUIRE(test["Airport H"] != DBL_MAX);
    }
}