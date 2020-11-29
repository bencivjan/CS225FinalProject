#include "Route.h"

Route::Route(Airport source, Airport destination, std::string airline_code, int stops){
    source_ = source;
    destination_ = destination;
    airline_ICAO = airline_code;
    stops_ = stops;
}