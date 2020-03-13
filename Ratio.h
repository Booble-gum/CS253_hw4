#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED

#include <iostream>

class Ratio {
  public:
    Ratio() = delete;
    Ratio(double numerator, double denominator) = delete;
    Ratio(float numerator, float denominator) = delete;
    Ratio(long numerator, long denominator = 1);
    Ratio(int numerator, int denominator = 1);
    Ratio(const Ratio &);
   ~Ratio() = default;

    Ratio &operator=(const Ratio &); //assignment operator

    //getters
    long numerator() const;
    long denominator() const;

    //setters
    void numerator(long top);
    void denominator(long bot);

    //methods for normalization
    static Ratio normalize(Ratio a);

    //Ratio operations
    long double ratio();
    Ratio add(Ratio r1 = 0, Ratio r2 = 0, Ratio r3 = 0, Ratio r4 = 0, Ratio r5 = 0, Ratio r6 = 0, Ratio r7 = 0, Ratio r8 = 0);
    static Ratio subtract(Ratio r1, Ratio r2);
    //Operator overloading
    Ratio operator+(const Ratio &) const;
    Ratio operator-(const Ratio &) const;

  private:
    long num, denom;

    //Helper functions for math; only called within the class.
    static int gcd(int a, int b);
    static int lcm(int a, int b);
  }; //end of class header

  // Stream operator overloads
  std::istream &operator>>(std::istream &is, Ratio &f);
  std::ostream &operator<<(std::ostream &, const Ratio &);

#endif /* RATIO_H_INCLUDED */
