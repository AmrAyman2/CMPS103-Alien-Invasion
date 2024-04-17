#pragma once
#include "../ArmyUnit.h"
class AlienSoldier : public ArmyUnit 
{
	public:
		AlienSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		//void Attack(EarthArmy* army); PHASE 2
};