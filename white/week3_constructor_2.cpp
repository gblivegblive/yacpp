#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Person {
 public:
  Person(const string &first_name, const string &last_name, int year)
      : birth_year(year) {
    year_to_first_name[year] = first_name;
    year_to_last_name[year] = last_name;
  };

  void ChangeFirstName(int year, const string &first_name) {
    if (year >= birth_year) {
      year_to_first_name[year] = first_name;
    }
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string &last_name) {
    if (year >= birth_year) {
      year_to_last_name[year] = last_name;
    }
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) const {
    if (year < birth_year) {
      return "No person";
    }

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
  string GetFullNameWithHistory(int year) const {
    if (year < birth_year) {
      return "No person";
    }
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
    auto first_name_rend = year_to_first_name.rend();
    auto last_name_rend = year_to_last_name.rend();
    auto next_first_name = next(first_name_year);
    auto next_last_name = next(last_name_year);

    if ((first_name_year != year_to_first_name.rend()) &&
        (last_name_year != year_to_last_name.rend())) {
      names.push_back(first_name_year->second);
      names.push_back(GetNameHistory(next_first_name, first_name_rend,
                                     first_name_year->second));
      names.push_back(last_name_year->second);
      names.push_back(GetNameHistory(next_last_name, last_name_rend,
                                     last_name_year->second));
    } else if (first_name_year != year_to_first_name.rend()) {
      names.push_back(first_name_year->second);
      names.push_back(GetNameHistory(next_first_name, first_name_rend,
                                     first_name_year->second));
      names.push_back("with unknown last name");
    } else if (last_name_year != year_to_last_name.rend()) {
      names.push_back(last_name_year->second);
      names.push_back(GetNameHistory(next_last_name, last_name_rend,
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
  const int birth_year;
  map<int, string> year_to_first_name;
  map<int, string> year_to_last_name;

  string GetNameHistory(map<int, string>::const_reverse_iterator &it_start,
                        map<int, string>::const_reverse_iterator &it_end,
                        string current) const {
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
//   Person person("Polina", "Sergeeva", 1960);
//   for (int year : {1959, 1960}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   person.ChangeFirstName(1965, "Appolinaria");
//   person.ChangeLastName(1967, "Ivanova");
//   for (int year : {1965, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }

//   return 0;
// }
