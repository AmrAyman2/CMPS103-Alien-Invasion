#include "EarthTank.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"
EarthTank::EarthTank (int id, const string& unitType, int jointime, int hp, int pow, int attackcap) : ArmyUnit(id, unitType, jointime, hp, pow, attackcap){}

//////////////////PHASE 2/////////////////
void EarthTank::Attack(GameRules* game, AlienArmy* armyA, EarthArmy* armyE)
{
	ArrayStack<AlienMonster*> tempMons;
	AlienMonster* unitattacked_m;
	AlienSoldier* unitattacked_s;
	//if (armyA->getAM_List().isEmpty() && armyA->getAS_List().isEmpty()) return; // check first, if there is no AM & AS that exist THEN no need to enter loop
	for (int i = 0; i < attackCapacity; i++)
	{
		if (armyE->ES_Count() < 0.3 * armyA->AS_Count()) //Checks Count of ES to AS
		{
			// Tank here should attack both AM & AS, if they both exist
			// If one does not exist it attacks other

			if (!armyA->getAM_List().isEmpty()) //Tank attacks an AM if exists
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n\n Tank with ID: " << this->getID() << " shoots " << unitattacked_m->getID() << "\n\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
				
			if (!armyA->getAS_List().isEmpty()) //Tank attacks an AS if exists
			{
				armyA->getAS_List().dequeue(unitattacked_s);
				int* S_Hp = unitattacked_s->getHealth();
				cout << "\n\n Tank with ID: " << this->getID() << " shoots " << unitattacked_s->getID() << "\n\n";
				*S_Hp -= (power * health / 100) / sqrt(*S_Hp);
				if (*unitattacked_s->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_s);
				else
					armyA->getAS_List().enqueue(unitattacked_s);
			}		
		}
		else if (armyE->ES_Count() >= 0.8 * armyA->AS_Count()) //Checks Count of ES to AS
		{
			if (!armyA->getAM_List().isEmpty())
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n\n Tank with ID: " << this->getID() << " shoots " << unitattacked_m->getID() << "\n\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
		}
		else //for case when count is between 0.3 and 0.8
		{
			if (!armyA->getAM_List().isEmpty())
			{
				armyA->getAM_List().pop(unitattacked_m);
				int* M_Hp = unitattacked_m->getHealth();
				cout << "\n\n Tank with ID: " << this->getID() << " shoots " << unitattacked_m->getID() << "\n\n";
				*M_Hp -= (power * health / 100) / sqrt(*M_Hp);
				if (*unitattacked_m->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_m);
				else
					tempMons.push(unitattacked_m);
			}
		}
	}

	while (!tempMons.isEmpty())
	{
		tempMons.pop(unitattacked_m);
		armyA->getAM_List().add(unitattacked_m);
	}
}
////////////////////////PHASE 2///////////////////////////////
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
// if (ES<0.3*AS)
//*     while(ES!>=0.8 AS)
//*          attack();
//*          attacksp():

//////////////////PHASE 2///////////////////////
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
/////////////////////////PHASE 2//////////////////////
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