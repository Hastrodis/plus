#include "Stroka.h"
#include <iostream>
using namespace std;
//пустая
Stroka::Stroka() {
	s = nullptr;
}
//помещение строки сюда
Stroka::Stroka(const char *s) {
	int length = strlen(s);
	this->s = new char[length +1];
	for (int i = 0; i < length; i++) {
		this->s[i] = s[i];
	}
	this->s[length] = '\0';
}

Stroka::Stroka(const Stroka& other) {
	int length = strlen(other.s);
	this->s = new char[length + 1];
	for (int i = 0; i < length; i++) {
		this->s[i] = other.s[i];
	};
	this->s[length] = '\0';
}


void Stroka::Print() {
	cout << s;
}

Stroka::~Stroka() {
	delete[] this->s;
}

//--------------Для числовой строки--------------------------

int_Stroka::int_Stroka() {
	s = { 0 };
}
//конструктор под количество элементов
int_Stroka::int_Stroka(int *s) {
	for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
		this->s[i] = s[i];
	}
}

int_Stroka::~int_Stroka() {

}

int int_Stroka::setSize(int *s) {
	int len = sizeof(s) / sizeof(int);
	return len;
}

void int_Stroka::Print() {
	int len = setSize(this->s);
	for (int i = 0; i < len; i++) {
		cout << endl;
	}
}

//----------------------Шаблоны--------------------------
template<class T, typename T1>
Shablon_Stroka<T, T1>::Shablon_Stroka() {
	s = NULL;
}

template<class T, typename T1>
Shablon_Stroka<T, T1>::Shablon_Stroka(const T1* Ss) {

}

template<class T, typename T1>
Shablon_Stroka<T, T1>::~Shablon_Stroka() {
	delete[] this->s;
}
template<class T, typename T1>
void Shablon_Stroka<T, T1>::Print() {
	cout << s;
}