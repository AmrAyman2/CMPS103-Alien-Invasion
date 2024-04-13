#pragma once
#include"Input.h"
#include"EarthArmy.h"
#include"AlienArmy.h"

class Generator
{
private:
	Input* I1;
	EarthArmy* E1;
	AlienArmy* A1;

public:
	Generator(Input&, EarthArmy&, AlienArmy&);
	void generateEarth();
	void generateAlien();
}