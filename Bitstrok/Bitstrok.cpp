#include <iostream>
#include "Stroka.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	//cout << "Введите строку" << endl;
	Stroka s("Text");
	cout << "Выведенная строка:" << endl;
	s.Print();
}

