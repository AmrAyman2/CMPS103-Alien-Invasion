#pragma once
#include "../ArmyUnit.h"

class AlienDrone : public ArmyUnit
{
	public:
		AlienDrone(int id,string name ,int jt, int hp, int power, int attackCap);
		//void Attack(EarthArmy* army);
};

