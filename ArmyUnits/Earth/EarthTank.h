#pragma once
#include "../ArmyUnit.h"
#include "../Alien/AlienMonster.h"
class EarthTank:public ArmyUnit
{
private:
	bool attackSoldiers;
public:
	EarthTank(int id, int tj, int hp, int power, int attackcap);
	void AttackNor();
	void AttackSp();
	void Attack();

};

