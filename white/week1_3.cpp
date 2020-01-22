#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main(int argc, char *argv[])
{
  float a, b, c;

  std::cin >> a >> b >> c;

  if (a != 0) {
    float D = b * b - 4 * a * c;

    if (D > 0) {
      std::cout << (-b + std::sqrt(D)) / (2 * a) << " " << (-b - std::sqrt(D)) / (2 * a);
    } else if (D == 0) {
      std::cout << -b / (2 * a);
    };
  } else {
    if (b != 0) {
      std::cout << -c / b;    
    }
  }

  return 0;
    
}
