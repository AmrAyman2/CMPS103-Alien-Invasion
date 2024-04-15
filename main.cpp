#include <iostream>
//#include "ArmyUnits/Alien/AlienSoldier.h"
//#include "AlienArmy.h"
#include "GameRules.h"
//#include "Input.h"
//#include "Generator.h"
//#include "EarthArmy.h"
//#include "ArmyUnits/ArmyUnit.h"
using namespace std;
//
//int main() {
//	Input* input = new Input();
//	AlienArmy* aliens = new AlienArmy;
//	EarthArmy* human = new EarthArmy;
//	GameRules* game = new GameRules;
//	Generator* generator = new Generator(*input, *human, *aliens, *game);
//	EarthSoldier* earthtop;
//	EarthTank* tanktop;
//	EarthGunnery* topgun;
//	int pri;
//	AlienSoldier* alientop;
//	AlienMonster* monstertop;
//	AlienDrone* dronetop;
//	AlienDrone* dronerear;
//
//	int time = game->gettimeStep();
//
//
//	for (int i = 0;i < 50;i++) {
//		generator->generateEarth();
//		generator->generateAlien();
//		int A = (rand() % (100 - 1 + 1)) + 1;
//		if (A > 0 && A < 10) {
//			human->ES_List.dequeue(earthtop);
//			human->ES_List.enqueue(earthtop);
//
//		}
//		else if (A > 10 && A < 20) {
//			human->ET_List.pop(tanktop);
//
//
//		}
//		else if (A > 20 && A < 30) {
//			human->EG_List.dequeue(topgun,pri);
//			
//		}
//		else if (A > 30 && A < 40) {
//			for (int j = 0;j < 5;j++) {
//				aliens->AS_List.dequeue(alientop);
//			}
//		}
//		else if (A > 40 && A < 50) {
//			for (int k = 0; k < 5;k++) {
//
//				aliens->AM_List.remove(monstertop);
//			}
//		}
//		else if (A > 50 && A < 60) {
//			for (int z = 0;z < 6;z++) {
//				aliens->AD_List.dequeueRear(dronerear);
//				
//			}
//			for (int m = 0;m < 6;m++) {
//				aliens->AD_List.dequeue(dronetop);
//
//			}
//		}
//
//		time++;
//	}
//
//
//
//
//	/*int N = input->getN();
//	int ES = input->getES();
//	int EG = input->getEG();
//	int ET = input->getET();
//	int AS = input->getAS();
//	int AM = input->getAM();
//	int AD = input->getAD();
//	int prob = input->getProb();*/
//	/*int EarthID = 0;
//	int AlienID = 2000;
//	AlienSoldier* a1= new AlienSoldier(AlienID++, 5, 100, 5, 2);
//	AlienSoldier* a2= new AlienSoldier(AlienID++, 5, 100, 5, 2);
//	AlienSoldier* a3= new AlienSoldier(AlienID++, 5, 100, 5, 2);
//	EarthSoldier* b1 = new EarthSoldier(EarthID++, 5, 100, 500, 3);
//	EarthArmy* Earth = new EarthArmy();
//	AlienArmy* Alien = new AlienArmy();
//	Alien->AddUnit(a1);
//	Alien->AddUnit(a2);
//	Alien->AddUnit(a3);
//	Earth->AddUnit(b1);
//	b1->Attack(Alien);
//	int* hp = a3->getHealth();
//	cout<<*hp<<endl;
//}*/
//}

int main()
{

	GameRules G1;
	G1.test();
	//G1.War();

	return 0;
}