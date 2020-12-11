#include "Route.h"

#include <cmath>

Route::Route(const Airport& source, const Airport& destination,
             std::string airline_code, int stops)
    : source_(source), destination_(destination) {
    this->airline_code = airline_code;
    stops_ = stops;
    weight_ = get_dist();
}

const Airport& Route::get_source() { return source_; }

const Airport& Route::get_destination() { return destination_; }

std::string Route::get_code() { return this->airline_code; }

int Route::get_stops() { return stops_; }

double Route::get_dist() {
    std::pair<double, double> coords1 = source_.get_coords();
    std::pair<double, double> coords2 = destination_.get_coords();
    int dist =
        ((coords1.first - coords2.first) * (coords1.first - coords2.first)) +
        ((coords1.second - coords2.second) * (coords1.second - coords2.second));
    return sqrt(dist);
}

double Route::get_weight() { return weight_; }