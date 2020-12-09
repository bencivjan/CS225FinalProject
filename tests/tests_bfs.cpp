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

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids.at(0) == "1");
        REQUIRE(bfs.visited_airport_ids.at(1) == "2");
        REQUIRE(bfs.visited_airport_ids.at(2) == "3");
    }
}

TEST_CASE("BFS traversal on cycle graph", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_cycle_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
        REQUIRE(bfs.visited_airport_ids[1] == "2");
        REQUIRE(bfs.visited_airport_ids[2] == "3");
    }
}

TEST_CASE("BFS traversal on disjoint graph starting at Airport A",
          "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
        REQUIRE(bfs.visited_airport_ids[1] == "2");
        REQUIRE(bfs.visited_airport_ids[2] == "3");
    }
}

TEST_CASE("BFS traversal on disjoint graph starting at Airport D",
          "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_disjoint_airport_data.csv",
            "Data/test_disjoint_route_data.csv", "4");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 2);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "4");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "5");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "4");
        REQUIRE(bfs.visited_airport_ids[1] == "5");
    }
}

TEST_CASE("BFS traversal on round trip graph starting at Airport A",
          "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_roundtrip_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
        REQUIRE(bfs.visited_airport_ids[1] == "2");
        REQUIRE(bfs.visited_airport_ids[2] == "3");
    }
}

TEST_CASE("BFS traversal on round trip graph starting at Airport B",
          "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_roundtrip_route_data.csv", "2");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "2");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "3");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "2");
        REQUIRE(bfs.visited_airport_ids[1] == "1");
        REQUIRE(bfs.visited_airport_ids[2] == "3");
    }
}

TEST_CASE("BFS traversal on empty route graph", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_empty_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "1");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
    }
}

TEST_CASE("BFS traversal on no outpath graph", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_simple_airport_data.csv",
            "Data/test_no_outpath_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 1);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "1");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
    }
}

// // TEST_CASE("BFS traversal on no airports graph", "[part=bfs]") {
// //     BFS bfs;
// //     Graph g("Data/test_empty_airport_data.csv",
// //             "Data/test_simple_route_data.csv", "1");

// //     bfs.traversal(g, g.start_airport);

// //     SECTION("Check visited correct number of airports") {
// //         REQUIRE(bfs.count == 0);
// //     }

// //     SECTION("Check visited correct airport first") {
// //         REQUIRE(bfs.start_airport.get_OpenFlightID() == "");
// //     }

// //     SECTION("Check visited correct airport last") {
// //         REQUIRE(bfs.end_airport.get_OpenFlightID() == "");
// //     }

// //     SECTION("Visited airports in correct order") {
// //         REQUIRE(bfs.visited_airport_ids.size() == 0);
// //     }
// // }

TEST_CASE("BFS traversal on complex graph", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/test_complex_airport_data.csv",
            "Data/test_complex_route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 7);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "8");
    }

    SECTION("Visited airports in correct order") {
        REQUIRE(bfs.visited_airport_ids[0] == "1");
        REQUIRE(bfs.visited_airport_ids[1] == "5");
        REQUIRE(bfs.visited_airport_ids[2] == "3");
        REQUIRE(bfs.visited_airport_ids[3] == "7");
        REQUIRE(bfs.visited_airport_ids[4] == "6");
        REQUIRE(bfs.visited_airport_ids[5] == "2");
        REQUIRE(bfs.visited_airport_ids[6] == "8");
    }
}

TEST_CASE("BFS traversal on dataset", "[part=bfs]") {
    BFS bfs;
    Graph g("Data/airport_data.csv", "Data/route_data.csv", "1");

    bfs.traversal(g, g.start_airport);

    SECTION("Check visited correct number of airports") {
        REQUIRE(bfs.count == 3189);
    }

    SECTION("Check visited correct airport first") {
        REQUIRE(bfs.start_airport.get_OpenFlightID() == "1");
    }

    SECTION("Check visited correct airport last") {
        REQUIRE(bfs.end_airport.get_OpenFlightID() == "5522");
    }

    // SECTION("Visited airports in correct order") {
    //     REQUIRE(bfs.visited_airport_ids[0] == "1");
    //     REQUIRE(bfs.visited_airport_ids[1] == "5");
    //     REQUIRE(bfs.visited_airport_ids[2] == "3");
    //     REQUIRE(bfs.visited_airport_ids[3] == "7");
    //     REQUIRE(bfs.visited_airport_ids[4] == "6");
    //     REQUIRE(bfs.visited_airport_ids[5] == "2");
    //     REQUIRE(bfs.visited_airport_ids[6] == "8");
    // }
}