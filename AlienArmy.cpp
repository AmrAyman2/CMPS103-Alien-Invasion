#include "AlienArmy.h"
bool AlienArmy::AddUnit(AlienSoldier* unit) 
{
	return AS_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienDrone* unit)
{
	return AD_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienMonster* unit)
{
	return AM_List.add(unit);
}

void AlienArmy::Attack(EarthArmy* earth)
{
	LinkedQueue <AlienSoldier*> temp = AS_List;
	AlienSoldier* soldier;
	while (!temp.isEmpty()) {
		temp.dequeue(soldier);
		soldier->Attack(earth);
	}

	Deque <AlienDrone*> temp2 = AD_List;
	AlienDrone* drone1;
	AlienDrone* drone2;
	while (!temp.isEmpty() && temp2.dequeue(drone1) && temp2.dequeueRear(drone2))
	{
		temp2.dequeue(drone1);
		drone1->Attack(earth);
		temp2.dequeueRear(drone2);
		drone2->Attack(earth);
	}

	ArrayBag<AlienMonster*> temp3 = AM_List;
	//using random generator which is yet to be done
}
