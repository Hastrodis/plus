#include <iostream>
#include "Stroka.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	/*Shablon_Stroka<Stroka, char> s1("chjgh");
	s1.Print();

	int array[] = { 10, 0, 5 };
	int_Stroka Sarray = int_Stroka(array);
	delete[] array;*/

	Stroka s("Text");
	cout << "Выведенная строка s:" << endl;
	s.Print();

	double d[] = {0.5, 0.6, 0.7};
	Shablon_Stroka<double> s1(d, 3);
	cout << "\nВыведенная строка s1:" << endl;
	s1.Print();
	/*
	Stroka s2(" and text");
	cout << "\nВыведенная строка s2:" << endl;
	s1.Print();

	Stroka resoult = s + s1 + s2;
	cout << "\nВыведенная строка resoult:" << endl;
	resoult[2] = '5';
	resoult.Print();//*/
	
}

