#include <iostream>
#include <vector>
#include <string>
#include <cmath>


int main(int argc, char *argv[])
{
  float n, a, b, x, y;

  std::cin >> n >> a >> b >> x >> y;

  if (n > b) {
    std::cout << n * ((100 - y) / 100);
  } else if (n > a) {
    std::cout << n * ((100 - x) / 100);
  } else {
    std::cout << n;
  }

  return 0;
    
}
