#include "stdafx.h"
#include "Vladel.h"

void Vladel::setIdVladel(int id)
{
	IdVladel = id;
}

int Vladel::getIdVladel()
{
	return IdVladel;
}

void Vladel::operator=(const Vladel &vld) {
	this->IdVladel = vld.IdVladel;
}