#pragma once
#include "../ArmyUnit.h"
class EarthTank:public ArmyUnit
{
	public:
		EarthTank(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		/*void AttackNor();
		void AttackSp();
		void Attack();*///PHASE 2////
};