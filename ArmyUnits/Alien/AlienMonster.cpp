#include "AlienMonster.h"

AlienMonster::AlienMonster(int id, const string& unitType, int jointime, int hp, int pow, int attackcap): ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

////////////////////////PHASE 2////////////////////////
/*void AlienMonster::Attack(EarthArmy* army)
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
}*/

/*ostream& operator<<(ostream& os, const AlienMonster monster)
{
	
	cout << monster.getID();
}*/