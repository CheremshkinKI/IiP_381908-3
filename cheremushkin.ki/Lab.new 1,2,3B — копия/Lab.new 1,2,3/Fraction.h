#pragma once
#include "Fraction.h"
class Fraction
{
public:
    int getA() const;
    int getB() const;
    void setA(int newA);
    void setB(int newB);
    Fraction(int h, int j);
    Fraction(const Fraction& tmp);
    Fraction();
    Fraction& operator=(const Fraction& tmp);
    Fraction operator -(const Fraction& tmp)const;
    Fraction operator +(const Fraction& tmp)const;
    Fraction operator / (const Fraction& tmp)const;
    Fraction operator* (const Fraction& tmp)const;
    Fraction&operator+(const int h);
    Fraction&operator-(const int h);
    Fraction&operator*(const int h);
    Fraction&operator/(const int h);
private:
    int a;
    int b;
};

