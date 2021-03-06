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

    if ((first_name_year != year_to_first_name.rend()) &&
        (last_name_year != year_to_last_name.rend())) {
      return first_name_year->second + " " +
             GetNameHistory(next(first_name_year), year_to_first_name.rend()) +
             " " + last_name_year->second + " " +
             GetNameHistory(next(last_name_year), year_to_last_name.rend());
    } else if (first_name_year != year_to_first_name.rend()) {
      return first_name_year->second + " " +
             GetNameHistory(next(first_name_year), year_to_first_name.rend()) +
             " with unknown last name";
    } else if (last_name_year != year_to_last_name.rend()) {
      return last_name_year->second + " " +
             GetNameHistory(next(last_name_year), year_to_last_name.rend()) +
             " with unknown first name";
    } else {
      return "Incognito";
    }
  }

 private:
  // приватные поля
  map<int, string> year_to_first_name;
  map<int, string> year_to_last_name;

  string GetNameHistory(map<int, string>::iterator it_start,
                        map<int, string>::iterator it_end) {
    std::vector<string> names;

    for (x = it_start; x != it_end; x++) {
      if ((names.empty()) || (names.back() != x->second)) {
        names.push_back(x->second);
      }
    }

    if (!names.empty()) {
      string output = "(";
      for (const auto &name : names) {
        output = output + name + ", ";
      }
      output = output + ")";
    } else {
      string output;
    }
    return output;
  };

// int main() {
//   Person person;

//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullName(year) << endl;
//   }

//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }

//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullName(year) << endl;
//   }

//   return 0;
// }
