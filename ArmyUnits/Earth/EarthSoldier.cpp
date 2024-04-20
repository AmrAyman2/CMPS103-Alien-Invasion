#include "EarthSoldier.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

EarthSoldier::EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap):ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

//////////////////PHASE 2/////////////////
void EarthSoldier::Attack(GameRules* game, AlienArmy* army)
{
	int count = 0;
	AlienSoldier* unitattacked;
	while (army->getAS_List().dequeue(unitattacked) && count < attackCapacity) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		if (*unitattacked->getHealth() <= 0)
			game->getkilledlist().enqueue(unitattacked);
		else
			army->getAS_List().enqueue(unitattacked);
		count++;
	}
}