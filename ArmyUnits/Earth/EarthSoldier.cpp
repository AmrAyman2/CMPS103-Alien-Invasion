#include "EarthSoldier.h"
EarthSoldier::EarthSoldier()
{
}
//#include "../../AlienArmy.h"
//#include "cmath"
EarthSoldier::EarthSoldier(int id,string name, int tj, int hp, int power, int attackcap):ArmyUnit(id,name, tj, hp, power, attackcap)
{
	
}

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

