#include <iostream>
#include "ArmyUnits/Alien/AlienSoldier.h"
#include "AlienArmy.h"
using namespace std;

int main() {
	int EarthID = 0;
	int AlienID = 2000;
	AlienSoldier* a1= new AlienSoldier(AlienID++, 5, 100, 5, 2);
	AlienSoldier* a2= new AlienSoldier(AlienID++, 5, 100, 5, 2);
	AlienSoldier* a3= new AlienSoldier(AlienID++, 5, 100, 5, 2);
	EarthSoldier* b1 = new EarthSoldier(EarthID++, 5, 100, 500, 3);
	EarthArmy* Earth = new EarthArmy();
	AlienArmy* Alien = new AlienArmy();
	Alien->AddUnit(a1);
	Alien->AddUnit(a2);
	Alien->AddUnit(a3);
	Earth->AddUnit(b1);
	b1->Attack(Alien);
	int* hp = a3->getHealth();
	cout<<*hp<<endl;
}