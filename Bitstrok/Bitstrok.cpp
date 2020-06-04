#include <iostream>
#include "Stroka.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int a;
	cout << "Введите кол-во символов" << endl;
	cin >> a;
	Stroka str(a);
	char s1;
	cout << "Введите символы ("<< a << " шт.):" << endl;
	for (int i = 0; i < a; i++) {
		cin >> s1;
		str.interS(s1, &str, i);
	}
	cout << "\n" << str.print() << endl;
}

