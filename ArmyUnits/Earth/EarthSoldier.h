#pragma once
#include "../ArmyUnit.h"
//class AlienArmy;
class EarthSoldier :public ArmyUnit
{

public:
	EarthSoldier();
	EarthSoldier(int id,string ,int tj, int hp, int power, int attackcap);
	//void Attack(AlienArmy* army);
	
};
