#pragma once
class TMyString
{
public:

	TMyString() { };

	virtual ~TMyString() { };

	virtual int getSize() = 0;

	virtual void setSize(int newSize) = 0;

	virtual void setChar(int pos, char ch) = 0;

	virtual char operator[](int i) = 0;
};

