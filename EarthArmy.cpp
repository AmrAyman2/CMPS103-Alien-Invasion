#include "EarthArmy.h"
bool EarthArmy::AddUnit(EarthSoldier* unit) 
{
	return ES_List.enqueue(unit);
}

bool EarthArmy::AddUnit(EarthTank* unit)
{
	return ET_List.push(unit);
}

bool EarthArmy::AddUnit(EarthGunnery* unit)
{
	int highestcombo = (*unit->getHealth() * unit->getPower()); //highest product of health and power of unit is best
	return EG_List.enqueue(unit, highestcombo);
}

void EarthArmy::Attack(AlienArmy* alien)
{
	LinkedQueue <EarthSoldier*> temp = ES_List;
	EarthSoldier* soldier;
	while (!temp.isEmpty()) {
		temp.dequeue(soldier);
		soldier->Attack(alien);
	}
}