#include "Airport.h"
namespace std{
    template <>
    struct hash<Airport>{
        std::size_t operator()(const Airport& key) const{
            std::hash<std::string> str_hash;
            return str_hash(key.get_name());
        }
    }; 
}