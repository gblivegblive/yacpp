#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream input("input.txt");
  float line;
  cout << fixed << setprecision(3);
  while (input >> line) {
    cout << line << endl;
  };
  return 0;
}
