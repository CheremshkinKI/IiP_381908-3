#include "Credit.h"
#include "string.h"
#include <fstream>
#include <sstream>
#include <vector>
void Credit::odobrenie()
{
	int x,c=1 ,u=0;
	char v;
	x = vvod();
	hed(x);
	string s = "not",b, re;
	fstream fi;
	fi.open("cred.txt", fstream::in | fstream::out | fstream::app);
	if (x==0)
	{
		u == 0;
	}
	else
	{
		while (getline(fi, re))
		{
			u++;
			if (u == x)
			{
				u = fi.tellg();
				u++;
				break;
			}
		}
	}
	fi.seekg(u);
	fi >> b;
	if (s==b)
	{
		do
		{
			cout << "Credit:1\n";
			cout << "Exit:2\n";
			cin >> c;
			if (c == 1)
			{
				vibor(x);
			}if (c==2)
			{
				x= vvod();
			}
		} while (c != 3);
	}
	else
	{
		cout << "1-to pay for the month \n";
		cout << "2-to pay in full \n";
		cout << "3-Exit\n";
		cin >> c;
		if (c==1)
		{
			mesgas(x);
		}
		if (c==2)
		{
			fillgas(x);
		}
		if (c == 3)
		{
			x = vvod();
		}
	}
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
    fo.close();
	fi.close();
}

void Credit::vibor(int x)
{
	x++;
	int y, a = 0, f, d,u=1;
	string b, v, re;
	char fai;
	fstream fi;
	fi.open("cred.txt", fstream::in | fstream::out | fstream::app);
	fstream fa;
	fa.open("gara.txt", fstream::in | fstream::trunc | fstream::app);
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	while (getline(fi,re))
	{
			u++;
			if (u==x)
			{
			  u=fi.tellg();
			  break;
			}
	}
	x--;
	for (int i = x ; i > 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			fo >> b;
		}
	}
	for (int j = 0; j < 5; j++)
	{
		fo >> b;
	}
	f = fo.tellg();
	fo >> b;
	y = atoi(b.c_str());
	fi.close();
	fa.close();
	fo.close();
	fi.open("cred.txt", fstream::in | fstream::out );
	fa.open("gara.txt", fstream::in | fstream::out | fstream::app);
	fo.open("id.txt", fstream::in | fstream::out );
	cout << "Select the amount you would like to borrow:\n";
	cout << "1-up to 100,000\n";
	cout << "2-from 100,000 to 500,000\n";
	cout << "3-from 500,000 to 1,000,000\n";
	cout << "4-from 1,000,000 to 3,000,000\n";
	cin >> a;
	int wat = 1, j, t = 1, l = 25, g, k, o;
	double la = 1.25;
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 1 || i == 2)
		{
			j = i;
		}
		if (i == 3)
		{
			j = i + 1;
		}
		if (i == 4)
		{
			j = i + 10;
		}
		wat = j + 1;
		d = (y  * wat * 6) / (la - ((a - 1) * 2 - wat + 1) / 10);
		g = y * wat * 6;
		if (a == 1)
		{
			k = 100000;
			if (k > g)
			{
				cout << t << "-Maximum credit for " << wat * 12 << " months " << d << " under " << l - (a - 1) * 2 - wat + 1 << "%"
					<< " issue to the Bank " << g << endl;
				t++;
			}
			else
			{
				int k1 = k / 6 * wat * 12;
				cout << t << "-Maximum credit for " << wat * 12 << " months " << k << " under " << l + (a - 1) * 2 - wat + 1 << "%"
					<< "issue to the Bank" << k1 << endl;
				t++;
			}
		}
		else
		{
			if (a == 2)
			{
				k = 100000, o = 500000;
			}
			if (a == 3)
			{
				k = 500000, o = 1000000;
			}
			if (a == 4)
			{
				k = 1000000, o = 3000000;
			}
			if (k >= g && o < g)
			{
				cout << t << "-Maximum credit for " << wat * 12 << " months " << d << " under " << l + (a - 1) * 2 - wat + 1 << "%"
					<< " issue to the Bank " << g << endl;
				t++;
			}
			else
			{
				if (k > g)
				{
					cout << "issuance is not possible\n";
				}
				else
				{
					int k1 = o / 6 * wat * 12;
					cout << t << "-Maximum credit for " << wat * 12 << " months " << o << " under " << l + (a - 1) * 2 - wat + 1 << "%"
						<< "issue to the Bank" << k1 << endl;
					t++;
				}
			}
		}
	}
	cout << "select a term"<<endl;
	int tr;
	cin >> wat;
	g = (y * wat * 6) / (la - ((a - 1) * 2 - wat + 1) / 10);
	do
	{
		cout << "select the amount"<<endl;
		cin >> tr;
	} while (g <= tr);
	cout << "you will have to"<<endl;
	g= tr* (la - ((a - 1) * 2 - wat + 1) / 10);
	int fd,size;
	fd = g / (wat*12);
	cout << g<<endl;
	y += tr;
	tr = y;
	f++;
	fo.seekp(f);
	while (y)
	{
		y /=10 ;
		fo << " ";
	}
	/*u++;*/
	fo.seekp(f);
	fo << tr;
	fi.seekp(u);
	fi << "yes "<< wat<< " "<< g << " " << fd;
	fi.close();
	fo.close();
	fa.close();
}