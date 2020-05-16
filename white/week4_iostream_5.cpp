#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
  string first_name;
  string last_name;
  int day;
  int month;
  int year;

  void PrintName() { cout << first_name << " " << last_name << endl; }
  void PrintDOB() { cout << day << "." << month << "." << year << endl; }
};

int main(int argc, char *argv[]) {
  size_t N;
  cin >> N;
  vector<Student> students;
  for (size_t i = 0; i < N; i++) {
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
    cin >> first_name >> last_name >> day >> month >> year;
    students.push_back({first_name, last_name, day, month, year});
  }

  size_t M;
  cin >> M;
  for (size_t i = 0; i < M; i++) {
    string op;
    size_t index;
    cin >> op >> index;

    if ((op == "name") && (index <= N) && (index > 0)) {
      students[index - 1].PrintName();
    } else if ((op == "date") && (index <= N) && (index > 0)) {
      students[index - 1].PrintDOB();
    } else {
      cout << "bad request" << endl;
    }
  }

  return 0;
}
