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
	Stroka();					 //������ �����������
	Stroka(const char *s);		 //������� �����������
	Stroka(const Stroka& other); //����������� �����������
	/*������������*/ Stroka& operator =(const Stroka& other) {
		if (this->s != nullptr) {
			//�������� �����
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
	/*��������*/	 Stroka  operator +(const Stroka& other) {
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
	/*�������� []*/  //char  operator [](int i) { return this->vChar[i]; }
	void Print();
	~Stroka();
};

//�������������� ����� - �������� ������
class int_Stroka : public Stroka 
{
	private:

	public:
		int_Stroka();
		~int_Stroka();
};
