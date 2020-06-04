#pragma once
class Stroka
{
protected:
	char *s;
	int count;
public:
	Stroka();
	~Stroka();
	int getCount();
	void setCount(int c);
};

class int_Stroka : public Stroka 
{

};
