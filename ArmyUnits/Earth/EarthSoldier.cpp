#include "EarthSoldier.h"

EarthSoldier::EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap):ArmyUnit(id, unitType, jointime, hp, pow, attackcap) {}

////////////////////PHASE 2/////////////////
//void EarthSoldier::Attack(AlienArmy* army)
//{
//	int count = 0;
//	AlienSoldier* unitattacked;
//	while (army->AS_List.dequeue(unitattacked) && count < attackCapacity) {
//		int* unitattackedhp = unitattacked->getHealth();
//		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
//		count++;
//	}
//}

