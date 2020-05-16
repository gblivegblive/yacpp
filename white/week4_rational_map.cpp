#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

class Rational {
 public:
  Rational() {
    ir_numerator = 0;
    ir_denominator = 1;
  }

  Rational(int numerator, int denominator) {
    if (denominator == 0) {
      throw std::invalid_argument("Invalid denominator");
    }
    int sign = 1;
    if ((denominator<0 & numerator> 0) | (denominator > 0 & numerator < 0)) {
      sign = -1;
    }
    int common_divisor = std::gcd(numerator, denominator);
    if (common_divisor != 0) {
      ir_numerator = sign * abs(numerator) / common_divisor;
      ir_denominator = abs(denominator) / common_divisor;
    } else {
      ir_numerator = 0;
      ir_denominator = 0;
    }
  }

  int Numerator() const {
    // Реализуйте этот метод
    return ir_numerator;
  }

  int Denominator() const {
    // Реализуйте этот метод
    return ir_denominator;
  }

  friend bool operator==(const Rational &lhs, const Rational &rhs);
  friend bool operator<(const Rational &lhs, const Rational &rhs);
  friend bool operator!=(const Rational &lhs, const Rational &rhs);
  friend Rational operator+(const Rational &lhs, const Rational &rhs);
  friend Rational operator-(const Rational &lhs, const Rational &rhs);
  friend Rational operator*(const Rational &lhs, const Rational &rhs);
  friend Rational operator/(const Rational &lhs, const Rational &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Rational &obj);
  friend std::istream &operator>>(std::istream &os, Rational &obj);

 private:
  int ir_numerator;
  int ir_denominator;
};

std::ostream &operator<<(std::ostream &os, const Rational &obj) {
  os << obj.ir_numerator << "/" << obj.ir_denominator;
  return os;
}

std::istream &operator>>(std::istream &is, Rational &obj) {
  int numerator;
  int denominator;
  char sep;

  int curpos = is.tellg();

  if (!(is >> numerator)) {
    is.seekg(curpos, is.beg);
    return is;
  }

  if (is.eof() || is.fail() || !(is >> sep) || (sep != '/')) {
    is.seekg(curpos, is.beg);
    return is;
  }

  if (is.peek() == EOF || is.eof() || is.fail() || !(is >> denominator)) {
    is.seekg(curpos, is.beg);
    return is;
  }

  obj = Rational(numerator, denominator);
  return is;
}

bool operator==(const Rational &lhs, const Rational &rhs) {
  return (lhs.ir_numerator == rhs.ir_numerator) &
         (lhs.ir_denominator == rhs.ir_denominator);
}

bool operator!=(const Rational &lhs, const Rational &rhs) {
  return !(lhs == rhs);
}

bool operator<(const Rational &lhs, const Rational &rhs) {
  return (lhs.ir_numerator * rhs.ir_denominator <
          rhs.ir_numerator * lhs.ir_denominator);
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
  return Rational{
      lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
  return Rational{
      lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.Numerator() * rhs.Numerator(),
                  lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator(),
                  lhs.Denominator() * rhs.Numerator());
}

int main() {
  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;
      return 1;
    }

    vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;
      return 2;
    }
  }

  {
    map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
