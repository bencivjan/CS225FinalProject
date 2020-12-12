#pragma once
#include <string>

#include "Airport.h"
class Route {
   private:
    const Airport& source_;
    const Airport& destination_;
    std::string airline_code;
    int stops_;
    double weight_;

   public:
    Route(const Airport& source, const Airport& destination,
          std::string airline_code, int stops);

    const Airport& get_source();
    const Airport& get_destination();
    std::string get_code();
    int get_stops();
    double get_dist();
    double get_weight();
};