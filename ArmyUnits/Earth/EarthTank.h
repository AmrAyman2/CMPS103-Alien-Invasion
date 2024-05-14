#pragma once
#include "../ArmyUnit.h"
#include "../../ADS/ArrayStack.h"
class AlienArmy;
class EarthArmy;
class GameRules;
class EarthTank:public ArmyUnit
{
	public:
		EarthTank(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, AlienArmy* army, EarthArmy* armyE);
		/*void AttackNor();
		void AttackSp();
		void Attack();*///PHASE 2////
};