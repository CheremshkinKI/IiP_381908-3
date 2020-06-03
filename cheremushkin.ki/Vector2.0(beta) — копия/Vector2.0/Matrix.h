#pragma once
#include <fstream>
using namespace std;
//extern std::ofstream cout;
#include "Vector.h"
class Matrix
{
public:
	Matrix();
	Matrix(int stroki, int stolbiki);
	Matrix(const Matrix& tmp);
	~Matrix();
	Matrix& operator=(const Matrix& tmp);
	Matrix operator+(const Matrix& tmp);
	Matrix operator-(const Matrix& tmp);
	Matrix operator*(const Matrix& tmp);
	Matrix operator/(const Matrix& tmp);
	Matrix operator*(const double tmp);
	Matrix operator^(const double tmp);
	double Determinant()const;

	double GetDeterminant(int str, int cols)const;
	void SetMassToVec(int index,double* mas);

	friend ostream& operator<<(ostream& stream, const Matrix& mat);
//	friend istream& operator>>(istream& stream, Matrix& mat);
private:
	Vector* VecMASS;
	int RowsMatrix ;
	int ColsMatrix ;
	
};
ostream& operator<<(ostream& stream, const Matrix& mat);
//istream& operator>>(istream& stream, Matrix& mat);