#include "Graph.h"

Graph::Graph() {
    // Files
    airports_ = std::unordered_map<std::string,
                                   std::pair<Airport, std::vector<Route>>>();

    std::ifstream airport_data("Data/airport_data.txt");
    std::ifstream route_data("Data/route_data.txt");
    // Create and fill all nodes
    std::unordered_map<std::string, std::string> var_names;

    std::pair<std::string, std::string> name_pair("name", "");
    std::pair<std::string, std::string> lat_pair("latitude", "");
    std::pair<std::string, std::string> long_pair("longitude", "");
    std::pair<std::string, std::string> city_pair("city", "");
    std::pair<std::string, std::string> country_pair("country", "");
    std::pair<std::string, std::string> ID_pair("openflightID", "");
    std::pair<std::string, std::string> abbrev_pair("abbreviation", "");
    var_names.insert(name_pair);
    var_names.insert(lat_pair);
    var_names.insert(long_pair);
    var_names.insert(city_pair);
    var_names.insert(country_pair);
    var_names.insert(ID_pair);
    var_names.insert(abbrev_pair);

    std::string headers[14] = {
        "openflightID", "name",     "city",     "country",
        "abbreviation", "ICAO",     "latitude", "longitude",
        "altitude",     "timezone", "DST",      "timezone-database",
        "type",         "source"};
    std::string route_headers[9] = {
        "airline_code",     "airline_ID",     "source_code", "source_ID",
        "destination_code", "destination_ID", "codeshare",   "stops",
        "equipment"};
    if (airport_data.is_open() && route_data.is_open()) {
        std::string curr_airport;
        while (!airport_data.eof()) {
            int i = 0;
            int start_index = 0;
            int reads = 0;
            int delim_index = 0;
            bool is_string = false;
            std::getline(airport_data, curr_airport);
            while (reads < 7) {
                if (curr_airport[start_index] == '\"') {
                    is_string = true;
                    delim_index = curr_airport.find('\"', start_index + 1);
                    while (curr_airport[delim_index + 1] != ',') {
                        delim_index = curr_airport.find('\"', delim_index + 1);
                    }
                } else {
                    delim_index = curr_airport.find(",", start_index);
                }
                if (var_names.count(headers[i])) {
                    reads++;
                    std::string value = "";
                    if (is_string) {
                        start_index++;
                    }
                    for (int j = start_index; j < delim_index; j++) {
                        value += curr_airport[j];
                    }
                    var_names[headers[i]] = value;
                }
                start_index = delim_index + 1;
                if (is_string) {
                    start_index++;
                }
                i++;
                is_string = false;
            }
            // construct Airport
            double lat_val;
            double long_val;
            if (var_names["latitude"][0] == '-') {
                lat_val = std::stod(var_names["latitude"].substr(1), NULL) * -1;
            } else {
                lat_val = std::stod(var_names["latitude"], NULL);
            }
            if (var_names["longtitude"][0] == '-') {
                long_val =
                    std::stod(var_names["longitude"].substr(1), NULL) * -1;
            } else {
                long_val = std::stod(var_names["longitude"], NULL);
            }

            Airport new_airport(var_names["openflightID"], var_names["name"],
                                var_names["city"], var_names["country"],
                                lat_val, long_val, var_names["abbreviation"]);

            // Add to graph
            std::vector<Route> adjacent_routes = {};
            std::pair<Airport, std::vector<Route>> new_pair(new_airport,
                                                            adjacent_routes);
            std::pair<std::string, std::pair<Airport, std::vector<Route>>>
                completed(new_airport.get_OpenFlightID(), new_pair);
            airports_.insert(completed);
        }
        airport_data.close();
        var_names.clear();
        // Route data
        std::pair<std::string, std::string> source_pair("source_ID", "");
        std::pair<std::string, std::string> dest_pair("destination_ID", "");
        std::pair<std::string, std::string> ac_pair("airline_code", "");
        std::pair<std::string, std::string> stops_pair("stops", "");
        var_names.insert(source_pair);
        var_names.insert(dest_pair);
        var_names.insert(ac_pair);
        var_names.insert(stops_pair);
        std::string curr_route;
        while (!route_data.eof()) {
            int reads = 0;
            int i = 0;
            int start_index = 0;
            int delim_index = 0;
            std::getline(route_data, curr_route);
            while (reads < 4) {
                if (curr_route[start_index] == ',') {
                    start_index++;
                    i++;
                    continue;
                }
                delim_index = curr_route.find(",", start_index);
                if (delim_index == -1) {
                    delim_index = (int)curr_route.size() - 1;
                }
                if (var_names.count(route_headers[i])) {
                    reads++;
                    std::string value = "";
                    int j;
                    j = start_index;
                    for (int j = start_index; j < delim_index; j++) {
                        value += curr_route[j];
                    }
                    var_names[route_headers[i]] = value;
                }
                i++;
                start_index = delim_index + 1;
            }
            if(var_names["stops"] != "0"){
                continue;
            }
            const Airport& curr_source = get_airport_by_ID(var_names["source_ID"]);
            const Airport& curr_dest = get_airport_by_ID(var_names["destination_ID"]);
            int num_stops = std::stoi(var_names["stops"], NULL);
            Route new_route(curr_source, curr_dest, var_names["airline_code"], num_stops);
            routes_.push_back(new_route);
        }
        route_data.close();
    }
}

const Airport& Graph::get_airport_by_ID(std::string ID) {
    return airports_[ID].first;
}

std::unordered_map<std::string, std::pair<Airport, std::vector<Route>>>&
Graph::get_airports() {
    return airports_;
}

std::vector<Route>& Graph::get_routes() { return routes_; }