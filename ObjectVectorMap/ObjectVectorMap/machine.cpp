#include "stdafx.h"
#include "machine.h"
#include "Vladel.h"

machine::machine(){
	this->mVlad = new Vladel();
}

machine::~machine(){
	if (mVlad != 0) {
		delete mVlad;
		mVlad = 0;
	}
}

machine& machine::operator=(const machine & idMachine)
{
	int id;
	idMachine = id;
}
/*void machine::setIdMachine(int id)
{
	
}*/

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