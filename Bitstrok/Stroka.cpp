#include "Stroka.h"
#include <iostream>
using namespace std;
//������
Stroka::Stroka() {
	s = nullptr;
}
//��������� ������ ����
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

//--------------��� �������� ������--------------------------

int_Stroka::int_Stroka() {
	s = { 0 };
}
//����������� ��� ���������� ���������
int_Stroka::int_Stroka(int *s) {
	for (int i = 0; i < sizeof(s) / sizeof(int); i++) {
		this->s[i] = s[i];
	}
}

int_Stroka::~int_Stroka() {
	delete[] this->s;
}

void int_Stroka::setSize(int *s) {
	this->len = sizeof(s) / sizeof(int);
}

int int_Stroka::getSize() {
	return this->len;
}

void int_Stroka::Print() {
	setSize(this->s);
	int len = getSize();
	for (int i = 0; i < len; i++) {
		cout << endl;
	}
}

//----------------------�������--------------------------
/*template<class T, typename T1>
Shablon_Stroka<T, T1>::Shablon_Stroka() {
	if (T1 == int) { s = { 0 }; }
	else if (T1 == char) { s = nullptr; }
	
}*/
/*
template<class T, typename T1>
Shablon_Stroka<T, T1>::Shablon_Stroka(const T1* Ss) {

}

template<class T, typename T1>
Shablon_Stroka<T, T1>::~Shablon_Stroka() {
	delete[] this->s;
	delete this->len;
}


template<class T, typename T1>
void Shablon_Stroka<T, T1>::Print() {
	if (T1 == char) {
		cout << s << endl;
	}
	else if (T1 == int) {
		cout << "�� ���������" << endl;
	}
}*/