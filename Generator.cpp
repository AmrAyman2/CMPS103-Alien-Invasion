#include <iostream>
#include "Generator.h"
using namespace std;

Generator::Generator(Input& i1,EarthArmy& e1, AlienArmy& a1) {
	I1 = &i1;
	E1 = &e1;
	A1 = &a1;
}

void Generator::generateEarth() {
	srand(time(0));
	int A = rand() % (100) + 1;
	if (A <= I1->getProb())
	{
		for (int i = 0; i < I1->getN(); i++)
		{
			int B= rand() % (100) + 1;
			if (B > 0 && B < I1->getES())
			{
				EarthSoldier *newSoldier = new EarthSoldier;
				newSoldier->setID(newSoldier->getTroopCount());
				newSoldier->setHealth(rand() % (I1->geteHealth_upper() - I1->geteHealth_upper() + 1) + I1->geteHealth_lower());
				newSoldier->setAttackCapacity(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				newSoldier->setPower(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				E1->AddUnit(newSoldier);
			}
			else if (B > I1->getES() && B < (I1->getES() + I1->getET()))
			{
				EarthTank* newTank= new EarthTank;
				newTank->setID(newTank->getTroopCount()+333);
				newTank->setHealth(rand() % (I1->geteHealth_upper() - I1->geteHealth_upper() + 1) + I1->geteHealth_lower());
				newTank->setAttackCapacity(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				newTank->setPower(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				E1->AddUnit(newTank);
			}
			else
			{
				EarthGunnery* newGunnery = new EarthGunnery;
				newGunnery->setID(newGunnery->getTroopCount()+666);
				newGunnery->setHealth(rand() % (I1->geteHealth_upper() - I1->geteHealth_upper() + 1) + I1->geteHealth_lower());
				newGunnery->setAttackCapacity(rand() % (I1->geteAttack_upper() - I1->geteAttack_lower() + 1) + I1->geteAttack_lower());
				newGunnery->setPower(rand() % (I1->getePower_upper() - I1->getePower_lower() + 1) + I1->getePower_lower());
				E1->AddUnit(newGunnery);
			}
		}
	}
}

void Generator::generateAlien() {
	srand(time(0));
	int A = rand() % (100) + 1;
	if (A <= I1->getProb())
	{
		for (int i = 0; i < I1->getN(); i++)
		{
			int B = rand() % (100) + 1;
			if (B > 0 && B < I1->getAS())
			{
				AlienSoldier* newaSoldier = new AlienSoldier;
				newaSoldier->setID(newaSoldier->getTroopCount()+2000);
				newaSoldier->setHealth(rand() % (I1->getaHealth_upper() - I1->getaHealth_upper() + 1) + I1->getaHealth_lower());
				newaSoldier->setAttackCapacity(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				newaSoldier->setPower(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				A1->AddUnit(newaSoldier);
			}
			else if (B > I1->getAS() && B < (I1->getAS() + I1->getAM()))
			{
				AlienMonster* newMonster = new AlienMonster;
				newMonster->setID(newMonster->getTroopCount() + 2333);
				newMonster->setHealth(rand() % (I1->getaHealth_upper() - I1->getaHealth_upper() + 1) + I1->getaHealth_lower());
				newMonster->setAttackCapacity(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				newMonster->setPower(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				A1->AddUnit(newMonster);
			}
			else
			{
				AlienDrone* newDrone = new AlienDrone;
				newDrone->setID(newDrone->getTroopCount() + 2666);
				newDrone->setHealth(rand() % (I1->getaHealth_upper() - I1->getaHealth_upper() + 1) + I1->getaHealth_lower());
				newDrone->setAttackCapacity(rand() % (I1->getaAttack_upper() - I1->getaAttack_lower() + 1) + I1->getaAttack_lower());
				newDrone->setPower(rand() % (I1->getaPower_upper() - I1->getaPower_lower() + 1) + I1->getaPower_lower());
				A1->AddUnit(newDrone);
			}
		}
	}

}

