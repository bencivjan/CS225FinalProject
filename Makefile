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
	
clean:
	rm -rf *.o map
