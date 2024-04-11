#pragma once
#include "ADS/LinkedQueue.h"
#include "ADS/priQueue.h"
#include "ADS/ArrayStack.h"
#include "ArmyUnits/ArmyUnit.h"
#include "ArmyUnits/Earth/EarthSoldier.h"
#include "ArmyUnits/Earth/EarthTank.h"
#include "ArmyUnits/Earth/EarthGunnery.h"
class EarthArmy {
public:
	LinkedQueue<EarthSoldier*> ES_List;
	ArrayStack<EarthTank*> ET_List;
	priQueue<EarthGunnery*> EG_List;

	bool AddUnit(EarthSoldier* unit);
	bool AddUnit(EarthTank* unit);
	bool AddUnit(EarthGunnery* unit);
	void Attack(AlienArmy* alien);
};