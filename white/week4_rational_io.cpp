#include <iostream>
#include <numeric>
#include <sstream>
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

// int main() {
//   {
//     ostringstream output;
//     output << Rational(-6, 8);
//     if (output.str() != "-3/4") {
//       cout << Rational(-6, 8) << endl;
//       cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
//       return 1;
//     }
//   }

//   {
//     istringstream input("5/7");
//     Rational r;
//     input >> r;
//     bool equal = r == Rational(5, 7);
//     if (!equal) {
//       cout << "5/7 is incorrectly read as " << r << endl;
//       return 2;
//     }
//   }

//   {
//     istringstream input("5/7 10/8");
//     Rational r1, r2;
//     input >> r1 >> r2;
//     bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//     if (!correct) {
//       cout << "Multiple values are read incorrectly: " << r1 << " " << r2
//            << endl;
//       return 3;
//     }

//     input >> r1;
//     input >> r2;
//     correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//     if (!correct) {
//       cout << "Read from empty stream shouldn't change arguments: " << r1 <<
//       " "
//            << r2 << endl;
//       return 4;
//     }
//   }

//   cout << "OK" << endl;
//   return 0;
// }

int main(int argc, char *argv[]) {
  Rational r1, r2;
  int r3;
  istringstream input("5");
  input >> r1 >> r2 >> r3;
  cout << r1 << r2 << r3;
  return 0;
}
