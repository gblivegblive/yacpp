#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
  int N;
  std::cin >> N;

  std::vector<int> temperature(N);
  int mean = 0;

  for (auto &temp_reading : temperature) {
    std::cin >> temp_reading;
    mean += temp_reading;
  }

  mean = mean / N;
  std::vector<size_t> indexes;
  
  for (int i=0; i<N; i++) {
    if (temperature[i] > mean) {
      indexes.push_back(i);
    }
  }

  std::cout << indexes.size() << std::endl;
  for (auto i : indexes) {
    std::cout << i << " ";
  }

  return 0;
}
 
