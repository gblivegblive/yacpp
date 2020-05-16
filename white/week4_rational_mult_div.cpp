#include <iostream>
#include <numeric>
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

  friend bool operator==(Rational const &lhs, Rational const &rhs);
  friend bool operator!=(Rational const &lhs, Rational const &rhs);
  friend Rational operator+(Rational const &lhs, Rational const &rhs);
  friend Rational operator-(Rational const &lhs, Rational const &rhs);
  friend Rational operator*(Rational const &lhs, Rational const &rhs);
  friend Rational operator/(Rational const &lhs, Rational const &rhs);
  friend std::ostream &operator<<(std::ostream &os, const Rational &obj);

 private:
  int ir_numerator;
  int ir_denominator;
};

std::ostream &operator<<(std::ostream &os, const Rational &obj) {
  os << obj.ir_numerator << "/" << obj.ir_denominator << endl;
  ;
  return os;
}

bool operator==(Rational const &lhs, Rational const &rhs) {
  return (lhs.ir_numerator == rhs.ir_numerator) &
         (lhs.ir_denominator == rhs.ir_denominator);
}

bool operator!=(Rational const &lhs, Rational const &rhs) {
  return !(lhs == rhs);
}

Rational operator+(Rational const &lhs, Rational const &rhs) {
  return Rational{
      lhs.Numerator() * rhs.Denominator() + lhs.Denominator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()};
}

Rational operator-(Rational const &lhs, Rational const &rhs) {
  return Rational{
      lhs.Numerator() * rhs.Denominator() - lhs.Denominator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()};
}

Rational operator*(Rational const &lhs, Rational const &rhs) {
  return Rational(lhs.Numerator() * rhs.Numerator(),
                  lhs.Denominator() * rhs.Denominator());
}

Rational operator/(Rational const &lhs, Rational const &rhs) {
  return Rational(lhs.Numerator() * rhs.Denominator(),
                  lhs.Denominator() * rhs.Numerator());
}

int main() {
  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;
    bool equal = c == Rational(8, 9);
    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;
      return 1;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;
    bool equal = c == Rational(2, 3);
    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;
      return 2;
    }
  }

  cout << "OK" << endl;
  return 0;
}
