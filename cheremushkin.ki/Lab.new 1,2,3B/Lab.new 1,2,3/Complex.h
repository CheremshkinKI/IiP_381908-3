#pragma once
#include <iostream>
#include "Fraction.h"
class Complex
{
public:
    int getARe() const;
    int getBRe() const;
    void setARe(int newA);
    void setBRe(int newB);
    int getAIm() const;
    int getBIm() const;
    void setAIm(int newA);
    void setBIm(int newB);
    void Print();
    Complex();
    Complex(const Complex& tmp);
    Complex(Fraction _re,Fraction _im);
    Complex& operator=(const Complex& tmp);
    Complex operator-(const Complex& tmp)const;
    Complex operator+(const Complex& tmp)const;
    Complex operator/(const Complex& tmp)const;
    Complex operator*(const Complex& tmp)const;
    Complex& operator++(int);
    Complex& operator++();
    Complex& operator--(int);
    Complex& operator*(const int h);
    Complex &operator/(const int h);
    Complex& operator+(const int h);
    Complex& operator-(const int h);
    Complex&operator+=(const Complex& tmp);
    Complex& operator-=(const Complex& tmp);
    Complex& operator+=(const int h);
    Complex& operator-=(const int h);
    Complex& operator%(const int h);
    bool operator==(const Complex& tmp);
    bool operator!=(const Complex& tmp);
    bool operator>(const Complex& tmp);
    bool operator<(const Complex& tmp); 
    bool operator<=(const Complex& tmp);
    bool operator>=(const Complex& tmp);
    bool operator==(const int h);
    bool operator>(const int h);
    bool operator<(const int h);
private:
    Fraction Re;
    Fraction Im;
};

