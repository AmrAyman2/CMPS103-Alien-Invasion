#include "AlienArmy.h"
bool AlienArmy::AddUnit(AlienSoldier* unit) {
	return AlienSoldierQueue.enqueue(unit);
}

void AlienArmy::Attack(EarthArmy* earth)
{
	LinkedQueue <AlienSoldier*> temp = AlienSoldierQueue;
	AlienSoldier* soldier;
	while (!temp.isEmpty()) {
		temp.dequeue(soldier);
		soldier->Attack(earth);
	}
}
