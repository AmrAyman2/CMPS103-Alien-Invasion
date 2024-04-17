#include "AlienSoldier.h"

AlienSoldier::AlienSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap) : ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

//////////////////////PHASE 2////////////////////
//void AlienSoldier::Attack(EarthArmy* army)
//{
//	int count = 0;
//	EarthSoldier* unitattacked;
//	while (army->ES_List.dequeue(unitattacked) && count < attackCapacity) {
//		int* unitattackedhp = unitattacked->getHealth();
//		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
//		count++;
//	}
//}
