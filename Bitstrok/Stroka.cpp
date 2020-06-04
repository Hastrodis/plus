#include "Stroka.h"
#include <iostream>
using namespace std;
//пустая
Stroka::Stroka() {
	char s[] = { 0 };
	count = 0;
}
//с размерностью
Stroka::Stroka(int a) {
	count = a;
	char s[] = { 0 };
	
}

Stroka::~Stroka() {
	/*delete *s;
	delete s[];*/
}

int Stroka::getCount() {
	return count;
}

void Stroka::interS(char s1, Stroka *s, int i) {
	s[i] = s1;
}

void Stroka::print() {
	std::cout << s << endl;
}
/*
void Stroka::print(char *s) {
	std::cout << s << endl;
}
/*
void Stroka::interS(char s1, char* s, int i) {
	s[i] = s1;
}
*/