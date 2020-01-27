#include <vector>
#include <string>

using namespace std;

vector<string> PalindromFilter(vector<string> words, unsigned int minLength){
  vector<string> output;
  for (auto word: words) {
    if (word.length() >= minLength) {
        string reverse(word.rbegin(), word.rend());
        if (word == reverse) {
          output.push_back(word);
        }
      }
  }
  return output;
}
