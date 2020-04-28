#include <iostream>
#include "Fraction.h"
#include "Complex.h"
#include <locale.h>
using namespace std;
int main()
{
    int buttle;
    setlocale(LC_CTYPE, "Rus");
    do {
        cout << "Выберите деиствие" << endl << "1)Калькулятор Дробеи" << endl << "2)Калькултор комлексных чисел" << endl << "3)Exit" << endl;
        cin >> buttle;
        switch (buttle)
        {
        case 1:
        {
            cout << "Выберите деиствие" << endl << "1)Сложение" << endl << "2) Умножение" << endl << "3) Деление" << endl << "4)Вычитание" << endl << "" << endl;
            int buttle1, buf;
            cin >> buttle1;
            Fraction ress = Fraction();
            Fraction A = Fraction();
            Fraction B = Fraction();
            cout << "Введите первыи опперант" << endl;
            cin >> buf;
            A.setA(buf);
            cin >> buf;
            A.setB(buf);
            cout << "Введите второи опперант" << endl;
            cin >> buf;
            B.setA(buf);
            cin >> buf;
            B.setB(buf);
            switch (buttle1)
            {
            case 1:
            {
                ress = A + B;
                cout << ress.getA() << "/" << ress.getB() << endl;

            }break;
            case 2:
            {
                ress = A * B;
                cout << ress.getA() << "/" << ress.getB() << endl;
            }break;
            case 3:
            {
                ress = A / B;
                cout << ress.getA() << "/" << ress.getB() << endl;
            }break;
            case 4:
            {
                ress = A - B;
                cout << ress.getA() << "/" << ress.getB() << endl;
            }break;
            default:
                break;
            }
        }break;
        case 2:
        {
            int buttle1, buf;
            Complex ress = Complex();
            Complex ressBoss = Complex();
            Complex A = Complex();
            Complex B = Complex();
            //     A++;
            //  A.Print();
            cout << "Введите перове комплексное число" << endl << "Введите реальную часть " << endl;
            cin >> buf;
            A.setARe(buf);
            cin >> buf;
            A.setBRe(buf);
            cout << "Введите дробную часть мнимого числа" << endl;
            cin >> buf;
            A.setAIm(buf);
            cin >> buf;
            A.setBIm(buf);
            cout << "Введите 2-ое комлексное чилсо" << endl << "Введите реальную часть " << endl;
            cin >> buf;
            B.setARe(buf);
            cin >> buf;
            B.setBRe(buf);
            cout << "Введите дробную часть мнимого числа" << endl;
            cin >> buf;
            B.setAIm(buf);
            cin >> buf;
            B.setBIm(buf);
            ressBoss = A;
            do
            {
                cout << "Выберите деиствие" << endl << "1)Сложение комплексных чисел " << endl << "2) Умножение комплексных чисел " << endl << "3) Деление комплексных чисел " << endl <<
                    "4)Вычитание комплексных чисел " << endl << "5)Инкремент(постфиксный)" << endl << "6)Инкремент(префиксный)" << endl << "7)Дикремент" << endl <<
                    "8)Умножение на число" << "9)Деление на число" << endl << "10)Прибавить число" << endl << "11)Вычесть число" << endl << "12)Комплекс +=" << endl <<
                    "13)Комлекс -=" << endl << "14)Остаток от деления на число %" << "15)Чсило +=" << endl << "16)Число-=" << endl << "17) Сравнение комплексных чисел" << endl << "18)Не равны ли комлексные числа"
                    << endl << "19)Больше либо равно (2 комплескных числа)" << endl << "20)Меньше либо равно (2 комплескных числа)" << endl << "21)Больше(2 комплескных числа" << endl
                    << "22)Меньше (2 комплескных числа)" <<endl<<"23)Сравнение(=) реальной части с числом"<<endl<<"24)Сравнение(>) реальной части с числом"<<endl<<"25)Сравнение(<) реальной части с числом"<<endl;
                cout << "26)exit"<<endl;
                    cin >> buttle1;
                      switch (buttle1)
                      {
                         case 1:
                         {
                          A = ressBoss;
                          ress = A + B;
                          ress.Print();
                          ressBoss = ress;
                          cout << endl << "Левый опперант" << endl;
                          ressBoss.Print();
                          cout <<endl<< "Правый опперант" << endl;
                          B.Print();
                          cout << endl;
                         }break;
                         case 2:
                         {
                          A = ressBoss;
                          ress = A * B;
                          ress.Print();
                          ressBoss = ress;
                          cout << endl << "Левый опперант" << endl;
                          ressBoss.Print();
                          cout << endl << "Правый опперант" << endl;
                          B.Print();
                          cout << endl;
                         }break;
                         case 3:
                         {
                          A = ressBoss;
                          ress = A / B;
                          ress.Print();
                          ressBoss = ress;
                          cout << endl << "Левый опперант" << endl;
                          ressBoss.Print();
                          cout << endl << "Правый опперант" << endl;
                          B.Print();
                          cout << endl;
                         }break;
                         case 4:
                         {
                          ress = A - B;
                          ress.Print();
                          ressBoss = ress;
                          cout << endl << "Левый опперант" << endl;
                          ressBoss.Print();
                          cout << endl << "Правый опперант" << endl;
                          B.Print();
                          cout << endl;
                         }break;
                         case 5:
                         {
                             ress = ressBoss;
                             ress++;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 6:
                         {
                             ress = ressBoss;
                             ++ress;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 7:
                         {
                             ress = ressBoss;
                             ress--;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 8:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress* h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 9:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress/ h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 10:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress + h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 11:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress - h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 12:
                         {
                             ress = ressBoss;
                             ress += A;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 13:
                         {
                             ress = ressBoss;
                             ress -= A;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 14:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress = A % h;
                             cout << "Числитель-остаток от деления , еcли оно произошло" << endl;
                             ress.Print();
                         }break;
                         case 15:
                         {   ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress += h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 16:
                         {
                             ress = ressBoss;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress -= h;
                             ress.Print();
                             ressBoss = ress;
                         }break;
                         case 17:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb=ress == B;
                             ress = ressBoss;
                             cout << RESb<<endl<<endl;
                         }break;
                         case 18:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb = ress != B;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;
                         case 19:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb = ress >= B;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;
                         case 20:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb = ress <= B;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;
                         case 21:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb = ress > B;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;
                         case 22:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             ress = ressBoss;
                             RESb = ress < B;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;  
                         case 23:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress = ressBoss;
                             RESb = ress ==h;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;  
                         case 24:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress = ressBoss;
                             RESb = ress > h;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;  
                         case 25:
                         {
                             std::cout << std::boolalpha;
                             bool RESb;
                             int h;
                             cout << "Введите чилсо" << endl;
                             cin >> h;
                             ress = ressBoss;
                             RESb = ress < h;
                             ress = ressBoss;
                             cout << RESb << endl << endl;
                         }break;
                         case 26: {}break;
                      }          
            } while (buttle1 !=26);
        }break;
        case 3: {} break;
 
        }
    } while (buttle!=3);
    return 0;
}


