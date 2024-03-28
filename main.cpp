#include <iostream>
#include "ArmyUnits/Alien/AlienSoldier.h"
using namespace std;

int main() {
	int EarthID = 0;
	int AlienID = 2000;
	AlienSoldier a1(AlienID++,5, 100, 5, 2);
	AlienSoldier a3(AlienID++,5, 100, 5, 2);
	AlienSoldier a2(AlienID++,5, 100, 5, 2);
	cout << a1.getID() << a3.getID() << a2.getID() << endl;
}