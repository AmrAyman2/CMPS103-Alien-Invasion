#pragma once
#include "../ArmyUnit.h"
//class AlienArmy;
class EarthSoldier :public ArmyUnit
{

public:
	EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
	//void Attack(AlienArmy* army); PHASE 2
	
};
