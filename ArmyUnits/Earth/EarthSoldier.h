#pragma once
#include "../ArmyUnit.h"
class AlienArmy;
class GameRules;
class EarthSoldier :public ArmyUnit
{
	private:
		bool infected;
		bool immuned;
	public:
		EarthSoldier(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);
		void Attack(GameRules* game, AlienArmy* army);
		bool isInfected();
		bool isImmuned();
		void setInfected(bool);
		void setImmuned(bool);
};
