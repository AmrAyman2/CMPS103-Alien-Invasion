#include "AlienSoldier.h"
//#include "cmath"
AlienSoldier::AlienSoldier()
{
}
AlienSoldier::AlienSoldier(int id,string Name,int tj, int hp, int pow, int attackcap) : ArmyUnit(id, Name, tj, hp, pow, attackcap) 
{
}

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
