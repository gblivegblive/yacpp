// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination) {
  for (auto w : source) {
    destination.push_back(w);
  }
  source.clear();
}


// int main(int argc, char *argv[])
// {
//   vector<string> source = {"a", "b", "c"};
//   vector<string> destination = {"z"};
//   MoveStrings(source, destination);
//   cout << source.empty() << endl;
//   for (auto w : destination) {
//     cout << w << " ";
//   }
//   return 0;
// }
