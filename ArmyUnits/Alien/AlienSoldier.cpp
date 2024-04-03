#include "AlienSoldier.h"
#include "cmath"
AlienSoldier::AlienSoldier(int id,int tj,int hp,int pow,int attackcap) : ArmyUnit(id,"Alien Soldier",tj,hp,pow,attackcap) {

}

void AlienSoldier::Attack(EarthArmy* army)
{
	int count = 0;
	EarthSoldier* unitattacked;
	while (army->EarthSoldierQueue.dequeue(unitattacked) && count < attackCapacity) {
		int* unitattackedhp = unitattacked->getHealth();
		*unitattackedhp -= (power * health / 100) / sqrt(*unitattackedhp);
		count++;
	}
}
