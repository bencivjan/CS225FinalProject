#include "Graph.h"

Graph::Graph(){
    // Files
    airports_ = std::unordered_map<Airport, std::vector<Route>>();
     
    std::ifstream airport_data("Data/airport_data.txt");
    std::ifstream route_data("Data/route_data.txt");
    // Create and fill all nodes
    std::unordered_map<std::string, std::string> var_names;

    std::pair<std::string, std::string> name_pair("name", "");
    std::pair<std::string, std::string> lat_pair("latitude", "");
    std::pair<std::string, std::string> long_pair("longitutde", "");
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

    std::string headers[14] = {"openflightID", "name", "city", "country", "abbreviation", "ICAO", "latitude", "longitutde", "altitude", "timezone", "DST", "timezone-database", "type", "source"};
    if(airport_data.is_open() && route_data.is_open()){
        std::string curr_airport;
        while(!airport_data.eof()){
            int i = 0;
            int start_index = 0;
            int reads = 0;
            int delim_index = 0;
            std::getline(airport_data, curr_airport);
            while(reads < 7){
                delim_index = curr_airport.find(",", start_index);
                if(var_names.count(headers[i])){
                    reads++;
                    std::string value = "";
                    for(int j = start_index; j < delim_index; j++){
                        value += curr_airport[j];
                    }
                    var_names[headers[i]] = value;
                }
                start_index = delim_index + 1;
                i++;
            }
            // construct Airport
            std::cout << "latitude = " << var_names["latitude"] << "\n";
            Airport new_airport(var_names["openflightID"], var_names["name"], var_names["city"], var_names["country"],
                            std::stod(var_names["latitidue"],NULL), std::stod(var_names["longitude"], NULL),
                            var_names["abbreviation"]);

            // Add to graph
            std::vector<Route> adjacent_routes = {};
            std::pair<Airport, std::vector<Route>> new_pair(new_airport, adjacent_routes);
            airports_.insert(new_pair);
        }
        airport_data.close();
        // Route data
        std::string curr_route;
        while(!route_data.eof()){
            int reads = 0;
            int i = 0;
            int start_index = 0;
            int delim_index = 0;
            std::getline(route_data, curr_route);
            while(reads < 2){
                delim_index = curr_route.find(",", start_index);
            }

        }
    }

}

std::unordered_map<Airport, std::vector<Route>>& Graph::data(){
    return airports_;
}