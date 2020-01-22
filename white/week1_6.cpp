#include <iostream>

int main(int argc, char *argv[])
{

  int a, b;
  std::cin >> a >> b;
  for (int x = a; x <= b; ++x) {
    if (x % 2 == 0) {
      std::cout << x << " ";
    }
  }
  
  return 0;
}
