#include "EarthTank.h"
void EarthTank::Attack()
{
	for (int i = 0; i < attackCapacity; i++)
	{
		monsterlist[i]->setHealth(health - power);
		if (monsterList[i]->getHealth <= 0)
			deathList->enqueue(monsterList[i]);
		else if (monsterList[i]->getHealth > 0)
			tempList->enqueue(monsterList[i]);
	}
	AlienMonster temp;
	for (int i = 0; i < attackCapacity; i++)
	{
		tempList->dequeue(temp);
		monsterList->insert(temp);
	}

}