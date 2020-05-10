#include <iostream>
//#include <fstream>
using namespace std;
//extern std::ofstream cout;
#include "Matrix.h"
#include "Vector.h"
#include <math.h>
//#include <new>

Matrix::Matrix()
{
	/*VecMASS = new Vector[3];
	RowsMatrix = 3;//строки-число векторов
	ColsMatrix = 3;//столбцы-кол-во элементов в строке
	for (int i = 0; i < RowsMatrix; i++)
	{
		VecMASS[i] = Vector(3);//поставить 3 в скобки 
	}*/
	RowsMatrix = 3;//строки-число векторов
	ColsMatrix = 3;//столбцы-кол-во элементов в строке
	VecMASS = static_cast<Vector*>(operator new[](RowsMatrix * sizeof(Vector)));
	for (int i = 0; i < RowsMatrix; i++)
	{
		new(VecMASS + i)Vector(ColsMatrix);
	}
}
Matrix::Matrix(int stroki, int stolbiki)
{
	RowsMatrix = stroki;
	VecMASS = new Vector[stroki];
	ColsMatrix = stolbiki;
	for (int i = 0; i < RowsMatrix; i++)
	{
		new(VecMASS + i)Vector(ColsMatrix);
	}
}
Matrix::Matrix(const Matrix& tmp)
{
	RowsMatrix = tmp.RowsMatrix;
	ColsMatrix = tmp.ColsMatrix;
	VecMASS = new Vector[RowsMatrix];
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			//VecMASS[i].SSetData(j, tmp.VecMASS[i].GetDataIndex(j));
			VecMASS[i][j] = tmp.VecMASS[i][j];
		}
	}
}

Matrix::~Matrix()
{
	/*
	RowsMatrix = 0;
	ColsMatrix = 0;
	delete[]this->VecMASS;
	VecMASS = nullptr;
	*/
	cout << "Сработал деструктор"<<endl;
	for (int i = 0; i< RowsMatrix; i++)
	{
		VecMASS[i].~Vector();
	}
	RowsMatrix = 0;
	ColsMatrix = 0;
	//cout << &VecMASS<<endl;
 // operator delete[] (VecMASS);
  // delete[]this->VecMASS;// не рабит , но лучше чем ничего
   VecMASS = nullptr;
}

Matrix& Matrix::operator=(const Matrix& tmp)
{
	RowsMatrix = tmp.RowsMatrix;
	ColsMatrix = tmp.ColsMatrix;
	VecMASS = new Vector[RowsMatrix];
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			//VecMASS[i].SSetData(j, tmp.VecMASS[i].GetDataIndex(j));
			VecMASS[i][j] = tmp.VecMASS[i][j];
		}
	}
return*this;
}

Matrix Matrix::operator+(const Matrix& tmp)
{
	if (RowsMatrix != tmp.RowsMatrix || ColsMatrix != tmp.ColsMatrix)
	{
		throw std::exception("Пошел ты нахер,козёл");
	}
	Matrix res = Matrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			res.VecMASS[i].SSetData(j, VecMASS[i].GetDataIndex(j)+ tmp.VecMASS[i].GetDataIndex(j));
		}
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& tmp)
{
	if (RowsMatrix != tmp.RowsMatrix || ColsMatrix != tmp.ColsMatrix)
	{
		throw std::exception("Пошел ты нахер,козёл");//Отсылка к сериалу Дальнобойщик,эхх настольгия 
	}
	Matrix res = Matrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			res.VecMASS[i].SSetData(j, VecMASS[i].GetDataIndex(j) - tmp.VecMASS[i].GetDataIndex(j));
		}
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& tmp)
{
	if (ColsMatrix != tmp.RowsMatrix)
	{
		throw std::exception("Пошел ты нахер,козёл");//Отсылка к сериалу Дальнобойщик,эхх настольгия 
	}
	Matrix res = Matrix(RowsMatrix, tmp.ColsMatrix);
	//for (int g = 0; g < RowsMatrix * tmp.ColsMatrix;g++)
	//{
		for (int i = 0; i < RowsMatrix; i++)
		{
			for (int j = 0; j < tmp.ColsMatrix; j++)
			{
				res.VecMASS[i].SSSetData(j, VecMASS[i].GetDataIndex(j) * tmp.VecMASS[j].GetDataIndex(i));
			}
		}
	//}
	return res;
}

