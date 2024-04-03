#include "EarthSoldier.h"
#include "../../AlienArmy.h"
#include "cmath"
EarthSoldier::EarthSoldier(int id, int tj, int hp, int power, int attackcap):ArmyUnit(id,"Earth Soldier", tj, hp, power, attackcap)
{
}

void EarthSoldier::Attack(AlienArmy* army)
{
	int count = 0;
	AlienSoldier* unitattacked;
	while (army->AlienSoldierQueue.dequeue(unitattacked) && count < attackCapacity) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		count++;
	}
}

