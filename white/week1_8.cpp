#include <iostream>

int euclid(int m, int n) {
  int r = m % n;
  if (r == 0) {
    return n;
  } else {
    return euclid(n, r);
  }
}

int main(int argc, char *argv[])
{
  int m, n;
  std::cin >> m >> n;
  std::cout << euclid(m, n);
  return 0;
}