Matrix Matrix::operator/(const Matrix& tmp)
{
	double detO;
	detO = tmp.Determinant();
	if (detO == 0)
	{
		throw std::exception("Пошел ты нахер,козёл");
	}
	Matrix MINOR= Matrix(tmp.RowsMatrix, tmp.ColsMatrix);
	if (tmp.RowsMatrix == 2)
	{
		double buf1, buf2, buf3, buf4;
		buf1 = MINOR.VecMASS[0].GetDataIndex(0);
		buf2= MINOR.VecMASS[0].GetDataIndex(1);
		buf3= MINOR.VecMASS[1].GetDataIndex(0);
		buf4= MINOR.VecMASS[1].GetDataIndex(1);
		MINOR.VecMASS[0].SSetData(0, buf4);
		MINOR.VecMASS[0].SSetData(1, -buf2);//сразу поставил - т.к. нашли алг доп.
		MINOR.VecMASS[1].SSetData(0, -buf3);//сразу оставил транспанированную 
		MINOR.VecMASS[1].SSetData(1, buf1);
		//--------------------------------------------
		Matrix neres = Matrix(tmp.RowsMatrix, tmp.ColsMatrix);
		neres =  MINOR*(1 / detO);
		Matrix res = Matrix(tmp.RowsMatrix, tmp.ColsMatrix);
		res = neres**this;
		return res;
	}
	if (tmp.RowsMatrix == 3)
	{
		MINOR.VecMASS[0].SSetData(0, GetDeterminant(0,0));
		MINOR.VecMASS[0].SSetData(1, GetDeterminant(0, 1));
		MINOR.VecMASS[0].SSetData(2, GetDeterminant(0, 2));
		MINOR.VecMASS[1].SSetData(0, GetDeterminant(1, 0));
		MINOR.VecMASS[1].SSetData(1, GetDeterminant(1, 1));
		MINOR.VecMASS[1].SSetData(2, GetDeterminant(1, 2));
		MINOR.VecMASS[2].SSetData(0, GetDeterminant(2, 0));
		MINOR.VecMASS[2].SSetData(1, GetDeterminant(2, 1));
		MINOR.VecMASS[2].SSetData(2, GetDeterminant(2, 2));
		//--------------------------------------------
		Matrix neres = Matrix(tmp.RowsMatrix, tmp.ColsMatrix);
		neres = MINOR * (1 / detO);
		Matrix res = Matrix(tmp.RowsMatrix, tmp.ColsMatrix);
		res = neres * *this;
		return res;
	}
}

Matrix Matrix::operator*(const double tmp)
{
	Matrix res = Matrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			res.VecMASS[i].SSetData(j, VecMASS[i].GetDataIndex(j)*tmp);
		}
	}
	return res;
}

Matrix Matrix::operator^(const double tmp)
{
	double buf = 1;
	Matrix res = Matrix(RowsMatrix, ColsMatrix);
	for (int i = 0; i < RowsMatrix; i++)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			for (int g = 0; g < tmp; g++)
			{
				buf *= VecMASS[i].GetDataIndex(j);
			}
			res.VecMASS[i].SSetData(j, buf);
			buf = 1;
		}
	}
	return res;
}

double Matrix::Determinant()const//готов
{
	double r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 1, r6 = 1;
	double res=0;
	double res1, res2, res3, res4;
	if (ColsMatrix != RowsMatrix)
	{
		throw std::exception("Пошел ты нахер,козёл");//Отсылка к сериалу Дальнобойщик,эхх настольгия 
	}
	if (ColsMatrix == 3)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			r1 = r1 * VecMASS[j].GetDataIndex(j);
		}
		r2 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(2) * VecMASS[2].GetDataIndex(0);
		r3 = VecMASS[0].GetDataIndex(2) * VecMASS[1].GetDataIndex(0) * VecMASS[2].GetDataIndex(1);
		int g = 0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			r4 = r4 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r5 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(0) * VecMASS[2].GetDataIndex(2);
		r6 = VecMASS[0].GetDataIndex(0) * VecMASS[1].GetDataIndex(2) * VecMASS[2].GetDataIndex(1);
		return res = r1 + r2 + r3 - r4 - r5 - r6;
	}
	if (ColsMatrix == 2)
	{
		for (int j = 0; j < ColsMatrix; j++)
		{
			r1 = r1 * VecMASS[j].GetDataIndex(j);
		}
		int g = 0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			r2 = r2 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		return res = r1 - r2;
	}
	if (ColsMatrix == 4)
	{
		r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 1, r6 = 1;
		for (int j = 1; j < ColsMatrix; j++)
		{
			r1 = r1 * VecMASS[j].GetDataIndex(j);
		}
		r2 = VecMASS[1].GetDataIndex(1) * VecMASS[2].GetDataIndex(2) * VecMASS[3].GetDataIndex(0);
		r3 = VecMASS[1].GetDataIndex(2) * VecMASS[2].GetDataIndex(0) * VecMASS[3].GetDataIndex(1);
		int k=0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			r4 = r4 * VecMASS[j].GetDataIndex(k);
			k++;
		}
		r5 = VecMASS[1].GetDataIndex(1) * VecMASS[2].GetDataIndex(0) * VecMASS[3].GetDataIndex(2);
		r6 = VecMASS[1].GetDataIndex(0) * VecMASS[2].GetDataIndex(2) * VecMASS[3].GetDataIndex(1);
	    res1 = r1 + r2 + r3 - r4 - r5 - r6;
