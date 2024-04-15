#pragma once
#include "../ArmyUnit.h"
class AlienSoldier : public ArmyUnit 
{
public:
	AlienSoldier(int id, string Name, int tj, int hp, int power, int attackcap);
	//void Attack(EarthArmy* army);
};

