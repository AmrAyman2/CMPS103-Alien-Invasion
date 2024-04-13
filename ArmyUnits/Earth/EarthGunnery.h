#pragma once
#include "../ArmyUnit.h"
#include "../../AlienArmy.h"
class EarthGunnery:public ArmyUnit
{
	public:
		EarthGunnery(int id, int tj, int hp, int power, int attackcap);
		EarthGunnery();
		void Attack(AlienArmy* army);
};