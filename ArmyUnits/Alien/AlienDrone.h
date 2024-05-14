#pragma once
#include "../ArmyUnit.h"

class AlienDrone : public ArmyUnit
{
	public:
			 AlienDrone(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
			//void Attack(EarthArmy* army); PHASE 2
};

ostream& operator<<(ostream& os, const AlienDrone drone);