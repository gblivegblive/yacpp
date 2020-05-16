#include <string>
using namespace std;

struct Specialization {
  string name;
  explicit Specialization(string input) { name = input; };
  operator string() const { return name; }
};

struct Course {
  string name;
  explicit Course(string input) { name = input; };
  operator string() const { return name; }
};

struct Week {
  string name;
  explicit Week(string input) { name = input; };
  operator string() const { return name; }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization spec, Course cour, Week w)
      : specialization(spec), course(cour), week(w){};
};

// int main(int argc, char *argv[]) {
//   LectureTitle title(Specialization("C++"), Course("White belt"),
//   Week("4th"));

//   return 0;
// }
