#include "Ratio.h"
#include <cmath>
using namespace std;

// Constructors
Ratio::Ratio(long numerator, long denominator): num(numerator), denom(denominator){
  if (!denominator)
    throw runtime_error("Denominator cannot be zero.");
}

Ratio::Ratio(int numerator, int denominator): num(numerator), denom(denominator){
  if (!denominator)
    throw runtime_error("Denominator cannot be zero.");
}
// Copy Constructor
Ratio::Ratio(const Ratio &rhs) : num(rhs.num), denom(rhs.denom){
}
// Assignment operator
Ratio &Ratio::operator=(const Ratio &rhs) {
  num = rhs.num;
  denom = rhs.denom;
  return *this;
}
// Getters & Setters
long Ratio::numerator() const {
  return num;
}

long Ratio::denominator() const {
  return denom;
}

void Ratio::numerator(long top){
  num = top;
}

void Ratio::denominator(long bot){
  if (!bot)
    throw runtime_error("Cannot set denominator to zero.");
  denom = bot;
}

// Ratio operations
long double Ratio::ratio(){
  long double upper = num;
  long double lower = denom;
  return upper/lower;
}

Ratio Ratio::add(Ratio r1, Ratio r2, Ratio r3, Ratio r4, Ratio r5, Ratio r6, Ratio r7, Ratio r8){
  return r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8;
}
// Methods for ratio normalization
int Ratio::gcd(int a, int b){
  //This code was copied and adapted from:
  //https://www.w3resource.com/cpp-exercises/for-loop/cpp-for-loop-exercise-9.php
  int gcd = 0;
  for (int i = 1; i <= a && i <= b; i++){
      if (a % i == 0 && b % i == 0){
          gcd = i;
      }
  }
  return gcd;
}

int Ratio::lcm(int a, int b){
  //This was copied and adapted from:
  //https://www.geeksforgeeks.org/program-to-find-lcm-of-two-numbers/
  return (a*b)/gcd(a,b);
}

// Normalize a fraction; This implementation is messy, but it works.
Ratio Ratio::normalize(Ratio a){
  int num = a.numerator();
  int denom = a.denominator();

  if (num == 0){
    a.denominator(1);
    return a;
  }

  else if (num < 0 && denom < 0){
    a.numerator(-1*a.numerator()/gcd(abs(num), abs(denom)));
    a.denominator(-1*a.denominator()/gcd(abs(num), abs(denom)));
    return a;
  }

  a.numerator(-1*abs(a.numerator()/gcd(abs(num), abs(denom))));
  a.denominator(abs(a.denominator()/gcd(abs(num), abs(denom))));
  return a;
}

// Operator overloading
Ratio Ratio::operator+(const Ratio &rhs) const {
  long newNum, newDenom;
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);

  if (rhs.numerator() == 0) //if zero, return left hand side
    return Ratio(num, denom);
  // use normalized ratios to return sum; call lcm to add properly and normalize again.
  


  newNum = num + rhs.numerator();
  newDenom = denom + rhs.denominator();
  return Ratio(newNum, newDenom);
}

// Operator Overloading for extraction and insertion
istream &operator>>(std::istream &is, Ratio &val) {
    long numer, denom;
    char c;
    is >> numer >> c >> denom;
    val.numerator(numer);
    val.denominator(denom);

    return is;
}

ostream &operator<<(ostream &stream, const Ratio &val) {
  return stream << val.numerator() << "/"  << val.denominator() << "\n";
}
