#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
  std::string word;
  std::cin >> word;

  int pos = word.find('f');

  if (pos < 0) {
    std::cout << -2;
  } else {
    pos = word.find('f', pos+1);  // -1 if not found
    std::cout << pos;
  }
  
  return 0;
}
