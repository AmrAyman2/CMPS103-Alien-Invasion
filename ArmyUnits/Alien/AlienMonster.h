#pragma once
#include "../ArmyUnit.h"
class AlienMonster: public ArmyUnit
{
	public:
		AlienMonster(int id,string name ,int jt, int hp, int power, int attackCap);
		//void Attack(EarthArmy* army);
};
		//ostream& operator<<(ostream& os, const AlienMonster monster);