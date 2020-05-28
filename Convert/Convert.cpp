#pragma once
#include <iostream>
#include <cmath>


#define NUMBER_SYSTEM_BASE_CODE -1;
#define NUMBER_SYSTEM_BASE_TEXT "Система счислений меньше 2!"; 
//#define NUMBER_SYSTEM_BASE_TEXT "The base of the number system is less than 2!";

#define NUMBER_NOT_NULL_CODE 101;
#define NUMBER_NOT_NULL_TEXT "Число не может быть 0!";  
//#define NUMBER_NOT_NULL_TEXT "The number must not be zero!";
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
char drob(double a, int p);
int integerPart(int a, int p, char* s);

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
		cout << "Введите число \n";
		cin >> a;
		if (a == 0) throw new NumberNotNull;
		cout << "Введите систему счисления" << endl;
		cin >> b;
		if (b < 2) {
			throw new NumberSystemBase();
		}
		try {
		
		}
		catch (NumberSystemBase* ex) {
			cout << ex->getMessage() << " Code: " << ex->getCode();
		}
	}
	catch (NumberNotNull* ex) {
		cout << ex->getMessage() << " Code: " << ex->getCode();
	}
    
	
	

	//cout << "Дробная часть от a = " << drob(a, b) << endl;
	//-------------------------------------дробная часть-------------------------------------
	//drob(a2, b, string);
	//cout << string << endl;
}

//делит на целую и дробную
void round(double a, double* a1, double* a2) {
	*a2 = modf(a, a1);
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


//другая вариация для целочисленной части
int integerPart(int a, int p) {
	//не доделано
	return 0;
}

//Дробная часть - преобразование
char drob(double a, int p) {
	int k = 0;
	double g = 0;
		a *= p;
		if (a > (p-1)) {
			return digit((int)a);
			round(a, &g, &a);
		}
		//s = '1';
		//s[k] = digit(1);
	
	
}

//целочисленная часть, суть в том, что полученное число отправляется в s по указателю
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