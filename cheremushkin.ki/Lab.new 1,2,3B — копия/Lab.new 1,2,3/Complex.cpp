#include "Complex.h"
#include "Fraction.h"
#include <iostream>
using namespace std;
Complex::Complex()
{
	Re.setA(0);
	Re.setB(0);
	Im.setA(0);
	Im.setB(0);
}
Complex::Complex(Fraction _re, Fraction _im)
{
	Re.setA (_re.getA());
	Re.setB (_re.getB());
	Im.setA (_im.getA());
	Im.setB (_im.getB());
}
Complex::Complex(const Complex& tmp)
{
	Re.setA(tmp.Re.getA());
	Re.setB(tmp.Re.getB());
	Im.setA(tmp.Im.getA());
	Im.setB(tmp.Im.getB());
}
Complex& Complex:: operator=(const Complex& tmp)
{
	Re.setA(tmp.Re.getA());
	Re.setB(tmp.Re.getB());
	Im.setA(tmp.Im.getA());
	Im.setB(tmp.Im.getB());
	return *this;
}
Complex Complex ::operator-(const Complex& tmp)const
{
	Fraction __re = Fraction();
	Fraction __im = Fraction();
	__re.setA(Re.getA() * tmp.Re.getB() - tmp.Re.getA() * Re.getB());
	__re.setB(Re.getB() * tmp.Re.getB());
	__im.setA(Im.getA() * tmp.Im.getB() - tmp.Im.getA() * Im.getB());
	__im.setB(Im.getB() * tmp.Im.getB());
	Complex res(__re, __im);
	return res;
}
Complex Complex:: operator+(const Complex& tmp)const
{
	Fraction __re = Fraction();
	Fraction __im = Fraction();
	if (Re.getA() == 0 && Re.getB() == 0)
	{
		__re.setA(tmp.Re.getA());
		__re.setB(tmp.Re.getB());
		__im.setA(tmp.Im.getA());
		__im.setB(tmp.Im.getB());
		Complex res(__re, __im);
		return res;
	}
	if (tmp.Re.getA() == 0 && tmp.Re.getB() == 0)
	{
		__re.setA(Re.getA());
		__re.setB(Re.getB());
		__im.setA(Im.getA());
		__im.setB(Im.getB());
		Complex res(__re, __im);
		return res;
	}
	__re.setA(Re.getA() * tmp.Re.getB() + tmp.Re.getA() * Re.getB());
	__re.setB(Re.getB() * tmp.Re.getB());
	__im.setA(Im.getA() * tmp.Im.getB() + tmp.Im.getA() * Im.getB());
	__im.setB(Im.getB() * tmp.Im.getB());
	Complex res(__re, __im);
	return res;
}
Complex Complex:: operator/(const Complex& tmp)const
{
	Fraction __re = Fraction();
	Fraction __im = Fraction();
	__re = (Re * tmp.Re + Im * tmp.Im) / (tmp.Re * tmp.Re + tmp.Im*tmp.Im);
	//__re.setB(Re.getB() * tmp.Re.getB());
	__im = (tmp.Re * Im - Re * tmp.Im) / (tmp.Re * tmp.Re + tmp.Im*tmp.Im);
	//__im.setA(Im.getA() * tmp.Im.getA());
	//__im.setB(Im.getB() * tmp.Im.getB());
	Complex res(__re, __im);
	return res;
}
Complex Complex:: operator*(const Complex& tmp)const
{
	Fraction __re = Fraction();
	Fraction __im = Fraction();
	__re.setA(Re.getA() * tmp.Re.getA() * Im.getB() * tmp.Im.getB()-Im.getA()*tmp.Im.getA()*Re.getB()*tmp.Re.getB());
	//__re.setA(Re.getA() * tmp.Re.getB());
	__re.setB(Re.getA() * tmp.Re.getA() * Im.getB() * tmp.Im.getB());
	//__re.setB(Re.getB() * tmp.Re.getA());
	__im.setA(Re.getA()*tmp.Re.getA()*Im.getB()*tmp.Re.getB()+Im.getA()*tmp.Re.getA()*Re.getB()*tmp.Im.getB());
	//__im.setA(Im.getA() * tmp.Im.getB());
	__im.setB(Re.getB()*tmp.Im.getB()*Im.getB()*tmp.Re.getB());
	//__im.setB(Im.getB() * tmp.Im.getA());
	Complex res(__re, __im);
	return res;
}
Complex&Complex::operator ++(int)
{
	Re + 1;
	return *this;
}
Complex&Complex:: operator++()
{
	Re + 1;
	return *this;
}
Complex& Complex::operator--(int)
{
	Re - 1;
	return *this;
}
Complex&Complex::operator*(const int h)
{
	Re=Re* h;
	Im=Im* h;
	return *this;
}
Complex &Complex::operator/(const int h)
{
	
	Re=Re/ h;
	Im=Im/ h;
	return *this;
}
Complex& Complex::operator+(const int h)
{

	Re = Re+ h;
	//Im = Im;
	return *this;
}
Complex& Complex::operator-(const int h)
{

	Re=Re - h;
	//Im = Im;
	return *this;
}
Complex & Complex::operator+=(const Complex& tmp)
{
	if (Re.getA() != 0 && Im.getA() != 0 && Re.getB() != 0 && Im.getB() != 0)
	{
		Re = (Re + tmp.Re);
		Im = (Im + tmp.Im);
	}
	else
	{
		Re =  tmp.Re;
		Im =  tmp.Im;
	}
	return *this;
}
Complex& Complex::operator-=(const Complex& tmp)
{
	if (Re.getA() != 0 && Im.getA() != 0 && Re.getB() != 0 && Im.getB() != 0)
	{
		Re = (Re - tmp.Re);
		Im = (Im - tmp.Re);
	}
	else
	{
	//	const int f = -1;
		Re.setA(tmp.Re.getA() * -1);
		Re.setB(tmp.Re.getB());
		Im.setA(tmp.Re.getA() * -1);
		Im.setB(tmp.Re.getB());
		//Re = tmp.Re;
		//Im = tmp.Im;
	}
	return *this;
}
Complex& Complex::operator+=(const int h)
{
	if (Re.getA() != 0 && Im.getA() != 0 && Re.getB()!=0&&Im.getB()!=0)
	{
		Re + h;
		Im + h;
		return*this;
	}
	else
	{
		Re.setA(h);
		Re.setB(1);
		Im.setA(h);
		Im.setB(1);
		return*this;
	}
}
Complex& Complex::operator-=(const int h)
{
	if (Re.getA() != 0 && Im.getA() != 0 && Re.getB() != 0 && Im.getB() != 0)
	{
		Re - h;
		Im - h;
		return*this;
	}
	else
	{
		Re.setA(-h);
		Re.setB(1);
		Im.setA(-h);
		Im.setB(1);
		return*this;
	}
}
Complex& Complex::operator%(const int h)
{
	if (Re.getA() % Re.getB() == 0)
	{
		int res1, ost1;
		res1 = Re.getA() / Re.getB();
		ost1 = res1 % h;
		Re.setB(1);
		Re.setA(ost1);
	}
	else
	{
		cout << "Невозможно вывявить остаток от деления вещественного числа";
	}
	if (Im.getA() % Im.getB() == 0)
	{
		int res1, ost1;
		res1 = Im.getA() / Im.getB();
		ost1 = res1 % h;
		Im.setB(1);
		Im.setA(ost1);
	}
	else
	{
		cout << "Невозможно вывявить остаток от деления мнимого числа";
	}
	return*this;
}
bool Complex:: operator == (const Complex& tmp)
{
	bool Res;
	if (Re.getA() == tmp.Re.getA() && Re.getB() == tmp.Re.getB()&&Im.getA()==tmp.Im.getA()&&Im.getB()==tmp.Im.getB())
	{
		cout << endl<<endl<< "Комплексные числа равны" << endl;
	    Res = true;
	}
	else
	{
		cout <<endl<<endl<< "Комлексные числа не равны :(";
		Res = false;
	}
	return Res;
}
bool Complex:: operator != (const Complex& tmp)
{
	bool Res;
	if (Re.getA() == tmp.Re.getA() && Re.getB() == tmp.Re.getB() && Im.getA() == tmp.Im.getA() && Im.getB() == tmp.Im.getB())
	{
		cout << endl << endl << "Комплексные числа равны" << endl;
		Res = false;
	}
	else
	{
		cout << endl << endl << "Комлексные числа не равны :(";
		Res = true;
	}
	return Res;
}
bool Complex::operator>(const Complex& tmp)
{
	bool Res;
	if ((Re.getA() * tmp.Re.getB() - tmp.Re.getA() * Re.getB())>0 && (Im.getA() * tmp.Im.getB() - tmp.Im.getA() * Im.getB())>0)
	{
		cout << endl << endl << "Левый опперант больше правого" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Меньше либо равен :(";
		Res = false;
	}
	return Res;
}
bool Complex::operator<(const Complex& tmp)
{
	bool Res;
	if ((Re.getA() * tmp.Re.getB() - tmp.Re.getA() * Re.getB()) < 0 && (Im.getA() * tmp.Im.getB() - tmp.Im.getA() * Im.getB()) < 0)
	{
		cout << endl << endl << "Левый опперант меньше правого" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Больше либо равен :(";
		Res = false;
	}
	return Res;
}
bool Complex::operator<=(const Complex& tmp)
{
	bool Res;
	if ((Re.getA() * tmp.Re.getB() - tmp.Re.getA() * Re.getB()) <= 0 && (Im.getA() * tmp.Im.getB() - tmp.Im.getA() * Im.getB()) <= 0)
	{
		cout << endl << endl << "Левый опперант меньше либо равен правому" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Больше :(";
		Res = false;
	}
	return Res;
}
bool Complex::operator>=(const Complex& tmp)
{
	bool Res;
	if ((Re.getA() * tmp.Re.getB() - tmp.Re.getA() * Re.getB()) >= 0 && (Im.getA() * tmp.Im.getB() - tmp.Im.getA() * Im.getB()) >= 0)
	{
		cout << endl << endl << "Левый опперант больше либо равен правому" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Меньше:(";
		Res = false;
	}
	return Res;
}
bool Complex::operator==(const int h)
{
	bool Res;
	if (Re.getB() == 0)
	{
		Re.setB(1);
	}
	if (Re.getA()==h*Re.getB())
	{
		cout << endl << endl << "Левый опперант == правому" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Не равен :(";
		Res = false;
	}
	return Res;
}
bool Complex::operator>(const int h)
{
	bool Res;
	if (Re.getB() == 0)
	{
		Re.setB(1);
	}
	if (Re.getA() > h * Re.getB())
	{
		cout << endl << endl << "Левый опперант > правого" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Левый опперант меньше либо равно правому :(";
		Res = false;
	}
	return Res;
}
bool Complex::operator<(const int h)
{
	bool Res;
	if (Re.getB() == 0)
	{
		Re.setB(1);
	}
	if (Re.getA() < h * Re.getB())
	{
		cout << endl << endl << "Левый опперант < правого" << endl;
		Res = true;
	}
	else
	{
		cout << endl << endl << "Левый опперант больше либо равно правому:(";
		Res = false;
	}
	return Res;
}
int Complex :: getARe()const
{
	return this->Re.getA();
}
int Complex::getBRe() const
{
	return this->Re.getB();
}
void Complex::setARe(int newA)
{
	this->Re.setA(newA);
}
void Complex::setBRe(int newB)
{
	this->Re.setB(newB);
}
int Complex::getAIm() const
{
	return this->Im.getA();
}
int Complex::getBIm() const
{
	return this->Im.getB();
}
void Complex::setAIm(int newA)
{
	this->Im.setA(newA);
}
void Complex::setBIm(int newB)
{
	this->Im.setB(newB);
}
void Complex::Print()
{
	cout <<"Real: "<< Re.getA() << "/" << Re.getB()<<endl;
	cout << "Imagination: "<<Im.getA() << "/" << Im.getB() << "*I" << endl;
}