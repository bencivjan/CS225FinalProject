map : main.o Graph.o Airport.o Route.o
	clang++ main.o Graph.o Airport.o Route.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o map

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



test : tests_astar.o tests_bfs.o Graph.o Airport.o Route.o BFS.o
	clang++ tests_astar.o tests_bfs.o Graph.o Airport.o Route.o BFS.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o test

tests_bfs.o : tests/tests_bfs.cpp cs225/catch/catch.hpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests_bfs.cpp

tests_astar.o : tests/tests_astar.cpp cs225/catch/catch.hpp
	clang++ -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests_astar.cpp
	
clean:
	rm -rf *.o map test
