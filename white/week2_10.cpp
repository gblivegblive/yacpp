#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

int main(int argc, char *argv[])
{
  int N;
  std::cin >> N;

  size_t current_month = 1;
  size_t next_month;
  std::map<size_t, size_t> number_of_days =
    { {1, 31},
      {2, 28},
      {3, 31},
      {4, 30},
      {5, 31},
      {6, 30},
      {7, 31},
      {8, 31},
      {9, 30},
      {10, 31},
      {11, 30},
      {12, 31}};

  std::map<size_t, std::set<std::string>> diary;

  std::string operation;
  size_t day;
  std::string task;

  for (size_t i = 0; i < N; ++i) {
    std::cin >> operation;
    if (operation == "ADD") {
      std::cin >> day >> task;
      diary[day].insert(task);
    } else if (operation == "DUMP") {
      std::cin >> day;
      std::cout << diary[day].size() << " ";
      for (const auto &task_name : diary[day]) {
        std::cout << task_name << " ";
      }
      std::cout << std::endl;
    } else if (operation == "NEXT") {
      next_month = (current_month + 1) % 12;
      if (number_of_days[next_month] < number_of_days[current_month]) {
        for (size_t i=number_of_days[next_month]+1; i<=number_of_days[current_month]; i++) {
          diary[number_of_days[next_month]].insert(diary[i].begin(), diary[i].end());
          diary[i].clear();
        }
      }
      current_month = next_month;
    }
  }
  return 0;
}
