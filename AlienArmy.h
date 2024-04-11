#pragma once
#include "ArmyUnits/Alien/AlienSoldier.h"
class AlienArmy
{
public:
	LinkedQueue<AlienSoldier*> AlienSoldierQueue;

	bool AddUnit(AlienSoldier* unit);
	void Attack(EarthArmy* earth);
};