//-------------------------------------------------------------------------------------------------
		r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 1, r6 = 1;
		int g = 0;
		for (int j = 0; j < ColsMatrix; j++)
		{
			if (j == 1)
			{
				j++;
			}
			r1 = r1 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r2 = VecMASS[0].GetDataIndex(1) * VecMASS[2].GetDataIndex(2) * VecMASS[3].GetDataIndex(0);
		r3 = VecMASS[0].GetDataIndex(2) * VecMASS[2].GetDataIndex(0) * VecMASS[3].GetDataIndex(1);
		g = 0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			if (j == 1)
			{
				j--;
			}
			r4 = r4 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r5 = VecMASS[0].GetDataIndex(1) * VecMASS[2].GetDataIndex(0) * VecMASS[3].GetDataIndex(2);
		r6 = VecMASS[0].GetDataIndex(0) * VecMASS[2].GetDataIndex(2) * VecMASS[3].GetDataIndex(1);
		res2 = r1 + r2 + r3 - r4 - r5 - r6;
//-------------------------------------------------------------------------------------------------
		r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 1, r6 = 1;
		 g = 0;
		for (int j = 0; j < ColsMatrix; j++)
		{
			if (j == 2)
			{
				j++;
			}
			r1 = r1 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r2 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(2) * VecMASS[3].GetDataIndex(0);
		r3 = VecMASS[0].GetDataIndex(2) * VecMASS[1].GetDataIndex(0) * VecMASS[3].GetDataIndex(1);
		g = 0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			if (j == 2)
			{
				j--;
			}
			r4 = r4 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r5 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(0) * VecMASS[3].GetDataIndex(2);
		r6 = VecMASS[0].GetDataIndex(0) * VecMASS[1].GetDataIndex(2) * VecMASS[3].GetDataIndex(1);
		res3 = r1 + r2 + r3 - r4 - r5 - r6;
//--------------------------------------------------------------------------------------------------
		r1 = 1, r2 = 1, r3 = 1, r4 = 1, r5 = 1, r6 = 1;
		 g = 0;
		for (int j = 0; j < ColsMatrix; j++)
		{
			if (j == 3)
			{
				j++;
			}
			r1 = r1 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r2 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(2) * VecMASS[2].GetDataIndex(0);
		r3 = VecMASS[0].GetDataIndex(2) * VecMASS[1].GetDataIndex(0) * VecMASS[2].GetDataIndex(1);
		g = 0;
		for (int j = ColsMatrix-1; j > 0; j--)
		{
			if (j == 3)
			{
				j--;
			}
			r4 = r4 * VecMASS[j].GetDataIndex(g);
			g++;
		}
		r5 = VecMASS[0].GetDataIndex(1) * VecMASS[1].GetDataIndex(0) * VecMASS[2].GetDataIndex(2);
		r6 = VecMASS[0].GetDataIndex(0) * VecMASS[1].GetDataIndex(2) * VecMASS[2].GetDataIndex(1);
		res4 = r1 + r2 + r3 - r4 - r5 - r6;
//------------------------------------------------------------------------------------------------
		return res = res1 * VecMASS[0].GetDataIndex(3) * (-1) + res2 * VecMASS[1].GetDataIndex(3) - res3 * VecMASS[2].GetDataIndex(3) + res4 * VecMASS[3].GetDataIndex(3);
	}
	cout << "Матрица A<2||A>4" << endl;
	return -1;
}

ostream& operator<<(ostream& stream, const Matrix& mat)
{
	stream << "Размер: " << mat.RowsMatrix << "*" <<mat.ColsMatrix<< endl;
	//stream << "(";
	for (int i = 0; i < mat.RowsMatrix; ++i)
	{
		mat.VecMASS[i].printToMatrix();
		stream << endl;
	}

	stream << endl;
	return stream;
}
double Matrix::GetDeterminant(int str, int cols)const
{
	double r1 = 1, r2 = 1;
	int g = 0;
	for (int j = 0; j < ColsMatrix-1; j++)
	{
		loop1:
		if (j == str&&g!=cols)
		{
			j++;
			goto loop1;
		}
		if (g == cols&&j!=str)
		{
			g++;
			goto loop1;
		}
		if (j == str && g == cols)
		{
			j++;
			g++;
			goto loop1;
		}
		if (j == 3 || g == 3)
		{
			break;
		}
		r1 = r1 * VecMASS[j].GetDataIndex(g);
		g++;
	}
	g = 0;
	for (int j = ColsMatrix-2; j > 0; j--)
	{
		loop2:
		if (j == str && g == cols)
		{
			j--;
			g++;
			goto loop2;
		}
		if (j == str && g != cols)
		{
			j--;
			goto loop2;
		}
		if (g == cols && j != str)
		{
			g++;
			goto loop2;
		}
		if (j == 3 || g == 3)
		{
			break;
		}
		r2 = r2 * VecMASS[j].GetDataIndex(g);
		g++;
	}
	return r1 - r2;
}
void Matrix::SetMassToVec(int index,double* mas)
{
	VecMASS[index].SetData(mas);
}
/*
istream& operator>>(istream& stream, Matrix& mat)
{
	// TODO: вставьте здесь оператор return
}
*/