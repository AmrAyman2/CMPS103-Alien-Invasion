#pragma once
#include "../ArmyUnit.h"
class AlienMonster: public ArmyUnit
{
	public:
		AlienMonster(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		//void Attack(EarthArmy* army); PHASE 2
};
		//ostream& operator<<(ostream& os, const AlienMonster monster); PHASE 2