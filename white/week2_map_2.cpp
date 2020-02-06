#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <vector>

int main(int argc, char *argv[])
{

  size_t N;
  std::cin >> N;
  std::string operation;
  std::map<std::string, std::unordered_set<std::string>> bus_to_stops_set;
  std::map<std::string, std::unordered_set<std::string>> stop_to_buses_set;

  std::map<std::string, std::vector<std::string>> bus_to_stops;
  std::map<std::string, std::vector<std::string>> stop_to_buses;

  while (N-- > 0) {
    std::cin >> operation;
    if (operation == "NEW_BUS") {
      std::string bus;
      size_t stop_count;
      std::string stop_name;
      std::cin >> bus >> stop_count; 
      while (stop_count-- > 0) {
        std::cin >> stop_name;
        auto res = bus_to_stops_set[bus].insert(stop_name);
        if (res.second) {
          bus_to_stops[bus].push_back(stop_name);
        }
        res = stop_to_buses_set[stop_name].insert(bus);
        if (res.second) {
          stop_to_buses[stop_name].push_back(bus);
        }
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
      std::cout << std::endl;      
    } else if (operation == "STOPS_FOR_BUS") {
      std::unordered_set<std::string> buses_at_stop;
      std::vector<std::string> buses_at_stop_ord;
      std::string bus;
      std::cin >> bus;
      if (bus_to_stops.count(bus) == 1) {
        for (const auto &stop : bus_to_stops[bus]) {
          std::cout << "Stop " << stop << ": ";
          buses_at_stop = stop_to_buses_set[stop];
          buses_at_stop.erase(bus);
          if (not buses_at_stop.empty()) {
            buses_at_stop_ord = stop_to_buses[stop];
            for (const auto& b : buses_at_stop_ord) {
              if (b != bus) {
                std::cout << b << " ";
              }
            }
          } else {
              std::cout << "no interchange";
          }
          std::cout << std::endl;
        }
      } else {
        std::cout << "No bus" << std::endl;        
      }
    } else if (operation == "ALL_BUSES") {
      if (not bus_to_stops.empty()) {
        for (const auto &bus_stops : bus_to_stops) {
          std::cout << "Bus " << bus_stops.first << ": ";
          for (const auto &stop : bus_stops.second) {
            std::cout << stop << " ";
          }
          std::cout << std::endl;
        }
      } else {
        std::cout << "No buses" << std::endl;
      }
    }    
  }

  return 0;
}
