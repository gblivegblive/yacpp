#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
// Реализуйте функции и методы классов и при необходимости добавьте свои
using namespace std;

class Date {
 public:
  Date() = default;
  Date(int year, int month, int day) {
    if ((month < 1) || (month > 12)) {
      cout << "Month value is invalid: " << month << endl;
      throw invalid_argument("wrong month");
    }
    if ((day < 1) || (day > 31)) {
      cout << "Day value is invalid: " << day << endl;
      throw invalid_argument("wrong day");
    }
    year_ = year;
    month_ = month;
    day_ = day;
  }
  int GetYear() const { return year_; };
  int GetMonth() const { return month_; };
  int GetDay() const { return day_; };
  friend std::istream& operator>>(std::istream& is, Date& obj);
  friend std::ostream& operator<<(std::ostream& os, const Date& obj);
  friend bool operator<(const Date& lhs, const Date& rhs);

 private:
  int year_;
  int month_;
  int day_;
};

bool operator<(const Date& lhs, const Date& rhs) {
  vector<int> lhsv = {lhs.year_, lhs.month_, lhs.day_};
  vector<int> rhsv = {rhs.year_, rhs.month_, rhs.day_};
  return lhsv < rhsv;
};

std::ostream& operator<<(std::ostream& os, const Date& obj) {
  std::cout << std::setfill('0') << std::setw(4);
  os << obj.year_;
  os << '-';
  std::cout << std::setfill('0') << std::setw(2);
  os << obj.month_;
  os << '-';
  std::cout << std::setfill('0') << std::setw(2);
  os << obj.day_;
  return os;
}

std::istream& operator>>(std::istream& is, Date& obj) {
  int year, month, day;
  char sep1, sep2;
  if (is) {
    is >> year >> sep1 >> month >> sep2 >> day;
    if (!is.eof()) {
      char nextsymbol = is.peek();
      if (!isspace(nextsymbol)) {
        is.setstate(ios::failbit);
        return is;
      }
    }
    if (is && (sep1 == '-') && (sep2 == '-')) {
      obj = Date(year, month, day);
    }
  }
  return is;
}

class Database {
 public:
  void AddEvent(const Date& date, const string& event) {
    events[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if ((events.count(date) > 0) && (events.at(date).count(event) > 0)) {
      events[date].erase(event);
      cout << "Deleted successfully" << endl;
      return true;
    } else {
      cout << "Event not found" << endl;
      return false;
    }
  }

  int DeleteDate(const Date& date) {
    int N = events[date].size();
    cout << "Deleted " << N << " events" << endl;
    events[date].clear();
    return N;
  }

  void Find(const Date& date) const {
    if (events.count(date) > 0) {
      for (const auto& s : events.at(date)) {
        cout << s << endl;
      }
    }
  };

  void Print() const {
    for (const auto& record : events) {
      if (record.first.GetYear() >= 0) {
        for (const auto& event : record.second) {
          cout << record.first << " " << event << endl;
        }
      }
    }
  };

 private:
  map<Date, set<string>> events;
};

void PrintWrongDate(string& command) {
  std::istringstream isserror(command);
  string dump, wrongdate;
  isserror >> dump >> wrongdate;
  cout << "Wrong date format: " << wrongdate << endl;
}

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    std::istringstream iss(command);
    string op;
    Date date;
    string event;
    if (iss >> op) {
      if (op == "Add") {
        try {
          iss >> date;
        } catch (invalid_argument&) {
          return 1;
        }
        if (iss) {
          iss >> event;
          db.AddEvent(date, event);
        } else {
          PrintWrongDate(command);
          return 1;
        }
      } else if (op == "Del") {
        try {
          iss >> date;
        } catch (invalid_argument&) {
          return 1;
        }
        if (iss) {
          if (iss >> event) {
            db.DeleteEvent(date, event);
          } else {
            db.DeleteDate(date);
          }
        } else {
          PrintWrongDate(command);
          return 1;
        }
      } else if (op == "Find") {
        try {
          iss >> date;
        } catch (invalid_argument&) {
          return 1;
        }
        if (iss) {
          db.Find(date);
        } else {
          PrintWrongDate(command);
          return 1;
        }
      } else if (op == "Print") {
        db.Print();
      } else {
        cout << "Unknown command: " << op << endl;
        return 1;
      }
    }
    // Считайте команды с потока ввода и обработайте каждую
  }

  return 0;
}
