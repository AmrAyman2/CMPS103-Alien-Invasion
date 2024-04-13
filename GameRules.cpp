#include "GameRules.h"

// Kamel ya bro @Ahmed Farouk
void GameRules::printDeadList() {

}
void GameRules::War() {
	Input I1;           
	EarthArmy Earth;    
	AlienArmy Aliens;   
	Generator generate(I1,Earth,Aliens,*this);
	while (timeStep <= 40)
	{
		generate.generateEarth();
		generate.generateAlien();
		//Attack Logic
		//Earth.printArmy();
		//Alien.printArmy();
		//printDeadlist();
		timeStep++;
	}
	if (timeStep > 40)
	{
		while (!Victory)
		{
			generate.generateEarth();
			generate.generateAlien();
			//Attack Logic
			//Earth.printArmy()
			//Alien.printArmy()
			//printDeadList()
			if (Earth.getTotalCount() > 0 && Alien.getTotalCount() == 0)
			{
				Winner = "Earth Army";
				Victory = true;
			}
			else if (Alien.getTotalCount() > 0 && Earth.getTotalCount() == 0)
			{
				Winner = "Alien Army";
				Victory = true;
			}
			timeStep++;
		}
	}
}

int GameRules::gettimeStep() {
	return timeStep;
}

// Kamel ya bro @Ahmed Farouk
void GameRules::test() {
	for (int i = 0; i < 50; i++)
	{
		
		timeStep++;
	}
}