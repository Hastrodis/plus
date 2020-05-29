#pragma once
#include "Vladel.h"
class machine
{
public:
	machine();
	~machine();

	int idMachine;
	int VipMachine;

	void setIdMachine(int id);
	void setVipMachine(int year);

	int getIdMachine();
	int getVipMachine();

	Vladel* mVlad;
};

