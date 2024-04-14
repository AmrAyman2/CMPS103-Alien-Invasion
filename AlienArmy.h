#pragma once
#include "ArmyUnits/Alien/AlienSoldier.h"
#include "ArmyUnits/Alien/AlienDrone.h"
#include "ArmyUnits/Alien/AlienMonster.h"
#include "ADS/Deque.h"
#include "ADS/ArrayBag.h"
class AlienArmy
{
public:
	LinkedQueue<AlienSoldier*> AS_List;
	Deque<AlienDrone*> AD_List;
	ArrayBag<AlienMonster*> AM_List;

	bool AddUnit(AlienSoldier* unit);
	bool AddUnit(AlienDrone* unit);
	bool AddUnit(AlienMonster* unit);
	void Attack(EarthArmy* earth);
	int AS_Count();
	void AS_PrintID();
	int AD_Count();
	void AD_PrintID();
	int AM_Count();
	void AM_PrintID();
	int getTotalCount();
	void print();
};

