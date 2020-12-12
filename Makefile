map : main.o Graph.o Airport.o Route.o Dijkstra.o Astar.o BFS.o
	clang++ main.o Graph.o Airport.o Route.o Dijkstra.o BFS.o astar.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o map

main.o : main.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic main.cpp

Graph.o : Graph.h Graph.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic Graph.cpp

Airport.o : Airport.h Airport.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic Airport.cpp

Route.o : Route.h Route.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic Route.cpp

BFS.o : BFS/BFS.h BFS/BFS.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic BFS/BFS.cpp

Dijkstra.o : Dijkstra/Dijkstra.cpp Dijkstra/Dijkstra.h 
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic Dijkstra/Dijkstra.cpp

Astar.o : Astar/astar.h Astar/astar.cpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic Astar/astar.cpp



test : tests_astar.o tests_bfs.o tests_dijkstras.o Graph.o Airport.o Route.o BFS.o Astar.o Dijkstra.o
	clang++ tests_astar.o tests_bfs.o tests_dijkstras.o Graph.o Airport.o Route.o BFS.o astar.o Dijkstra.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o test

tests_bfs.o : tests/tests_bfs.cpp cs225/catch/catch.hpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests_bfs.cpp

tests_astar.o : tests/tests_astar.cpp cs225/catch/catch.hpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests_astar.cpp

tests_dijkstras.o : tests/tests_dijkstras.cpp cs225/catch/catch.hpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests_dijkstras.cpp
	
clean:
	rm -rf *.o map test
