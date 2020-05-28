#pragma once
#include <iostream>
#include <cmath>


#define NUMBER_SYSTEM_BASE_CODE -1;
#define NUMBER_SYSTEM_BASE_TEXT "Система счисления меньше 2!"; 

#define NUMBER_NOT_NULL_CODE 101;
#define NUMBER_NOT_NULL_TEXT "Число не может быть 0!";  
//это вроде как классы исключений для вывода ошибок (сверху прописаны)

//класс ошибки 
class NumberError
{
public:
	virtual const char* getMessage() = 0;
	virtual int getCode() = 0;
};
//класс ошибки - система счисления меньше двух
class NumberSystemBase :NumberError {
public:
	virtual const char* getMessage() { return NUMBER_SYSTEM_BASE_TEXT; };
	virtual int getCode() { return NUMBER_SYSTEM_BASE_CODE; };

};
//класс ошибки - число равно нулю
class NumberNotNull :NumberError {
public:
	virtual const char* getMessage() { return NUMBER_NOT_NULL_TEXT; };
	virtual int getCode() { return NUMBER_NOT_NULL_CODE; };
};
//*/
using namespace std;
//char digit(int num){}
//делит на целую и дробную
void round(double a, double* a1, double* a2);
void drob(double a, int p, char* s);
void drob(double a, int p, char* s, int it1);
int integerPart(int a, int p, char* s);


//замена чисел типа int на цифры/буквы типа char
char digit(int num)
{
    switch (num) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    case 10: return 'A';
    case 11: return 'B';
    case 12: return 'C';
    case 13: return 'D';
    case 14: return 'E';
    case 15: return 'F';
    }
}

int main()
{
	//a - число, а1 - целая часть, а2 - дробная часть.
	double a, a1 = 0, a2 = 0;
	//система счисления
	int b;
	//
	char s[100] = { 0 };
	try {
		setlocale(LC_ALL, "Russian");
		cout << "Введите число: \n";
		cin >> a;
		if (a == 0) throw new NumberNotNull;
		//разделение на двое
		round(a, &a1, &a2);
		cout << "Введите систему счисления:" << endl;
		cin >> b;
		cout << "" << endl;
		if (b < 2) {
			throw new NumberSystemBase();
		}
		
		try {
			//преобразование целой части
			int k = integerPart(a1, b, s); //k счетчик
			//it1 используется как двойное условие - для проверки и для округления
			int it1 = a - (int)a;
			if (it1 != 0) {
				//преобразование вещественной части
				cout << "Введите точность округления \n (в случае если точность будет равна 0 или меньше - у переведенного числа вещественнаяая часть будет полной): \n";
				cin >> it1;
				if (it1 > 0) {
					s[k++] = ',';
					drob(a2, b, &s[k], it1);

				}
				else {
					drob(a2, b, &s[k]);
				}
			}
			else s[k++] = '\0'; //в случае если число 'a' целое - добавляем детерминирующий ноль (вроде так называется)
			cout << "Ответ: \n		Число " << a << " в десятичной системе счисления = " << s << " в двоичной системе счисления" << endl;
		}
		catch (NumberSystemBase* ex) {
			cout << ex->getMessage() << " Code: " << ex->getCode();
		}
	}
	catch (NumberNotNull* ex) {
		cout << ex->getMessage() << " Code: " << ex->getCode();
	}
    
	
}

//делит на целую и дробную
void round(double a, double* a1, double* a2) 
{
	*a2 = modf(a, a1);
}

//=======
//это вроде как классы исключений для вывода ошибок (сверху прописаны)


//Дробная часть - преобразование
//условное ограничение
void drob(double a, int b, char* s) {
	int it = 0, k = 0;
	double a1 = a;
	do {
		a1 *= b;
		s[k++] = digit((int)a1);
		a1 -= (int)a1;
		it++;
	} while (a1 > 0.00000001);
	s[k] = '\0'; //конец строки
}
//с ограничением
void drob(double a, int b, char* s, int it1) {
	int it = 0, k = 0;
	double a1 = a;
	do {
		a1 *= b;
		s[k++] = digit((int)a1);
		a1 -= (int)a1;
		it++;
	} while (it < it1); //ограничение через задание предела (кол-во знаков после запятой)
	s[k] = '\0'; //конец строки
}

//целочисленная часть, суть в том, что полученное число отправляется в s по указателю
int integerPart(int a, int b, char* s) {

    if (b < 2) {
        //throw new NumberSystemBase();
		cout << "Ошибка, система счисления меньше 2" << endl;
    }
	//берется целочисленная часть
    int num = (int)a;
	//остаток от деления на p (систему счисления)
    int rest = num % b;
	//num делится на p и сохраняется (типо num = num / p)
    num /= b;
    if (num == 0)
    {
		//когда рекурсия дойдет до конца, начнет возвращать значения
        s[0] = digit(rest); return 1;
    }
    int k = integerPart(num, b, s);
    s[k++] = digit(rest);
    return k;
}




