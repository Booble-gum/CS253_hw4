#include "Ratio.h"
using namespace std;

// Constructors
Ratio::Ratio(long numerator, long denominator): num(numerator), denom(denominator){
  if (!denominator)
    throw runtime_error("Divisor of zero.");
}

Ratio::Ratio(int numerator, int denominator): num(numerator), denom(denominator){
  if (!denominator)
    throw runtime_error("Divisor of zero.");
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
  Ratio a = normalize(*this);
  return a.num;
}

long Ratio::denominator() const {
  Ratio a = normalize(*this);
  return a.denom;
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
long double Ratio::ratio() const{
  long double upper = num, lower = denom;
  return upper/lower;
}

Ratio Ratio::add(Ratio r1, Ratio r2, Ratio r3, Ratio r4, Ratio r5, Ratio r6, Ratio r7, Ratio r8){
    return *this + r1 + r2 + r3 + r4 + r5 + r6 + r7 + r8; 
}
Ratio Ratio::subtract(Ratio r2){ return *this - r2; }

Ratio Ratio::multiply(Ratio r2){ return *this * r2; }

Ratio Ratio::divide(Ratio r2){ return *this / r2;}

int Ratio::compare(Ratio r2){
    Ratio a = normalize(*this);
    Ratio b = normalize(r2);
    if (*this == r2)
        return 0;
    else if (a.numerator() - b.numerator() > 0)
        return 1;
    return -1;
}

int Ratio::compare(long double val){
  // the value passed in can be turned into a ratio over 1.
  // normalize both ratios and then call compare??
    long double a = normalize(*this).ratio();
    if (a == val)
        return 0;
    if (a > val)
        return 1;
    return -1;
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
  int num = a.num;
  int denom = a.denom;

  if (num == 0){
    a.denominator(1);
    return a;
  }

  if (num < 0 && denom < 0){
    a.numerator(-1*a.num/gcd(abs(num), abs(denom)));
    a.denominator(-1*a.denom/gcd(abs(num), abs(denom)));
    return a;
  }
  else if (num < 0 || denom < 0){
    a.numerator(-1*abs(a.num/gcd(abs(num), abs(denom))));
    a.denominator(abs(a.denom/gcd(abs(num), abs(denom))));
    return a;    
  }
  
  a.numerator(abs(a.num/gcd(abs(num), abs(denom))));
  a.denominator(abs(a.denom/gcd(abs(num), abs(denom))));
  return a;
}

// Operator overloading
Ratio Ratio::operator+(const Ratio &rhs) const {
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);
  
  if (rhs.numerator() == 0) //if zero, return left hand side
    return Ratio(a.num, a.denom);
  
  long newDenom = gcd(a.denominator(), b.denominator())*lcm(a.denominator(), b.denominator());
  long newNum = a.numerator()*(newDenom/a.denominator()) + b.numerator()*(newDenom/b.denominator());
  
  return normalize(Ratio(newNum, newDenom));
}

Ratio Ratio::operator-(const Ratio &rhs) const {
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);
  b.numerator(-1*b.numerator());  
  return a + b;  
}

Ratio Ratio::operator*(const Ratio &rhs) const {
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);
   
  return normalize(Ratio(a.numerator()*b.numerator(), a.denominator()*b.denominator()));  
}

Ratio Ratio::operator/(const Ratio &rhs) const {
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);
  long bnum, bdnum;
  bnum = b.denominator();
  bdnum = b.numerator();
  b = Ratio(bnum, bdnum);
   
  return a * b; 
}

bool Ratio::operator==(const Ratio &rhs) const {
  Ratio a = normalize(*this);
  Ratio b = normalize(rhs);
  if (a.numerator() == b.numerator() && a.denominator() == b.denominator())
      return true;
  return false; 
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
  return stream << val.numerator() << "/"  << val.denominator();
}
