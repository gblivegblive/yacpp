#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Person {
 public:
  void ChangeFirstName(int year, const string &first_name) {
    year_to_first_name[year] = first_name;
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string &last_name) {
    year_to_last_name[year] = last_name;
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    auto first_name_year =
        lower_bound(year_to_first_name.rbegin(), year_to_first_name.rend(),
                    year, [](const pair<int, string> &lhs, const int &rhs) {
                      return lhs.first > rhs;
                    });

    auto last_name_year =
        lower_bound(year_to_last_name.rbegin(), year_to_last_name.rend(), year,
                    [](const pair<int, string> &lhs, const int &rhs) {
                      return lhs.first > rhs;
                    });

    if ((first_name_year != year_to_first_name.rend()) &&
        (last_name_year != year_to_last_name.rend())) {
      return first_name_year->second + " " + last_name_year->second;
    } else if (first_name_year != year_to_first_name.rend()) {
      return first_name_year->second + " with unknown last name";
    } else if (last_name_year != year_to_last_name.rend()) {
      return last_name_year->second + " with unknown first name";
    } else {
      return "Incognito";
    }
    // получить имя и фамилию по состоянию на конец года year
  }
  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
    auto first_name_year =
        lower_bound(year_to_first_name.rbegin(), year_to_first_name.rend(),
                    year, [](const pair<int, string> &lhs, const int &rhs) {
                      return lhs.first > rhs;
                    });

    auto last_name_year =
        lower_bound(year_to_last_name.rbegin(), year_to_last_name.rend(), year,
                    [](const pair<int, string> &lhs, const int &rhs) {
                      return lhs.first > rhs;
                    });

    vector<string> names;

    if ((first_name_year != year_to_first_name.rend()) &&
        (last_name_year != year_to_last_name.rend())) {
      names.push_back(first_name_year->second);
      names.push_back(GetNameHistory(next(first_name_year),
                                     year_to_first_name.rend(),
                                     first_name_year->second));
      names.push_back(last_name_year->second);
      names.push_back(GetNameHistory(next(last_name_year),
                                     year_to_last_name.rend(),
                                     last_name_year->second));

    } else if (first_name_year != year_to_first_name.rend()) {
      names.push_back(first_name_year->second);
      names.push_back(GetNameHistory(next(first_name_year),
                                     year_to_first_name.rend(),
                                     first_name_year->second));
      names.push_back("with unknown last name");
    } else if (last_name_year != year_to_last_name.rend()) {
      names.push_back(last_name_year->second);
      names.push_back(GetNameHistory(next(last_name_year),
                                     year_to_last_name.rend(),
                                     last_name_year->second));
      names.push_back("with unknown first name");
    } else {
      names.push_back("Incognito");
    }

    string output;
    if (!names.empty()) {
      bool need_sep = false;
      for (const auto &name : names) {
        if (!name.empty()) {
          if (need_sep) {
            output = output + " ";
          }
          output = output + name;
          need_sep = true;
        }
      }
    }
    return output;
  }

 private:
  // приватные поля
  map<int, string> year_to_first_name;
  map<int, string> year_to_last_name;

  string GetNameHistory(map<int, string>::reverse_iterator it_start,
                        map<int, string>::reverse_iterator it_end,
                        string current) {
    std::vector<string> names;

    for (auto x = it_start; x != it_end; x++) {
      if (x->second != current) {
        names.push_back(x->second);
        current = x->second;
      }
    }

    string output;
    if (!names.empty()) {
      output += "(";
      bool need_sep = false;
      for (const auto &name : names) {
        if (need_sep) {
          output = output + ", ";
        }
        output = output + name;
        need_sep = true;
      }
      output = output + ")";
    }
    return output;
  }
};

// int main() {
//   Person person;

//   person.ChangeFirstName(1900, "Eugene");
//   person.ChangeLastName(1900, "Sokolov");
//   person.ChangeLastName(1910, "Sokolov");
//   person.ChangeFirstName(1920, "Evgeny");
//   person.ChangeLastName(1930, "Sokolov");
//   cout << person.GetFullNameWithHistory(1940) << endl;

//   return 0;
// }

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}
