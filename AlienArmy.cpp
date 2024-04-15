#include "AlienArmy.h"
bool AlienArmy::AddUnit(AlienSoldier* unit) 
{
	return AS_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienDrone* unit)
{
	return AD_List.enqueue(unit);
}

bool AlienArmy::AddUnit(AlienMonster* unit)
{
	return AM_List.add(unit);
}

//void AlienArmy::Attack(EarthArmy* earth)
//{
//	LinkedQueue <AlienSoldier*> temp = AS_List;
//	AlienSoldier* soldier;
//	while (!temp.isEmpty()) {
//		temp.dequeue(soldier);
//		soldier->Attack(earth);
//	}
//
//	Deque <AlienDrone*> temp2 = AD_List;
//	AlienDrone* drone1;
//	AlienDrone* drone2;
//	while (!temp.isEmpty() && temp2.dequeue(drone1) && temp2.dequeueRear(drone2))
//	{
//		temp2.dequeue(drone1);
//		drone1->Attack(earth);
//		temp2.dequeueRear(drone2);
//		drone2->Attack(earth);
//	}
//
//	ArrayBag<AlienMonster*> temp3 = AM_List;
//	//using random generator which is yet to be done
//}

int AlienArmy::AS_Count()
{
	LinkedQueue<AlienSoldier*> temp(AS_List);
	int AScount = 0;
	AlienSoldier* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		AScount++;
	}
	return AScount;
}

void AlienArmy::AS_PrintID()
{
	LinkedQueue<AlienSoldier*> temp(AS_List);
	AlienSoldier* temppointer;
	cout << AS_Count() << " AS " << "[";
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";
	}
}

int AlienArmy::AD_Count()
{
	Deque<AlienDrone*> temp(AD_List);
	int ADcount = 0;
	AlienDrone* temppointer;
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		ADcount++;
	}
	return ADcount;
}

void AlienArmy::AD_PrintID()
{
	Deque<AlienDrone*> temp(AD_List);
	AlienDrone* temppointer;
	cout << AD_Count() << " AD " << "[";
	while (!temp.isEmpty()) {
		temp.dequeue(temppointer);
		if (temp.isEmpty())
			cout << temppointer->getID() << "]" << endl;
		else
			cout << temppointer->getID() << ",";
	}
}

int AlienArmy::AM_Count()
{
	return AM_List.getCurrentSize();
}

void AlienArmy::AM_PrintID()
{
	cout << AM_Count() << " AM ";
	AM_List.print();
}

int AlienArmy::getTotalCount()
{
	return (AS_Count() + AD_Count() + AM_Count());
}

void AlienArmy::print()
{
	cout << "============== Alien Army Alive Units ==============" << endl;
	AS_PrintID();
	AD_PrintID();
	AM_PrintID();
}

void AlienArmy::getAS_List(LinkedQueue<AlienSoldier*>& list)
{
	list = AS_List;
}

void AlienArmy::getAD_List(Deque<AlienDrone*>& list)
{
	list = AD_List;
}

void AlienArmy::getAM_List(ArrayBag<AlienMonster*>& list)
{
	list = AM_List;
}



