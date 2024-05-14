#include "AlienDrone.h"

AlienDrone::AlienDrone(int id, const string& unitType, int jointime, int hp, int pow, int attackcap): ArmyUnit(id, unitType , jointime, hp, pow, attackcap) {}

///////////////PHASE 2///////////////////
//void AlienDrone::Attack(EarthArmy* army)
//{
//	int count = 0;
//	EarthTank* tankattacked; EarthGunnery* gunneryattacked;
//	int highestcombo = (*gunneryattacked->getHealth() * gunneryattacked->getPower()); //highest product of health and power of unit is best
//	while (army->EG_List.dequeue(gunneryattacked, highestcombo) && army->ET_List.pop(tankattacked) && count < attackCapacity)
//	{
//		int* tankattackedhp = tankattacked->getHealth();
//		int* gunneryattackedhp = gunneryattacked->getHealth();
//		*tankattackedhp -= (power * health / 100) / sqrt(*tankattackedhp);
//		*gunneryattackedhp -= (power * health / 100) / sqrt(*gunneryattackedhp);
//		count++;
//	}
//} 
ostream& operator<<(ostream& os, const AlienDrone drone)
{
	os << drone.getID();
	return os;
}