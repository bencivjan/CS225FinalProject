#include "Airport.h"
namespace std{
    template <>
    struct hash<Airport>{
        std::size_t operator()(const Airport& k) const{
            std::hash<std::string> str_hash;
            return str_hash(k.get_name());
        }
    }; 
}