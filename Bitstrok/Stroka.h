#pragma once
#include <iostream>
class Stroka
{
private:
	char *s;
public:
	Stroka(); 
	Stroka(const char *s);
	//конструктор копирования (без него не работает оператор +, так как запинается об =)
	Stroka(const Stroka& other); 
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
			newS.s[i] = other.s[i];
		}
		newS.s[thisLength + otherLength] = '\0';
		return newS;
	}
	void Print();
	~Stroka();

};

class int_Stroka : public Stroka 
{

};
