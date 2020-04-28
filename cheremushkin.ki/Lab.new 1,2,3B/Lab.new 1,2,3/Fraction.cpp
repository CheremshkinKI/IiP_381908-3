#include "Fraction.h"
#include <iostream>
using namespace std;
int Fraction:: getA() const
{
	return this-> a;
}
int Fraction:: getB() const
{
	return this->b;
}
void Fraction:: setA(int newA) 
{
	this->a = newA;
}
void Fraction:: setB(int newB) 
{
	this->b = newB;
}
Fraction::Fraction(int h, int j) 
{
	a = h;
	b = j;
}
Fraction::Fraction(const Fraction& tmp)
{
	a = tmp.a;
	b = tmp.b;
}
Fraction::Fraction()
{
	a = 0;
	b = 0;
}
Fraction& Fraction ::operator=(const Fraction& tmp)
{
	a = tmp.a;
	b = tmp.b;
	return *this;
}
Fraction Fraction::operator -(const Fraction& tmp)const
{
	int r, d;
	r = a * tmp.b - tmp.a * b;
	d = b * tmp.b;
	Fraction res(r, d);
	cout << "Constuctor" << &res;
	return res;
}
Fraction Fraction ::operator +(const Fraction& tmp)const
{
	int r, d;
	r = a * tmp.b + tmp.a * b;
	d = b * tmp.b;
	Fraction res(r, d);
	return res;
}
Fraction Fraction:: operator / (const Fraction& tmp)const
{
	int r, d;
	r = a * tmp.b;
	d = b * tmp.a;
	Fraction res(r, d);
	return res;
}
Fraction Fraction:: operator* (const Fraction& tmp)const
{
	int r, d;
	r = a * tmp.a;
	d = b * tmp.b;
	Fraction res(r, d);
	return res;
}
Fraction &Fraction :: operator+(const int h)
{

	if (b != 0)
	{
		a = a + b * h;
		//b = b;
	}
	else
	{
		a = a + h;
		b = 1;
	}
	return *this;
}
Fraction &Fraction::operator-(const int h)
{
	
	if (b != 0)
	{
		a = a - b * h;
		//b = b;
	}
	else
	{
		a = a - h;
		b = 1;
	}
	return *this;
}
Fraction& Fraction::operator*(const int h)
{
	
	a=a*h;
//	b = b;
	return *this;
}
Fraction& Fraction::operator/(const int h)
{
	
//	A.a = a;
	b =b*h;
	return *this;
}
