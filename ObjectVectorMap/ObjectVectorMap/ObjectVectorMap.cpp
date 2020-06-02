// ObjectVectorMap.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "machine.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	/*machine& mVlad = (const machine & other)
	{

	}*/
	
	vector<machine*> a;
	a.push_back(new machine);
	a.push_back(new machine);



	for (int i = 0; i < 2; i++)
	{
		int id;
		int VipMachine; 
		int IDVlad;
		cout << "Input ID Machine" << "\n";
		cin >> id;
		a[i]->setIdMachine(id);
		cout << "Input year of manufacturee" << "\n";
		cin >> VipMachine;
		a[i]->setVipMachine(VipMachine);
		cout << "ID Vladel" << "\n";
		cin >> IDVlad;
		a[i]->mVlad->setIdVladel(IDVlad);

	}


	for (int i = 0; i < 2; i++) {
		cout << "\n" << i+1 << " Vector element \n";
		cout << a[i]->getIdMachine() << "\n";
		cout << a[i]->getVipMachine() << "\n";
		cout << a[i]->mVlad->getIdVladel() << "\n";
	}	int i;
	
	a.~vector;


}