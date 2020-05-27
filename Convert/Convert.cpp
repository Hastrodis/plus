﻿#pragma once
#include <iostream>



#define NUMBER_SYSTEM_BASE_CODE -1;
#define NUMBER_SYSTEM_BASE_TEXT "Система счислений меньше 2!"; //#define NUMBER_SYSTEM_BASE_TEXT "The base of the number system is less than 2!";

#define NUMBER_NOT_NULL_CODE 101;
#define NUMBER_NOT_NULL_TEXT "Число не может быть 0!";  //#define NUMBER_NOT_NULL_TEXT "The number must not be zero!";

using namespace std;

int main()
{
	//пробная фигня пока не трогайте
	double a;
	int b;
    setlocale(LC_ALL, "Russian");
	cout << "Введите число \n";
	cin >> a;
	cout << "Введите систему счисления" << endl;
	cin >> b;
	a = (double)a;
	cout << "дробная часть A = " << a << endl;
	//string s = integerPart(a,b);
}

//замена числа на цифру, к примеру switch(10) = A
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
//это вроде как классы исключений для вывода ошибок (сверху прописаны)
/*
class NumberError
    {

    };
class NumberSystemBase :NumberError {
public:
    virtual const char* getMessage() { return NUMBER_SYSTEM_BASE_TEXT; };
    virtual int getCode() { return NUMBER_SYSTEM_BASE_CODE; };

};//*/

//другая вариация для целочисленной части
int integerPart(int a, int p) {
	//не доделано
	return 0;
}

//Дробная часть - преобразование
double drob(double a, int p) {
	if (a < 1) {
		a *= p;
		return digit((int)a);
		a = (double)a;
	}
	
	
}

//целочисленная часть (код от Максима), суть в том, что полученное число отправляется в s по указателю
int integerPart(int a, int p, char* s) {

    if (p < 2) {
        //throw new NumberSystemBase();
		cout << "Ошибка, система счисления меньше 2" << endl;
    }
	//берется целочисленная часть
    int num = (int)a;
	//остаток от деления на p (систему счисления)
    int rest = num % p;
	//num делится на p и сохраняется (типо num = num / p)
    num /= p;
    if (num == 0)
    {
        s[0] = digit(rest); return 1;
    }
    int k = integerPart(num, p, s);
    s[k++] = digit(rest);
    return k;
}