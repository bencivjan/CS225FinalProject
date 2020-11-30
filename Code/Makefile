map : main.o Graph.o Airport.o Route.o hash.o
	clang++ main.o Graph.o Airport.o Route.o hash.o -o map

main.o : main.cpp
	clang++ -c main.cpp

Graph.o : Graph.h Graph.cpp
	clang++ -c Graph.cpp

Airport.o : Airport.h Airport.cpp
	clang++ -c Airport.cpp

Route.o : Route.h Route.cpp
	clang++ -c Route.cpp
	
hash.o : hash.cpp
	clang++ -c hash.cpp