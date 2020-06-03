// Файл Vector.cpp ---------------------------------------
#include <iostream>
//#include <fstream>
using namespace std;
//extern std::ofstream cout;
#include "Vector.h"
#include <math.h>
Vector::Vector()
{
	cout << this << endl << "DefoltK"<<endl;
	Size = 3;
	Data = new double[Size];//поставить 10 ,если надо будет 
	for (int i = 0; i < Size; i++)
	{
		Data[i] = 0;//поставить 0 
	}
}
Vector::Vector(int size)
{
	cout << this << endl << "SizeK"<<endl;
	Data = new double[size];
	Size = size;
	for (int i = 0; i < size; i++)
	{
		Data[i] = i;
	}
}
Vector::Vector(int size, double* data)
{
	cout << this << endl << "SizeDataK" << endl;
	if (data == NULL)
	{
		throw std::exception("Error");
	}
	else
	{
		Size = size;
		Data = new double[Size];
		for (int i = 0; i < Size; i++)
		{
			Data[i] = data[i];
		}
	}
}
Vector::Vector(const Vector& vector)
{
	if (vector.Data == NULL)
	{
		throw std::exception("Error");
	}
   /*f (this->Data != NULL)
	{
		delete[] this->Data;
	}*/
	//Data=nullptr;
	Size = vector.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = vector.Data[i];
	}
}
Vector& Vector::operator=(const Vector& vector)
{
/*	if (vector.Data == NULL)
	{
		throw std::exception("Error");
	}
	if (Size != vector.Size)
	{
		throw std::exception("Left operant != Right operant");
	}

	if (this->Data != NULL)
	{
		delete[] this->Data;
	}*/
	Size = vector.Size;
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = vector.Data[i];
	}
	return*this;
}
Vector Vector::operator+(const Vector& tmp) const
{
	double* rres = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		rres[i] = Data[i] + tmp.Data[i];
	}
	Vector Res =  Vector(Size, rres);
	return Res;
}
Vector Vector::operator-(const Vector& tmp) const
{
	double* rres = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		rres[i] = Data[i] - tmp.Data[i];
	}
	Vector Res = Vector(Size, rres);
	return Res;
}
/*
double Vector::operator+(const Vector& tmp) const
{
	if (tmp.Data == NULL)
	{
		throw std::exception("Error");
	}
	if (Size != tmp.Size)
	{
		throw std::exception("Left operant != Right operant");
	}
	/*
	double* rres = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		rres[i] = Data[i] + tmp.Data[i];
	}
	Vector Res = new Vector(Size, rres);
	return Res;
	//
	double dll1, dll2;
	dll1 = GetLegth();
	dll2 = tmp.GetLegth();
	double Angle;
	Angle = GetCosA(tmp);
	double res;
	res = sqrt((dll1 * dll1 + dll2 * dll2) - 2 * dll1 * dll2 * Angle);
	return res;
}
double Vector::operator-(const Vector& tmp) const
{
	if (tmp.Data == NULL)
	{
		throw std::exception("Error");
	}
	if (Size != tmp.Size)
	{
		throw std::exception("Left operant != Right operant");
	}
	/*
	double* rres = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		rres[i] = Data[i] - tmp.Data[i];
	}
	Vector Res = new Vector(Size, rres);
	return Res;
	//
	double dll1, dll2;
	dll1 = GetLegth();
	dll2 = tmp.GetLegth();
	double Angle;
	Angle = GetCosA(tmp);
	double res;
	res = sqrt((dll1 * dll1 + dll2 * dll2) - 2 * dll1 * dll2 * Angle);
	return res;
}
*/
double Vector::operator*(const Vector& tmp) const
{
	if (tmp.Data == NULL)
	{
		throw std::exception("Error");
	}
	if (Size != tmp.Size)
	{
		throw std::exception("Left operant != Right operant");
	}
	double dll1, dll2;
	dll1 = GetLegth();
	dll2 = tmp.GetLegth();
	double Angle;
	Angle = GetCosA(tmp);
	double res;
	res = dll1*dll2* Angle;
	return res;
}
Vector Vector::operator*(const double tmp)
{
	for (int i = 0; i < Size; i++)
	{
		Data[i] = Data[i] * tmp;
	}
	return *this;
}
Vector::~Vector()
{
	cout << this << endl << "Destuctor"<<endl;
	delete[]this->Data;//?
	this->Data = nullptr;
	Size = 0;
}
void Vector::print()
{
	cout << "Размер: " << Size<< endl;
	cout <<"(";
	for (int i = 0; i < Size; i++)
	{
		//cout << "[" << i<<"]=" << Data[i]<<endl;
		//cout << "(" << Data[i] << ")" << endl;
		if(i==Size-1)
		{
			cout << Data[i];
			break;
		}
		cout << Data[i]<<",";
	}
	cout << ")";
}
void Vector::printToMatrix()
{
	for (int i = 0; i < Size; i++)
	{
		
		cout <<" "<< Data[i];
	}
}

