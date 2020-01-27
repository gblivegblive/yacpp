#include <iostream>
#include <string>
#include <algorithm>

bool IsPalindrom(std::string word){
  std::string original = word;
  std::reverse(word.begin(), word.end());
  return word == original;
}
