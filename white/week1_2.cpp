#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main(int argc, char *argv[])
{
  std::string word;
  std::vector<std::string> inputs;

  while (std::cin >> word) {
    inputs.push_back(word);
  }

  std::cout << *std::min_element(inputs.begin(), inputs.end());
  
  return 0;
    
}
