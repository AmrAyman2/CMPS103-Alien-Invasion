#include "GameRules.h"
#include "Generator.h"
#include "ADS/priQueue.h"
using namespace std;

GameRules::GameRules(EarthArmy& e, AlienArmy& a, Input& i) {
	//myEarth = e;
	//*myAlien = a;
	//*myI = i;
	myEarth = &e;
	myAlien = &a;
	myI = &i;
}

void GameRules::printDeadList() {
	cout << endl;
	cout << "============== Killed / Destructed Units ===========" << endl;
	LinkedQueue<ArmyUnit*> temp(getkilledlist());
	int killedcount=getdeadlistcount();
	cout << killedcount << " Dead Units" << endl;
	temp.print();
}
int GameRules::getdeadlistcount()
{
	LinkedQueue<ArmyUnit*> temp(getkilledlist());
	int count = 0;
	ArmyUnit* trash;
	while (!temp.isEmpty()) {
		temp.dequeue(trash);
		count++;
	}
	return count;
}
void GameRules::War() {
	Generator myGen(myI, myEarth, myAlien, this);

	while (timeStep <= 500)
	{
		cout << "\n\n\t ============ Time Step " << timeStep << " =============\n\n";
		myGen.generateEarth();
		myGen.generateAlien();
		/* ------- Attacking Logic ------- */
		myEarth->Attack(this, myAlien);
		myAlien->Attack(this, myEarth);
		myEarth->print();
		myAlien->print();
		printDeadList();
		timeStep++;
	}

	
	//if (timeStep > 100)
	//{
	//	while (timeStep < 100)
	//	{
	//		cout << "\n\n\t ============ Time Step " << timeStep << " =============\n\n";
	//		myGen.generateEarth();
	//		myGen.generateAlien();
	//		//Attack Logic
	//		myEarth->Attack(this, myAlien);
	//		myAlien->Attack(this, myEarth);
	//		myEarth->print();
	//		myAlien->print();
	//		printDeadList();
	//		if (myEarth->getTotalCount() > 0 && myAlien->getTotalCount() == 0)
	//		{
	//			Winner = "Earth Army";
	//			Victory = true;
	//			cout << "Winner Winner Chicken Dinner:: Planet Earth" << endl;
	//		}
	//		else if (myAlien->getTotalCount() > 0 && myEarth->getTotalCount() == 0)
	//		{
	//			Winner = "Alien Army";
	//			Victory = true;
	//			cout << "Winner Winner Chicken Dinner:: Planet ET" << endl;
	//		}
	//		timeStep++;
	//	}
	//}
}



int GameRules::gettimeStep() {
	return timeStep;
}

LinkedQueue<ArmyUnit*>& GameRules::getkilledlist()
{
	return killedlist;
}

Input& GameRules::getInput() {
	return *myI;
}

//void GameRules::test() 
//{
//	Input* input = new Input();
//	AlienArmy* aliens = new AlienArmy;
//	EarthArmy* human = new EarthArmy;
//	//GameRules* game = new GameRules;
//	Generator* generator = new Generator(*input, *human, *aliens, *this);
//	EarthSoldier* earthtop;
//	EarthTank* tanktop;
//	EarthGunnery* topgunMaverick;
//	int trash=0;
//	AlienSoldier* alientop;
//	AlienMonster* monstertop;
//	AlienDrone* dronetop;
//	AlienDrone* dronerear;
//	LinkedQueue<ArmyUnit*> templist;
//	priQueue<EarthGunnery*> tempGun;
//
//	int time = gettimeStep();
//
//	for (int i = 0;i < 50;i++) 
//	{
//			cout << "                     Time Step: " << i+1 << endl;
//			generator->generateEarth();
//			generator->generateAlien();
//			int A = (rand() % (100)) + 1;
//			if (A > 0 && A < 10) {
//				if(human->getES_List().dequeue(earthtop))
//				human->getES_List().enqueue(earthtop);
//			}
//			else if (A > 10 && A < 20) {
//				if (human->getET_List().pop(tanktop))
//				{
//					getkilledlist().enqueue(tanktop);
//				}
//			}
//			else if (A > 20 && A < 30) {
//				if(!human->getEG_List().isEmpty()) {
//					human->getEG_List().dequeue(topgunMaverick, trash);
//					topgunMaverick->setHealth((*topgunMaverick->getHealth() / 2));
//					int newpri = (*topgunMaverick->getHealth() * topgunMaverick->getPower());
//					tempGun.enqueue(topgunMaverick,newpri);
//				}
//				if (!tempGun.isEmpty()) {
//					tempGun.dequeue(topgunMaverick, trash);
//					int newpri2 = (*topgunMaverick->getHealth() * topgunMaverick->getPower());
//					human->getEG_List().enqueue(topgunMaverick,newpri2);
//				}
//			}
//			else if (A > 30 && A < 40) {
//				for (int j = 0;j < 5;j++) {
//					if (aliens->getAS_List().dequeue(alientop))
//					{
//						alientop->setHealth(*alientop->getHealth() - 1);
//						templist.enqueue(alientop);
//						ArmyUnit* au = alientop;
//						templist.dequeue(au);
//						alientop =(AlienSoldier*) au;
//						aliens->getAS_List().enqueue(alientop);
//					}
//				}
//			}
//			else if (A > 40 && A < 50) {
//				for (int k = 0; k < 5;k++) {
//
//					if (aliens->getAM_List().remove(monstertop))
//						aliens->getAM_List().add(monstertop);
//				}
//			}
//			else if (A > 50 && A < 60) {
//				for (int z = 0;z <3 ;z++) {
//					if(aliens->getAD_List().dequeueRear(dronerear))
//						getkilledlist().enqueue(dronerear);
//				}
//				for (int m = 0;m < 3;m++) {
//					if(aliens->getAD_List().dequeue(dronetop))
//						getkilledlist().enqueue(dronetop);
//				}
//			}
//			human->print();
//			aliens->print();
//			printDeadList();
//			cout << endl;
//			cout << endl;
//			time++;
//		}
//}
//
//
