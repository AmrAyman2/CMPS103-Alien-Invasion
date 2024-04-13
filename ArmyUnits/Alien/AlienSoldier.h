#pragma once
#include "../ArmyUnit.h"
#include "../../EarthArmy.h"
class AlienSoldier : public ArmyUnit 
{
public:
	AlienSoldier();
	AlienSoldier(int id,int tj, int hp, int power, int attackcap);
	void Attack(EarthArmy* army);
};

