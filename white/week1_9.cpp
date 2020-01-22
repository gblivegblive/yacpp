#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  int x;
  std::cin >> x;
  std::vector<int> result;
  
  while (x > 0) {
    result.push_back(x%2);
    x = x / 2;
  }

  for (auto y=result.rbegin(); y<result.rend(); y++) {
        std::cout << *y;
  }

  return 0;
}
