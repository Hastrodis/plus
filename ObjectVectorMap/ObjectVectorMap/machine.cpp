#include "stdafx.h"
#include "machine.h"
//#include "Vladel.h"



void machine::setIdMachine(int id)
{
	idMachine = id;
}

void machine::setVipMachine(int year)
{
	VipMachine = year;
}

int machine::getIdMachine()
{
	return idMachine;
}

int machine::getVipMachine()
{
	return VipMachine;
}