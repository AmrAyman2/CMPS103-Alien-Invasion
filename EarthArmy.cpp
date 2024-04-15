#include "EarthArmy.h"
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



/////////////phase 2///////////
//void EarthArmy::Attack(AlienArmy* alien)
//{
//	LinkedQueue <EarthSoldier*> temp = ES_List;
//	EarthSoldier* soldier;
//	while (!temp.isEmpty()) {
//		temp.dequeue(soldier);
//		soldier->Attack(alien);
//	}
//}

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
		if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
		cout << temppointer->getID() << ",";
	}
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
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";
	}
}

int EarthArmy::EG_Count()
{
	priQueue<EarthGunnery*> temp(EG_List);
	int EGcount = 0;
	int trash = 0;
	EarthGunnery* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer,trash);
		EGcount++;
	}
	return EGcount;
}

void EarthArmy::EG_PrintID()
{
	priQueue<EarthGunnery*> temp(EG_List);
	EarthGunnery* temppointer;
	int trash = 0;
	cout << EG_Count() << " EG " << "[";
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer,trash);
		if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";
	}
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

void EarthArmy::getES_List(LinkedQueue<EarthSoldier*>& list)
{
	list = ES_List;
}

void EarthArmy::getET_List(ArrayStack<EarthTank*>& list)
{
	list = ET_List;
}

void EarthArmy::getEG_List(priQueue<EarthGunnery*>& list)
{
	list = EG_List;
}


