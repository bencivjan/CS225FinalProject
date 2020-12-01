map : main.o Graph.o Airport.o Route.o
	g++ -g main.o Graph.o Airport.o Route.o -o map -ggdb

main.o : main.cpp
	g++ -std=gnu++11 -c main.cpp

Graph.o : Graph.h Graph.cpp
	g++ -std=gnu++11 -c Graph.cpp

Airport.o : Airport.h Airport.cpp
	g++ -c Airport.cpp

Route.o : Route.h Route.cpp
	g++ -c Route.cpp
	