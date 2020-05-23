// ObjectVectorMap.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "machine.h"
#include <vector>
//#include <map>
#include <iostream>

using namespace std;

//typedef std::map<int, int> mp;
int main()
{
	vector<machine*> a;
	a.push_back(new machine);
	a.push_back(new machine);



	for (int i = 0; i < 2; i++)
	{
		int id;
		int VipMachine; 
		cout << "Input ID Machine" << "\n";
		cin >> id;
		a[i]->setIdMachine(id);
		cout << "Input year of manufacturee" << "\n";
		cin >> VipMachine;
		a[i]->setVipMachine(VipMachine);
	}


	for (int i = 0; i < 2; i++) {
		cout << "\n" << i+1 << " Vector element \n";
		cout << a[i]->getIdMachine() << "\n";
		cout << a[i]->getVipMachine() << "\n";
	}	int i;
	/*
	mp c1;
	for (int i = 3; i < 5; i++)
	{
		int id;
		int VipMachine;
		cout << "Input ID Machine" << "\n";
		cin >> id;		
		cout << "Input year of manufacturee" << "\n";
		cin >> VipMachine;
		c1.insert(id, VipMachine);
		
	}//*/

	

}