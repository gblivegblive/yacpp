#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iterator>

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

map<char, int> BuildCharCounters(const string& word){
  map<char, int> counts;
  for (const char& letter: word){
    ++counts[letter];
  }
  return counts;
}


int main(int argc, char *argv[])
{

  int N;
  cin >> N;
  vector<string> answer;

  while (N > 0) {
    string first_word, second_word;
    cin >> first_word >> second_word;
    if (BuildCharCounters(first_word) == BuildCharCounters(second_word)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
    --N;
  }

  return 0;
}
