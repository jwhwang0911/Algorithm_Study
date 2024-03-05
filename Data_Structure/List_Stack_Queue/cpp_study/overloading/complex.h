#include<iostream>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  // 재우 바보

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex operator+(const char* str) const;
  Complex operator-(const char* str) const;
  Complex operator*(const char* str) const;
  Complex operator/(const char* str) const;

  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  Complex& operator=(const Complex& c);

  friend Complex operator+(const Complex& a, const Complex& b);

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};