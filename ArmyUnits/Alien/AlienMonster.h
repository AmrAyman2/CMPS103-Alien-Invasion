#pragma once
#include "../ArmyUnit.h"
#include "../../EarthArmy.h"
class AlienMonster: public ArmyUnit
{
	public:
		AlienMonster();
		AlienMonster(int id, int jt, int hp, int power, int attackCap);
		void Attack(EarthArmy* army);
};
		ostream& operator<<(ostream& os, const AlienMonster monster);