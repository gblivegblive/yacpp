#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

int main(int argc, char *argv[])
{

  size_t N;
  std::cin >> N;
  std::string operation;
  std::map<std::string, std::unordered_set<std::string>> bus_to_stops;
  std::map<std::string, std::unordered_set<std::string>> stop_to_buses;

  while (N-- > 0) {
    std::cin >> operation;
    if (operation == "NEW BUS") {
      std::string bus;
      size_t stop_count;
      std::string stop_name;
      std::cin >> bus >> stop_count; 
      while (stop_count-- > 0) {
        std::cin >> stop_name;
        bus_to_stops[bus].insert(stop_name);
        stop_to_buses[stop_name].insert(bus);
      }
    } else if (operation == "BUSES_FOR_STOP") {
      std::string stop_name;
      std::cin >> stop_name;
      if (stop_to_buses.count(stop_name) == 1) {
        for (const auto& bus : stop_to_buses[stop_name]) {
          std::cout << bus << " ";
        }
      } else {
        std::cout << "No stop";        
      }
      std::cout << "\n";      
    } else if (operation == "STOPS_FOR_BUS") {
      std::string bus;
      std::cin >> bus;
      if (stop_to_buses.count(stop_name) == 1) {
        std::unordered_set<std::string> stops = bus_to_stops[bus];
        stops.erase(bus);
        if (not stops.empty()) {
          for (const auto& stop : stops) {
            std::cout << "Stop " << stop << ": ";
            for (const auto& bus : stops) {
          }
        } else {
          std::cout << "";
        }

      } else {
        std::cout << "No bus";        
      }
      std::cout << "\n";      

    } else if (operation == "ALL_BUSES") {

    }
    
  }

  return 0;
}
