#include <iostream>
#include <vector>
#include <numeric>
#include <string>

int main(int argc, char *argv[])
{
  int N;
  std::cin >> N;

  std::string operation;
  int ops_count;

  std::vector<int> queue;

  for (size_t i = 0; i < N; ++i) {
    std::cin >> operation;
    if (operation != "WORRY_COUNT") {
      std::cin >> ops_count;
    }
    if (operation == "WORRY") {
      queue[ops_count] = 1;
    } else if (operation == "QUIET") {
      queue[ops_count] = 0;
    } else if (operation == "COME") {
      queue.resize(queue.size() + ops_count, 0);
    } else if (operation == "WORRY_COUNT") {
      std::cout << std::accumulate(queue.begin(), queue.end(), 0) << std::endl;
    }
  }
  return 0;
}
