#pragma once
#include"Input.h"
#include"Generator.h"
#include"EarthArmy.h"
#include"AlienArmy.h"
//#include<iostream>
using namespace std;

class GameRules
{
private:
	EarthArmy* myEarth;
	AlienArmy* myAlien;
	Input* myI;
	bool Victory=false;
	string Winner;
	int timeStep=1;
	LinkedQueue<ArmyUnit*> killedlist;

public:
	GameRules();
	void War();
	int gettimeStep();
	LinkedQueue<ArmyUnit*>& getkilledlist();
	//void test();
	int getDeadCount();
	void printDeadList();
};