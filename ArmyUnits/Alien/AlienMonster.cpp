#include "AlienMonster.h"
#include "../../EarthArmy.h"
#include "../../GameRules.h"

AlienMonster::AlienMonster(int id, const string& unitType, int jointime, int hp, int pow, int attackcap): ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}
void AlienMonster::Attack(GameRules* game, EarthArmy* army)
{
	// Alien Monster should attack both ET & ES, if they both exist
	// If one does not exist it attacks other

	ArrayStack<EarthTank*> tempTank;
	EarthTank* unitattacked_T;
	EarthSoldier* unitattacked_S;
	if (army->getET_List().isEmpty() && army->getES_List().isEmpty()) return; // check first, if there is no ET & ES that exist THEN no need to enter loop
	for (int i = 0; i < attackCapacity; i++)
	{
		if (army->getET_List().isEmpty() || army->getES_List().isEmpty())
		{
			if (!army->getET_List().isEmpty()) //Attacking Earth Tank
			{
				army->getET_List().pop(unitattacked_T);
				int* Tank_Hp = unitattacked_T->getHealth();
				*Tank_Hp -= (power * health / 100) / sqrt(*Tank_Hp);
				if (*unitattacked_T->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_T);
				else
					tempTank.push(unitattacked_T);
			}

			if (!army->getES_List().isEmpty()) //Attacking Earth Soldier
			{
				army->getES_List().dequeue(unitattacked_S);
				int* Sold_Hp = unitattacked_S->getHealth();
				*Sold_Hp -= (power * health / 100) / sqrt(*Sold_Hp);
				if (*unitattacked_S->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_S);
				else
					army->getES_List().enqueue(unitattacked_S);
			}
		}
		else
		{
			if (i % 2 != 0) //Attack is divided between both ET and ES if BOTH lists are not empty
			{
				//Attacking Earth Tank
				army->getET_List().pop(unitattacked_T);
				int* Tank_Hp = unitattacked_T->getHealth();
				*Tank_Hp -= (power * health / 100) / sqrt(*Tank_Hp);
				if (*unitattacked_T->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_T);
				else
					tempTank.push(unitattacked_T);
			}
			else
			{
				//Attacking Earth Soldier
				army->getES_List().dequeue(unitattacked_S);
				int* Sold_Hp = unitattacked_S->getHealth();
				*Sold_Hp -= (power * health / 100) / sqrt(*Sold_Hp);
				if (*unitattacked_S->getHealth() <= 0)
					game->getkilledlist().enqueue(unitattacked_S);
				else
					army->getES_List().enqueue(unitattacked_S);
			}
		}
	}

	while (!tempTank.isEmpty())
	{
		tempTank.pop(unitattacked_T);
		army->getET_List().push(unitattacked_T);
	}
}
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

