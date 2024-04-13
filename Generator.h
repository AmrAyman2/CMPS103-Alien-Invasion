#pragma once
#include"Input.h"
#include"EarthArmy.h"
#include"AlienArmy.h"
class GameRules;

class Generator
{
private:
	Input* I1;
	EarthArmy* E1;
	AlienArmy* A1;
	GameRules* G1;
public:
	Generator();
	Generator(Input&, EarthArmy&, AlienArmy&, GameRules&);
	void generateEarth();
	void generateAlien();
};