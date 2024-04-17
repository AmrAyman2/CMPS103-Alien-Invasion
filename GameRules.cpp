#include "GameRules.h"
#include "Generator.h"
#include "ADS/priQueue.h"
using namespace std;



// Kamel ya bro @Ahmed Farouk
int GameRules::getDeadCount()
{
	LinkedQueue<ArmyUnit*> temp;
	int killedcount = 0;
	ArmyUnit* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		killedcount++;
	}
	return killedcount;
}
void GameRules::printDeadList() {
	cout << "============== Killed / Destructed Units ==============" << endl;
	LinkedQueue<ArmyUnit*> temp;
	ArmyUnit* temppointer;
	cout << getDeadCount() << " units " << "[";				
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		cout << temppointer->getID() << ", " ;

		/*if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";*/
	}
	cout << "]" << endl;
}
//void GameRules::War() {
//	Input I1;           
//	EarthArmy Earth;    
//	AlienArmy Aliens;   
//	Generator generate(I1,Earth,Aliens,*this);
//	while (timeStep <= 40)
//	{
//		generate.generateEarth();
//		generate.generateAlien();
//		//Attack Logic
//		//Earth.printArmy();
//		//Alien.printArmy();
//		//printDeadlist();
//		timeStep++;
//	}
//	if (timeStep > 40)
//	{
//		while (!Victory)
//		{
//			generate.generateEarth();
//			generate.generateAlien();
//			//Attack Logic
//			//Earth.printArmy()
//			//Alien.printArmy()
//			//printDeadList()
//			if (Earth.getTotalCount() > 0 && Alien.getTotalCount() == 0)
//			{
//				Winner = "Earth Army";
//				Victory = true;
//			}
//			else if (Alien.getTotalCount() > 0 && Earth.getTotalCount() == 0)
//			{
//				Winner = "Alien Army";
//				Victory = true;
//			}
//			timeStep++;
//		}
//	}
//}

GameRules::GameRules(){}

int GameRules::gettimeStep() {
	return timeStep;
}

void GameRules::getkilledlist(LinkedQueue<ArmyUnit*>& ripkilled)
{
	ripkilled = killedlist;
}

// Kamel ya bro @Ahmed Farouk
void GameRules::test() 
{
	Input* input = new Input();
	AlienArmy* aliens = new AlienArmy;
	EarthArmy* human = new EarthArmy;
	//GameRules* game = new GameRules;
	Generator* generator = new Generator(*input, *human, *aliens, *this);
	EarthSoldier* earthtop;
	EarthTank* tanktop;
	EarthGunnery* topgunMaverick;
	int pri=0;
	int trash=0;
	AlienSoldier* alientop;
	AlienMonster* monstertop;
	AlienDrone* dronetop;
	AlienDrone* dronerear;
	//LinkedQueue<ArmyUnit*> killedlist;
	LinkedQueue<ArmyUnit*> templist;
	priQueue<EarthGunnery*> tempGun;

	int time = gettimeStep();


	for (int i = 0;i < 50;i++) 
{
		generator->generateEarth();
		generator->generateAlien();
		int A = (rand() % (100)) + 1;
		if (A > 0 && A < 10) {
			if(human->getES_List().dequeue(earthtop))
			human->getES_List().enqueue(earthtop);
		}
		else if (A > 10 && A < 20) {
			if (human->getET_List().pop(tanktop))
			{
				//getkilledlist(killedlist);
				killedlist.enqueue(tanktop);
			}
		}
		else if (A > 20 && A < 30) {
			//FIX THIS CRAP
			
			/*if(human->getEG_List().dequeue(topgun, pri))
			{
				topgun->setHealth((*topgun->getHealth()) / 2);
				human->getEG_List().enqueue(topgun, pri/2);
			}*/
			/*if (!((human->getEG_List()).isEmpty()))
			{
				human->getEG_List().dequeue(topgunMaverick, pri);
				topgunMaverick->setHealth(*(topgunMaverick->getHealth()) / 2);
				human->getEG_List().enqueue(topgunMaverick, pri);
			}*/
			
		
			
			
			if(!human->getEG_List().isEmpty()) {
				human->getEG_List().dequeue(topgunMaverick, trash);
				topgunMaverick->setHealth((*topgunMaverick->getHealth() / 2));
				//int newpri = (*temppointer->getHealth() * temppointer->getPower());
				tempGun.enqueue(topgunMaverick,trash);
				
			}
			if (!tempGun.isEmpty()) {
				tempGun.dequeue(topgunMaverick, trash);
				//int newpri = (*temppointer->getHealth() * temppointer->getPower());
				human->getEG_List().enqueue(topgunMaverick,trash);
			}
			
		}

		else if (A > 30 && A < 40) {
			for (int j = 0;j < 5;j++) {
				if (aliens->getAS_List().dequeue(alientop))
				{
					alientop->setHealth(*alientop->getHealth() - 1);
					templist.enqueue(alientop);
					ArmyUnit* au = alientop;
					templist.dequeue(au);
					alientop =(AlienSoldier*) au;
					aliens->getAS_List().enqueue(alientop);
				}
			}
		}
		else if (A > 40 && A < 50) {
			for (int k = 0; k < 5;k++) {

				if (aliens->getAM_List().remove(monstertop))
					aliens->getAM_List().add(monstertop);
			}
		}
		else if (A > 50 && A < 60) {
			for (int z = 0;z <3 ;z++) {
				if(aliens->getAD_List().dequeueRear(dronerear))
					killedlist.enqueue(dronerear);

			}
			for (int m = 0;m < 3;m++) {
				if(aliens->getAD_List().dequeue(dronetop))
					killedlist.enqueue(dronetop);
			}
		}
		human->print();
		aliens->print();
		printDeadList();
		time++;
	}
}