void Vector::printT()
{
	cout << "Размер: " << Size << endl;
	cout << endl << "(";
	for (int i = 0; i < Size; i++)
	{
		//cout << "[" << i<<"]=" << Data[i]<<endl;
		if (i == Size - 1)
		{
			cout << Data[i];
			break;
		}
		cout << Data[i] << "," << endl;
		//cout << Data[i];
	}
	cout << ")";
}
void Vector::SetSize(int s)
{
	Size = s;
}
void Vector::SetData(double* m)
{
	Data = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = m[i];
	}
}
void Vector::SSetData(int index,double type)
{
	Data[index] = type;
}
void Vector::SSSetData(int index, double type)
{
	Data[index] += type;
}
double Vector::GetDataIndex(int index)
{
	return Data[index];
}
double Vector::GetLegth()const
{
	double res = 0;
	if (this->Data != nullptr && this->Size > 0)
	{
		for (int i = 0; i < Size; i++)
		{
			res += Data[i] * Data[i];
		}
		return sqrt(res);
	}
	return -1;
}
double Vector::GetCosA(const Vector& vec2)const
{
	double angle;
	double dl1, dl2;
	dl1 = GetLegth();
	dl2 = vec2.GetLegth();
	double upNum=0, downNum;
	for (int i = 0; i < Size; i++)
	{
		upNum += Data[i] * vec2.Data[i];
	}
	downNum = dl1 * dl2;
	if (upNum == 0)
	{
		return 0;
	}
	if (downNum == 0)
	{
		return upNum;
	}
	angle = upNum / downNum;
	return angle;
}
double Vector::GetDistance(const Vector& vec2) const
{
	double* rres = new double[Size];
	for (int i = 0; i < Size; i++)
	{
		rres[i] = vec2.Data[i]-Data[i] ;
	}
	Vector Res = Vector(Size, rres);
	return Res.GetLegth();
}
double& Vector::operator[](const int index)
{
	if (index < 0 || index >= Size)
	{
		cout << "Пошел ты нахер,козёл!!";//це шутка
		abort();
	}
	return this->Data[index];
	/*double& Vector::operator[](int index) 
	{  if ( index < 0 || index >= count )  
	abort(); // принудительное завершение программы  
	return memo[index];*/
}
// вывод в поток
ostream& operator<<(ostream& stream, const Vector& vec) 
{
	stream <<"Размер: "<< vec.Size << " "<<endl;
	stream << "(";
	for (int i = 0; i < vec.Size; ++i)
	{
		if (i == vec.Size - 1)
		{
			cout << vec.Data[i];
			break;
		}
		stream << vec.Data[i] << ",";
	}
	stream << ")";
	stream << endl;
	return stream;
}
// ввод из потока
istream& operator>>(istream& stream, Vector& vec) 
{
	int strCount;
	stream >> strCount;
	if (vec.Size != strCount)
	{
		if (vec.Data != NULL)
			delete[] vec.Data;
		vec.Size = strCount;
		vec.Data = new double[strCount];
	}
	for (int i = 0; i < vec.Size; ++i)
		stream >> vec.Data[i];
	return stream;
}
