#pragma once
#include <iostream>
class Stroka
{
protected:
	char *s;
	int count;
public:
	Stroka(); //������ ������ ������
	Stroka(int a); //������ ������ ������ ������������ 10
	void interS(char s1, Stroka* s, int i);
	//void interS(char s1, char* s, int i);
	void print();
	~Stroka();
	int getCount();
	void print(char *s);
};

class int_Stroka : public Stroka 
{

};
