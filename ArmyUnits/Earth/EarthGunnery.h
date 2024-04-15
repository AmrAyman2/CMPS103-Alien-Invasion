#pragma once
#include "../ArmyUnit.h"
class EarthGunnery:public ArmyUnit
{
	public:
		EarthGunnery(int id,string, int tj, int hp, int power, int attackcap);
		//void Attack(AlienArmy* army);
};