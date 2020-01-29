#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[])
{

  size_t N;
  std::cin >> N;
  std::string operation, param1, param2;
  std::map<std::string, std::string> countries;

  while (N-- > 0) {
    std::cin >> operation;
    if (operation == "CHANGE_CAPITAL") {
      std::cin >> param1 >> param2; // capital of country param1 is param2
      if (countries.count(param1) == 0) {
        std::cout << "Introduce new country " << param1 << " with capital " << param2 << "\n";
        countries[param1] = param2;        
      } else if (countries[param1] == param2) {
        std::cout << "Country " << param1 << " hasn't changed its capital" << "\n";
      } else {
        std::cout << "Country "<< param1 << " has changed its capital from " << countries[param1] << " to "<< param2 << "\n";
        countries[param1] = param2;        
      }
    } else if (operation == "RENAME") {
      std::cin >> param1 >> param2;  // rename country from param1 to param2
      if ((param1 == param2) || (countries.count(param1) == 0) ||
          (countries.count(param2) == 1)) {
        std::cout << "Incorrect rename, skip" << "\n";
      } else {
        std::cout << "Country " << param1 << " with capital " << countries[param1] << " has been renamed to " << param2 << "\n";
        countries[param2] = countries[param1];  
        countries.erase(param1);
      }

    } else if (operation == "ABOUT") {
      std::cin >> param1;       // print capital of country param1
      if (countries.count(param1) == 0) {
        std::cout << "Country " << param1 << " doesn't exist" << "\n";
      } else {
        std::cout << "Country " << param1 << " has capital " << countries[param1] << "\n";        
      }

    } else if (operation == "DUMP") {
      if (countries.size() == 0) {
        std::cout << "There are no countries in the world" << "\n";
      } else {
        for (auto p : countries) {
          std::cout << p.first << "/" << p.second << " ";
        }
        std::cout << "\n";
      }
    }
    
  }

  return 0;
}
