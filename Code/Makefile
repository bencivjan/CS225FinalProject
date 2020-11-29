
map : main.o graph.o airport.o route.o
	clang++ main.o graph.o airport.o route.o -o map

main.o : main.cpp
	clang++ -c main.cpp

graph.o : Graph.h Graph.cpp
	clang++ -c Graph.cpp

airport.o : Airport.h Airport.cpp
	clang++ -c Airport.cpp

route.o : Route.h Route.cpp
	clang++ -c Route.cpp
	
