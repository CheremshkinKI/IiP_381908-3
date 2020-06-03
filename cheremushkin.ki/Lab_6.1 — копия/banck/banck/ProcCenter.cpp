#include "ProcCenter.h"
#include <sstream>
#include <vector>

int ProcCenter::vvod()
{
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	int x=0;
	string a[5];
	string c;
	cout << "Vvedite Id\n";
	cin >> a[0];
		fo >> c;
		while (!fo.eof())
		{
			if (a[0] == c)
			{
				fo >> c;
				string f;
				do
				{
					system("cls");
					cout << "Vvedite Id\n" << a[0] << endl;
					cout << "Vvedite pasword\n";
					cin >> f;
				} while (c != f);
				break;
			}
			else
			{
				for (int i = 0; i < 6; i++)
				{
					fo >> c;
				}
				x++;
			}
		}
		/*cout << "Vvedite Famili\n";
		cin >> a[1];
		cout << "Vvedite Name\n";
		cin >> a[2];
		cout << "Vvedite Father name\n";
		cin >> a[3];
		cout << "Vvedite salary\n";
		cin >> a[4];*/
	fo.close();
	/*fo.open("id.txt", fstream::in | fstream::out );
	int da=2;
	fo.seekp(2);
	fo << da;
	fo.close();
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	fo.close();*/
	system("cls");
	return x;
}

void ProcCenter::hed(int x)
{
	string d;
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	while (x!=0)
	{
		for (int i = 0; i < 6; i++)
		{
			fo >> d;
		}
		x--;
	}
	for (int i = 0; i < 6; i++)
	{
		if (i==0)
		{
			fo >> d;
			cout <<"ID:" << d << " ";
		}
		if (i==1)
		{
			fo >> d;
		}
		if (i == 2)
		{
			fo >> d;
			cout << "Famili:" << d << " ";
		}
		if (i == 3)
		{
			fo >> d;
			cout << "Name:" << d << " ";
		}
		if (i == 4)
		{
			fo >> d;
			cout << "Father name:" << d << " ";
		}
		if (i == 4)
		{
			fo >> d;
			cout << "Money:" << d << " \n";
		}
	}
	fo.close();
}

void ProcCenter::fillgas(int x)
{

	int u=0,y,y1,f,ded=0;
	string re,b;
	fstream fi;
	fi.open("cred.txt", fstream::in | fstream::out | fstream::app);
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	if (x == 0)
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
	for (int i = 0; i < 3; i++)
	{
		fi >> re;
	}
	y1 = atoi(re.c_str());
	for (int i = x; i > 0; i--)
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
	fo.close();
	fi.open("cred.txt", fstream::in | fstream::out );
	fo.open("id.txt", fstream::in | fstream::out );
	if (y>=y1)
	{
		int far=y1;
		fo.seekp(f);
		while (far)
		{
			far /= 10;
			fo << " ";
		}
		y -= y1;
		fo.seekp(f);
		fo << y;
		u--;
		fi.seekp(u);
				for (int i = 0; i < 32; i++)
				{
					fi << " ";
				}
		fi.seekp(u);
		fi << "not";
		cout << "the loan is repaid";

	}
	else
	{
		cout << "insufficient funds";
	}
	
}

void ProcCenter::mesgas(int x)
{
	int u = 0, y, y1,y2, f, ded,ded1;
	string re, b;
	fstream fi;
	fi.open("cred.txt", fstream::in | fstream::out | fstream::app);
	fstream fo;
	fo.open("id.txt", fstream::in | fstream::out | fstream::app);
	if (x == 0)
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
	for (int i = 0; i < 2; i++)
	{
		fi >> re;
	}
	ded = fi.tellg();
	fi >> re;
	y1 = atoi(re.c_str());
	ded1 = fi.tellg();
	fi >> re;
	y2= atoi(re.c_str());
	for (int i = x; i > 0; i--)
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
	fo.close();
	fi.open("cred.txt", fstream::in | fstream::out);
	fo.open("id.txt", fstream::in | fstream::out);
	if (y >= y2)
	{
		int far = y1;
		fo.seekp(f);
		while (far)
		{
			far /= 10;
			fo << " ";
		}
		y -= y1;
		fo.seekp(f);
		fo << y;
		y1 -= y2;
		if (y1==0)
		{
			int far = y1;
			u--;
			fi.seekp(u);
			for (int i = 0; i < 32; i++)
			{
				fi << " ";
			}
			fi.seekp(u);
			fi << "not";
			cout << "the loan is repaid";
		}
		else
		{
			fi.seekp(ded+2);
			fi << y1;
			fi.seekp(ded1+2);
			fi << y2;
			}
	}
	else
	{
		cout << "insufficient funds";
	}
}
