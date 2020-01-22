#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main(int argc, char *argv[])
{
  int a, b;

  std::cin >> a >> b;

  if (b != 0) {
    int quotient = a / b;
    std::cout << quotient;
  } else {
    std::cout << "Impossible";
  }

  return 0;    
}
