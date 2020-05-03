#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	Vector(int size, double* data);
	Vector(int size);//0 вектор ,все нулями 
	Vector(const Vector& tmp);
	Vector& operator=(const Vector& tmp);
//	double operator+(const Vector& tmp)const;
//	double operator-(const Vector& tmp)const;
	Vector operator+(const Vector& tmp)const;
	Vector operator-(const Vector& tmp)const;
	double operator*(const Vector& tmp)const;
	Vector operator*(const double tmp);
	//Vector& operator/(const Vector& tmp)const;
	// Matrix operator*(const Vector& tmp)const;//массив векторов-матрица Д/З
	//Matrix -новыи класс-хранилище массивов векторо
	// <,=,>,!=,[]
	void print();
	void SetSize(int s);
	void SetData(double* m);
	double GetLegth()const;
	double GetCosA(const Vector& vec2)const;
	double GetDistance(const Vector& vec2)const;
private:
	int  Size;//кол-во направлении (x,y,z)
	double* Data;
};


