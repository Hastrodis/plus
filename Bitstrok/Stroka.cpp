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

//----------------------Шаблоны--------------------------
/*template<class T>
Shablon_Stroka<T>::Shablon_Stroka(const T* Ss, int l) {
	//this->
	st.clear();
	for (int i = 0; i < l; i++) {
		st.push_back(Ss[i]);
	}
}//*/

/*template<class T>
Shablon_Stroka<T>::~Shablon_Stroka() {
	st.clear();
	//delete[] this->s;
	//delete this->len;
}//*/

/*template<class T>
void Shablon_Stroka<T>::Print() {
	for (int i = 0; i < st.size(); i++) {
		cout << st[i] << "\n";
	}
}//*/

/*
template<class T, typename T1>
void Shablon_Stroka<T, T1>::Print() {
	if (T1 == char) {
		cout << s << endl;
	}
	else if (T1 == int) {
		cout << "Не придумали" << endl;
	}
}*/