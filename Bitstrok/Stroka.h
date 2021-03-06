#pragma once
#include <iostream>
#include<vector>

class Stroka
{
/*protected:
	vector<char> vChar;*/
private:
	char *s;
public:
	Stroka();					 //пустой конструктор
	Stroka(const char *s);		 //обычный конструктор
	Stroka(const Stroka& other); //конструктор копирования
	/*присваивание*/ Stroka& operator =(const Stroka& other) {
		if (this->s != nullptr) {
			//удаление шлака
			delete[] s;
		}
		int length = strlen(other.s);
		this->s = new char[length + 1];
		for (int i = 0; i < length; i++) {
			this->s[i] = other.s[i];
		};
		this->s[length] = '\0';
		return *this;
	}
	/*сложение*/	 Stroka  operator +(const Stroka& other) {
		Stroka newS;
		int thisLength = strlen(this->s);
		int otherLength = strlen(other.s);
		newS.s = new char[1 + thisLength + otherLength];
		int i = 0;
		for (; i < thisLength; i++)
		{
			newS.s[i] = this->s[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newS.s[i] = other.s[j];
		}
		newS.s[thisLength + otherLength] = '\0';
		return newS;
	}
	/*оператор []*/  char&  operator [](int i) { return this->s[i]; }
	void Print();
	~Stroka();
};

//числовая строка
class int_Stroka 
{
	private:
		int* s;
		int len;
	public:
		int_Stroka();
		int_Stroka(int *s);
		~int_Stroka();
		void Print();
		void setSize(int* s);
		int getSize();
};

//шаблон
template<class T>
class Shablon_Stroka {
	/*private:
		vector<T> st;*/
	public: 
		std::vector<T> st;
		//Shablon_Stroka();
		Shablon_Stroka(const T* Ss, int l) {
			st.clear();
			for (int i = 0; i < l; i++) {
				st.push_back(Ss[i]);
			}
		};
		~Shablon_Stroka() {
			st.clear();
		};
		void Print() {
			for (int i = 0; i < st.size(); i++) {
				std::cout << st[i] << "\n";
			}
		};
};//*/