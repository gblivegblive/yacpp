#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  ifstream input("input.txt");
  size_t m, n;
  input >> n >> m;
  int value;

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      input >> value;
      input.ignore(1);
      cout << setw(10);
      cout << value;
      if (j < m - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
