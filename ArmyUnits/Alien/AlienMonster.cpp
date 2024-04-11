#include "AlienMonster.h"
AlienMonster::AlienMonster(int id, int jt, int hp, int power, int attackCap):ArmyUnit(id, "Alien Monster", jt, hp, power, attackCap) {}

void AlienMonster::Attack(EarthArmy* army)
{
	int count = 0;
	EarthTank* tankattacked; EarthSoldier* soldierattacked;
	while (army->ES_List.dequeue(soldierattacked) && army->ET_List.pop(tankattacked) && count < attackCapacity)
	{
		int* tankattackedhp = tankattacked->getHealth();
		int* soldierattackedhp = soldierattacked->getHealth();
		*tankattackedhp -= (power * health / 100) / sqrt(*tankattackedhp);
		*soldierattackedhp -= (power * health / 100) / sqrt(*soldierattackedhp);
		count++;
	}
}