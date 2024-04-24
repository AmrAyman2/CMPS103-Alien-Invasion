#pragma once
#include "ADS/LinkedQueue.h"
#include "ADS/priQueue.h"
#include "ADS/ArrayStack.h"
#include "ArmyUnits/ArmyUnit.h"
#include "ArmyUnits/Earth/EarthSoldier.h"
#include "ArmyUnits/Earth/EarthTank.h"
#include "ArmyUnits/Earth/EarthGunnery.h"
class AlienArmy;
class GameRules;
class EarthArmy {
private:
	LinkedQueue<EarthSoldier*> ES_List;
	ArrayStack<EarthTank*> ET_List;
	priQueue<EarthGunnery*> EG_List;
public:
	EarthArmy() {};
	bool AddUnit(EarthSoldier* unit);
	bool AddUnit(EarthTank* unit);
	bool AddUnit(EarthGunnery* unit);
	int ES_Count();
	void ES_PrintID();
	int ET_Count();
	void ET_PrintID();
	int EG_Count();
	void EG_PrintID();
	int getTotalCount();
	void print();
	void Attack(GameRules* game,AlienArmy* alien);

	LinkedQueue<EarthSoldier*>& getES_List();
	ArrayStack<EarthTank*>& getET_List();
	priQueue<EarthGunnery*>& getEG_List();
};