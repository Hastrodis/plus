#include "Stroka.h"

Stroka::Stroka() {
	char s[] = { 0 };
	count = 0;
}

Stroka::~Stroka() {

}

int Stroka::getCount() {
	return count;
}

void Stroka::setCount(int c) {
	count = c;
}