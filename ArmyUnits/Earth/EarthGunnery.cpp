#include "EarthGunnery.h"

EarthGunnery::EarthGunnery(int id,string name, int tj, int hp, int power, int attackcap):ArmyUnit(id, name, tj, hp, power, attackcap) {}

int EarthGunnery::getPriority()
{
	return (power * health);
}

//void EarthGunnery::Attack(AlienArmy* army)
//{
//
//
//}