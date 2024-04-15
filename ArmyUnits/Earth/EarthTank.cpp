#include "EarthTank.h"
#include "EarthSoldier.h"
#include "../Alien/AlienSoldier.h"
#include "../Alien/AlienMonster.h"
#include "../../ArmyUnits/ArmyUnit.h"
#include "../../EarthArmy.h"

EarthTank::EarthTank(int id,string name, int tj, int hp, int power, int attackcap):ArmyUnit(id, name, tj, hp, power, attackcap)
{
}

// Attack function of unit tank gets the required number of monsters and reduces its health
// if dead its sent to dead list, else its ent to temp list
// after the tank finishes attacking, monsters in templist are sent back to monsterlist
//void EarthTank::AttackNor()
//{
//	for (int i = 0; i < attackCapacity; i++)
//	{
//		monsterlist[i]->setHealth(health - power);
//		if (monsterList[i]->getHealth <= 0)
//			deathList->enqueue(monsterList[i]);
//		else if (monsterList[i]->getHealth > 0)
//			tempList->enqueue(monsterList[i]);
//	}
//	AlienMonster temp;
//	for (int i = 0; i < attackCapacity; i++)
//	{
//		tempList->dequeue(temp);
//		monsterList->insert(temp);
//	}
//
//}
//the overrriden function should call both attacks
// if ES is< 0.3*AS, themn tanks should attack AS using attacksp
// in Game rules when calling tanks to attack
/* if (ES<0.3*AS)
*     while(ES!>=0.8 AS)
*          attack();
*          attacksp():
*/

//void EarthTank::AttackSp() {
//	for (int i = 0; i < attackCapacity; i++)
//	{
//		ALienSoldierlist[i]->setHealth(health - power);
//		if (ALienSoldierList[i]->getHealth <= 0)
//			deathList->enqueue(ALienSoldierList[i]);
//		else if (monsterList[i]->getHealth > 0)
//			tempList->enqueue(ALienSoldierList[i]);
//	}
//	ALienSoldier temp;
//	for (int i = 0; i < attackCapacity; i++)
//	{
//		tempList->dequeue(temp);
//		ALienSoldierList->insert(temp);
//	}
//}

//void EarthTank::Attack() {
//	if (ES->getCount() < 0.3 * AS->getCount())
//	{
//		attackSoldiers = true;
//	}
//	if(ES->getCount() > 0.8 * AS->getCount())
//		attackSoldiers = false;
//	if (attackSoldiers)
//	{
//		AttackNor();
//		AttackSp();
//	}
//	else
//		AttackNor();
//}