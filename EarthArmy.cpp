#include "EarthArmy.h"
#include "AlienArmy.h"
#include "GameRules.h"

bool EarthArmy::AddUnit(EarthSoldier* unit)
{
	return ES_List.enqueue(unit);
}

bool EarthArmy::AddUnit(EarthTank* unit)
{
	return ET_List.push(unit);
}

bool EarthArmy::AddUnit(EarthGunnery* unit)
{
	int highestcombo = (*unit->getHealth() * unit->getPower()); //highest product of health and power of unit is best
	return EG_List.enqueue(unit, highestcombo);
}

int EarthArmy::ES_Count()
{
	LinkedQueue<EarthSoldier*> temp(ES_List);
	int EScount = 0;
	EarthSoldier* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		EScount++;
	}
	return EScount;
}

void EarthArmy::ES_PrintID()
{
	LinkedQueue<EarthSoldier*> temp(ES_List);
	EarthSoldier* temppointer;
	cout << ES_Count() << " ES " << "[";
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		if (temp.isEmpty()) {
			cout << temppointer->getID() << "]" << endl;
			return;
		}
		else
			cout << temppointer->getID() << ", ";
	}
	cout << "]" << endl;
}

int EarthArmy::ET_Count()
{
	ArrayStack<EarthTank*> temp(ET_List);
	int ETcount = 0;
	EarthTank* temppointer;
	while (!temp.isEmpty()) {
		temp.pop(temppointer);
		ETcount++;
	}
	return ETcount;
}

void EarthArmy::ET_PrintID()
{
	ArrayStack<EarthTank*> temp(ET_List);
	EarthTank* temppointer;
	cout << ET_Count() << " ET " << "[";
	while (!temp.isEmpty()) {
		temp.pop(temppointer);
		if (temp.isEmpty())
		{
			cout << temppointer->getID() << "]" << endl;
			return;
		}
		else
			cout << temppointer->getID() << ", ";
	}
	cout << "]" << endl;
}

int EarthArmy::EG_Count()
{
	priQueue<EarthGunnery*> temp;
	int EGcount = 0;
	int trash = 0;
	EarthGunnery* temppointer;
	while (!EG_List.isEmpty()) {
		EG_List.dequeue(temppointer, trash);
		temp.enqueue(temppointer,trash);
		EGcount++;
	}
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer, trash);
		EG_List.enqueue(temppointer, trash);
	}
	return EGcount;
}

void EarthArmy::EG_PrintID()
{
	priQueue<EarthGunnery*> temp;
	EarthGunnery* temppointer;
	int trash = 0;
	cout << EG_Count() << " EG " << "[";
	while (!EG_List.isEmpty()) {
		EG_List.dequeue(temppointer, trash);
		temp.enqueue(temppointer, trash);
		if (EG_List.isEmpty())
		{
			cout << temppointer->getID() << "]" << endl;
			while (!temp.isEmpty()) {
				temp.dequeue(temppointer, trash);
				EG_List.enqueue(temppointer, trash);
			}
			return;
		}
		else
		cout<<temppointer->getID()<<", ";
	}
	cout << "]" << endl;
}

int EarthArmy::getTotalCount()
{
	return (ES_Count() + ET_Count() + EG_Count());
}

void EarthArmy::print()
{
	cout << "============== Earth Army Alive Units ==============" << endl;
	ES_PrintID();
	ET_PrintID();
	EG_PrintID();
}

void EarthArmy::Attack(GameRules* game,AlienArmy* alien)
{
	EarthSoldier* earthsold;
	EarthGunnery* earthgunnery;
	EarthTank* earthtank;
	for (int i = 0; i < ES_Count(); i++) {
		ES_List.dequeue(earthsold);
		earthsold->Attack(game,alien);
		ES_List.enqueue(earthsold);
	}
	/*for (int i = 0; i < EG_Count(); i++) {
		EG_List.dequeue(earthgunnery);
		earthgunnery->Attack(game, alien);
		EG_List.enqueue(earthgunnery);
	}
	for (int i = 0; i < ET_Count(); i++) {
		ET_List.pop(earthtank);
		earthtank->Attack(game, alien);
		ET_List.push(earthtank);
	}*/
}

LinkedQueue<EarthSoldier*>& EarthArmy::getES_List()
{
	return ES_List;
}

ArrayStack<EarthTank*>& EarthArmy::getET_List()
{
	return ET_List;
}

priQueue<EarthGunnery*>& EarthArmy::getEG_List()
{
	return EG_List;
}