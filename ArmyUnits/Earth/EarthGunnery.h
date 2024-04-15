#pragma once
#include "../ArmyUnit.h"
class EarthGunnery:public ArmyUnit
{
	public:
		EarthGunnery(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		//void Attack(AlienArmy* army); PHASE 2
};