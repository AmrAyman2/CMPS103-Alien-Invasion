#pragma once
#include "ADS/LinkedQueue.h"
#include "ArmyUnits/ArmyUnit.h"
#include "ArmyUnits/Earth/EarthSoldier.h"
class EarthArmy {
public:
	LinkedQueue<EarthSoldier*> EarthSoldierQueue;

	bool AddUnit(EarthSoldier* unit);
	void Attack(AlienArmy* alien);
};