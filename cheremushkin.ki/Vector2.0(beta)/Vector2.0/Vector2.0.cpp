#include <clocale>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Vector.h"
#include <locale.h>
#include <time.h>
#include "Matrix.h"
int random(int a, int b);

int main()
{
	setlocale(LC_CTYPE, "Rus");
	/*	Vector g =  Vector();
		g.print();
		double* mass = new double[10];
		int a = 0, b = 10;
		for (int i = 0; i < 10; i++)
		{
			mass[i] = rand() % (b - a + 1) + a;
		}
		Vector g2 = Vector(10,mass);
		g2.print();
		double scsum;
		scsum = g + g2;
		cout << scsum<<endl;
		*/
	int SWITHC;
	cout << "Выберите дейстиве" << endl << "1)Матрицы+Векторы" << endl<<"2)Векторы"<<endl;
	cin >> SWITHC;
	switch (SWITHC)
	{
		case 1:
		{
			cout << "Введите рамзерность матриц,от 2 до 4(на 4 не рабит деление,т.к. невозможно отработать обратную матрицу,создается квадратная матрица"<<endl;
			int size;
			cin >> size;
			Matrix Mat1 = Matrix(size,size);
			Matrix Mat2 = Matrix(size,size);
			Matrix RES = Matrix(size,size);
			cout << "Введите массивы векторов для первой матрицы" << endl;
			double*buf1=new double[size];
			for (int i = 0; i < size; i++)
			{
				cout << "Введите массив: " << i << endl;
				for (int j = 0; j < size; j++)
				{
					cout << "[ "<<j<<"]= ";
					cin >> buf1[j];
				}
				Mat1.SetMassToVec(i, buf1);
			}
			cout << "Введите массивы векторов для второй матрицы" << endl;
			double* buf2 = new double[size];
			for (int i = 0; i < size; i++)
			{
				cout << "Введите массив: " << i << endl;
				for (int j = 0; j < size; j++)
				{
					cout << "[ " << j << "]= ";
					cin >> buf2[j];
				}
				Mat2.SetMassToVec(i, buf1);
			}
			cout << Mat1;
			cout << Mat2;
			int switchwec;
			do {
				cout << endl << "Выбирите дейстиве" << endl << "1)Сложение" << endl << "2)Вычитание" << endl << "3)Умнажение матриц" << endl << "4)Умножение на число" << endl << "5)Деление" << endl << "6)Детерминант" << endl << "7)Возведение в степень" << endl << "8)Выход" << endl;
				cin >> switchwec;
				switch (switchwec)
				{
					case 1:
					{
						RES = Mat1 + Mat2;
						cout << RES;
					}break;
					case 2:
					{
						RES = Mat1 - Mat2;
						cout << RES;
					}break;
					case 3:
					{
						RES = Mat1 * Mat2;
						cout << RES;
					}break;
					case 4:
					{
						double h;
						cout << "Введите число" << endl;
						cin >> h;
						RES = Mat1 * h;
						cout << RES;
					}break;
					case 5:
					{
						RES = Mat1 / Mat2;
						cout << RES;
					}break;
					case 6:
					{	
						double h;
						h=Mat1.Determinant();
						cout << "Детерминант равен: "<<h;
					}break;
					case 7:
					{
						double h;
						cout << "Введите число" << endl;
						cin >> h;
						RES = Mat1^ h;
						cout << RES;
					}break;
					case 8:
					{
						cout << "Mission completed"<<endl;
					}break;
				}
				//cout << Mat1;
				//Matrix Mat2 = Matrix(3, 3);
				//cout << Mat2;
				//Mat1 = Mat2;
				//cout << Mat1;
				//Mat3 = Mat1 * Mat2;
				//cout << Mat3;
			//	Matrix Mat3 = Matrix(3,4);
			//	cout<<Mat3;
			} while (switchwec != 8);

		}break;
		case 2:
		{	
			Vector Vec1 = Vector();
			Vector Vec2 = Vector();
			int switch1;
			int ssize;
			cout << "Выберите методы ввода первого вектора" << endl << "1)Руками" << endl << "2)Генерация с вводом размера и вводом полей " << endl;
			cin >> switch1;
			switch (switch1)
			{
			case 1:
			{
			loop1:
				cout << "Введите размер векторов(Внимание, он сохранится на 2ой тоже,т.к. если не сделать этого , то сложение ,вычитание и другое невозможны)" << endl;
				cin >> ssize;
				if (ssize < 2)
				{
					cout << "error" << endl;
					goto loop1;
				}
				double* Mmass = new double[ssize];
				cout << "Введите массив" << endl;
				for (int i = 0; i < ssize; i++)
				{
					cout << "[" << i << "]=";
					cin >> Mmass[i];
				}
				//Vector Vec11 = Vector(ssize,Mmass);
				Vec1.SetSize(ssize);
				Vec1.SetData(Mmass);
				Vec1.print();
				cout << "Выберите методы ввода второго вектора" << endl << "1)Руками" << endl << "2)Генерация с вводом размера " << endl;
				int switch11;
				cin >> switch11;
				switch (switch11)
				{
				case 1:
				{
					//int ssize;
					cout << "Размер береться тот же, т.к. если он не равен первому , то произойдет тротлинг" << endl;
					//cin >> ssize;
					double* Mmass = new double[ssize];
					cout << "Введите массив" << endl;
					for (int i = 0; i < ssize; i++)
					{
						cout << "[" << i << "]=";
						cin >> Mmass[i];
					}
					//Vector Vec12 = Vector(ssize, Mmass);
					Vec2.SetSize(ssize);
					Vec2.SetData(Mmass);
					Vec2.print();
				}break;
				case 2:
				{	cout << "Размер береться тот же, т.к. если он не равен первому , то произойдет тротлинг" << endl;
				//int ssize;
				//cout << "Введите размер первого вектора" << endl;
				//cin >> ssize;
				int a, b;
				cout << "Введите левую границу" << endl;
				cin >> a;
				cout << "Введите праву границу" << endl;
				cin >> b;
				double* Mmass = new double[ssize];
				for (int i = 0; i < ssize; i++)
				{
					Mmass[i] = rand() % (b - a + 1) + a;
				}
				//Vector Vec12 = Vector(ssize, Mmass);
				Vec2.SetSize(ssize);
				Vec2.SetData(Mmass);
				Vec2.print();
				}break;
				}
			}break;
			case 2:
			{
				//int ssize;
				cout << "Введите размер первого вектора" << endl;
			loop2:
				cin >> ssize;
				if (ssize < 2)
				{
					cout << "error" << endl;
					goto loop2;
				}
				int a, b;
				cout << "Введите левую границу" << endl;
				cin >> a;
				cout << "Введите праву границу" << endl;
				cin >> b;
				double* Mmass = new double[ssize];
				for (int i = 0; i < ssize; i++)
				{
					Mmass[i] = rand() % (b - a + 1) + a;
				}
				//Vector Vec11 = Vector(ssize, Mmass);
				Vec1.SetSize(ssize);
				Vec1.SetData(Mmass);
				Vec1.print();
				cout << "Выберите методы ввода второго вектора" << endl << "1)Руками" << endl << "2)Генерация с вводом размера " << endl;
				int switch21;
				cin >> switch21;
				switch (switch21)
				{
				case 1:
				{
					//int ssize;
					cout << "Размер береться тот же, т.к. если он не равен первому , то произойдет тротлинг" << endl;
					//cin >> ssize;
					double* Mmass = new double[ssize];
					cout << "Введите массив" << endl;
					for (int i = 0; i < ssize; i++)
					{
						cout << "[" << i << "]=";
						cin >> Mmass[i];
					}
					//Vector Vec12 = Vector(ssize, Mmass);
					Vec2.SetSize(ssize);
					Vec2.SetData(Mmass);
					Vec2.print();
				}break;
				case 2:
				{	cout << "Размер береться тот же, т.к. если он не равен первому , то произойдет тротлинг" << endl;
				//int ssize;
				//cout << "Введите размер первого вектора" << endl;
				//cin >> ssize;
				int a, b;
				cout << "Введите левую границу" << endl;
				cin >> a;
				cout << "Введите праву границу" << endl;
				cin >> b;
				double* Mmass = new double[ssize];
				for (int i = 0; i < ssize; i++)
				{
					Mmass[i] = rand() % (b - a + 1) + a;
				}
				//Vector Vec12 = Vector(ssize, Mmass);
				Vec2.SetSize(ssize);
				Vec2.SetData(Mmass);
				Vec2.print();
				}break;
				}
			}break;
			}
			cout << "Выберите дейстиве" << endl << "1)Сумма векторов" << "2)Разность векторов" << "3)Cкалярное произведение" << "4)Расстояние между 2мя векторами" << endl << "5)Умножение вектора на число" << endl << "6)Вывод транспанированного вектора" << endl << "7)Вывод в поток" << endl;
			int switchK;
			cin >> switchK;
			switch (switchK)
			{
			case 1:
			{
				Vector res = Vector(ssize);
				res = Vec1 + Vec2;
				res.print();
			}break;
			case 2:
			{
				Vector res = Vector(ssize);
				res = Vec1 - Vec2;
				res.print();
			}break;
			case 3:
			{
				double res;
				res = Vec1 * Vec2;
				cout << res << endl;
			}break;
			case 4:
			{
				double res;
				res = Vec1.GetDistance(Vec2);
				cout << res << endl;
			}break;
			case 5:
			{
				double n;
				cout << "Введите число для умнажения";
				cin >> n;
				Vec1* n;
				Vec1.print();
			}
			case 6:
			{
				Vec1.printT();
			}break;
			case 7:
			{
				cout << Vec1;
			}
			default:
				break;
			}
		}break;
    }
	return 0;
}
//its bool shit
//don't use
int random(int a, int b)
{
	srand(time(NULL));
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}
//rand() % (b - a + 1) + a;