#include "GameRules.h"
//#include <iostream>
//#include "ArmyUnits/Alien/AlienSoldier.h"
//#include "AlienArmy.h"
//#include "GameRules.h"
//#include "Input.h"
#include "Generator.h"
//#include "EarthArmy.h"
//#include "ArmyUnits/ArmyUnit.h"
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
		if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";
	}
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

int GameRules::gettimeStep() {
	return timeStep;
}

void GameRules::getkilledlist(LinkedQueue<ArmyUnit*>& ripkilled)
{
	ripkilled = killedlist;
}

// Kamel ya bro @Ahmed Farouk
void GameRules::test() {
	Input* input = new Input();
	AlienArmy* aliens = new AlienArmy;
	EarthArmy* human = new EarthArmy;
	Generator* generator = new Generator(*input, *human, *aliens, *this);
	EarthSoldier* earthtop;
	EarthTank* tanktop;
	EarthGunnery* topgun;
	int pri;
	int trash=0;
	AlienSoldier* alientop;
	AlienMonster* monstertop;
	AlienDrone* dronetop;
	AlienDrone* dronerear;
	LinkedQueue<ArmyUnit*> killedlist;
	int time = gettimeStep();
	//LinkedQueue<ArmyUnit*> killedlist;
	LinkedQueue<ArmyUnit*> templist;

	LinkedQueue<EarthSoldier*> es_List;
	ArrayStack<EarthTank*> et_List;
	priQueue<EarthGunnery*> eg_List;
	LinkedQueue<AlienSoldier*> as_List;
	Deque<AlienDrone*> ad_List;
	ArrayBag<AlienMonster*> am_List;



	for (int i = 0;i < 50;i++) {
		generator->generateEarth();
		generator->generateAlien();
		int A = (rand() % (100)) + 1;
		if (A > 0 && A < 10) {
			human->ES_List.dequeue(earthtop);
			human->ES_List.enqueue(earthtop);

		}

		else if (A > 10 && A < 20) {
			human->getET_List(et_List);
			et_List.pop(tanktop);
			getkilledlist(killedlist);
			killedlist.enqueue(tanktop);
		}

		else if (A > 20 && A < 30) {
			human->EG_List.dequeue(topgun, pri);
			topgun->setHealth((*topgun->getHealth()) / 2);
			human->EG_List.enqueue(topgun, trash);
		}
		else if (A > 30 && A < 40) {
			for (int j = 0;j < 5;j++) {
				aliens->getAS_List(as_List);
				as_List.dequeue(alientop);
				alientop->setHealth(*alientop->getHealth()-1);
				templist.enqueue(alientop);
			}
		}

		else if (A > 40 && A < 50) {
			for (int k = 0; k < 5;k++) {
				aliens->getAM_List(am_List);
				am_List.remove(monstertop);
				aliens->getAM_List(am_List);
				am_List.add(monstertop);
			}
		}

		else if (A > 50 && A < 60) {
			for (int z = 0;z < 6;z++) {
				aliens->getAD_List(ad_List);
				ad_List.dequeueRear(dronerear);
				killedlist.enqueue(dronerear);

			}
			for (int m = 0;m < 6;m++) {
				aliens->getAD_List(ad_List);
				ad_List.dequeue(dronetop);
				aliens->AD_List().dequeue(dronetop);
				killedlist.enqueue(dronetop);
			}
		}

		human->print();
		aliens->print();
		printDeadList();
		human->print();
		aliens->print();
		printDeadList();
		time++;
	}
}


