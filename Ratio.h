#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED

#include <iostream>

class Ratio {
  public:
    // Constructors
    Ratio() = delete;
    Ratio(double numerator, double denominator = 1) = delete;
    Ratio(float numerator, float denominator = 1) = delete;
    Ratio(long double numerator, long double denominator = 1) = delete;
    Ratio(long numerator, long denominator = 1);
    Ratio(int numerator, int denominator = 1);
    Ratio(const Ratio &);
   ~Ratio() = default;

    // Assignment operator
    Ratio &operator=(const Ratio &); 

    // Getters
    long numerator() const;
    long denominator() const;

    // Setters
    void numerator(long top);
    void denominator(long bot);

    // Methods for normalization
    static Ratio normalize(Ratio a);

    // Ratio operations
    long double ratio() const;
    Ratio add(Ratio r1 = 0, Ratio r2 = 0, Ratio r3 = 0, Ratio r4 = 0, Ratio r5 = 0, Ratio r6 = 0, Ratio r7 = 0, Ratio r8 = 0);
    Ratio subtract(Ratio r2);
    Ratio multiply(Ratio r2);
    Ratio divide(Ratio r2);
    int compare(Ratio r2);
    int compare(long double val);
    
    
    // Operator overloading
    Ratio operator+(const Ratio &) const;
    Ratio operator-(const Ratio &) const;
    Ratio operator*(const Ratio &) const;
    Ratio operator/(const Ratio &) const;
    bool operator==(const Ratio &) const;

  private:
    long num, denom;

    // Helper functions for math; only called within the class.
    static int gcd(int a, int b);
    static int lcm(int a, int b);
  };

  // Stream operator overloads
  std::istream &operator>>(std::istream &is, Ratio &f);
  std::ostream &operator<<(std::ostream &, const Ratio &);

#endif /* RATIO_H_INCLUDED */
