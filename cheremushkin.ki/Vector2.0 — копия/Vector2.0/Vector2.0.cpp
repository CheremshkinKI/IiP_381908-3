#include <iostream>
#include "Vector.h"
#include <locale.h>
#include <time.h>
using namespace std;
int random(int a, int b);

int main()
{
	setlocale(LC_CTYPE,"Rus");
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
				cout << "error"<<endl;
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
					for (int i = 0; i < 10; i++)
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
			for (int i = 0; i < 10; i++)
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
						cout << "[" << i << "]=" ;
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
					for (int i = 0; i < 10; i++)
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
	cout << "Выберите дейстиве" << endl << "1)Сумма векторов" << "2)Разность векторов" << "3)Cкалярное произведение" << "4)Расстояние между 2мя векторами" << endl<<"5)Умножение вектора на число"<<endl;
	int switchK;
	cin >> switchK;
	switch (switchK)
	{
		case 1:
		{
			Vector res= Vector(ssize);
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
	default:
		break;
	}
	
	/*
		Написать свитч+
		Проверить все функции
		Что за транспанироавание АААА
		Реализовать конструкторы.+
		Диструктор.+
		Перегрузить операции сложения+
		и разности векторов,+
		умножение вектора на +
		число и на вектор (векторное произведение). ++
		Перегрузить операции ввода и вывода в поток.
		Реализовать метод поиска длины вектора+
		определения косинус угла между двумя векторами.+
	*/

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