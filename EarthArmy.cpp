#include "EarthArmy.h"
bool EarthArmy::AddUnit(EarthSoldier* unit) {
	return EarthSoldierQueue.enqueue(unit);
}

void EarthArmy::Attack(AlienArmy* alien)
{
	LinkedQueue <EarthSoldier*> temp = EarthSoldierQueue;
	EarthSoldier* soldier;
	while (!temp.isEmpty()) {
		temp.dequeue(soldier);
		soldier->Attack(alien);
	}
}

