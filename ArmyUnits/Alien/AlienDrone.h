#pragma once
#include "../ArmyUnit.h"
#include "../../EarthArmy.h"
class AlienDrone : public ArmyUnit
{
	public:
		AlienDrone();
		AlienDrone(int id, int jt, int hp, int power, int attackCap);
		void Attack(EarthArmy* army);
};

