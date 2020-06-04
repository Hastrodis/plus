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


