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
		//cout<<(*temppointer->getHealth() * temppointer->getPower());
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



