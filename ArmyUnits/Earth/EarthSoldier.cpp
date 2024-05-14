#include "EarthSoldier.h"
#include "../../AlienArmy.h"
#include "../../GameRules.h"

EarthSoldier::EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap):ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

//////////////////PHASE 2/////////////////
void EarthSoldier::Attack(GameRules* game, AlienArmy* army)
{
	int count = 0;
	AlienSoldier* unitattacked;
	while (army->getAS_List().dequeue(unitattacked) && count < attackCapacity && count < army->AS_Count()) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		if (*unitattackedhp <= 0) {
			game->getkilledlist().enqueue(unitattacked);
			unitattacked->setTD(game->gettimeStep());
		}
		else if (*unitattackedhp > 0 && *unitattackedhp < (0.2 * unitattacked->getjoinHealth()));
		
		else
			army->getAS_List().enqueue(unitattacked);
		count++;
	}
}

bool EarthSoldier::isInfected() {
	return infected;
}
bool EarthSoldier::isImmuned() {
	return immuned;
}
void EarthSoldier::setInfected(bool b) {
	infected = b;
}
void EarthSoldier::setImmuned(bool b) {
	immuned = b;
}