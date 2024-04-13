#pragma once
#include <string>
#include <iostream>
using namespace std;

class ArmyUnit {
protected:
    int ID;
    string type;
    int TJ; // TJ: join time
    int health;
    int power;
    int attackCapacity; //maximum number of units that could be attacked by this unit at one timestep
    int Ta; //first attacked Time
    int Td; //Destruction Time
    int Df; //first attack delay
    int Dd; //Destruction delay
    int Bt; //batle time
    int troopCount=0; //needed for IDs in random generator


public:
    // Constructor
    ArmyUnit(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);

    // Member functions
    int getID() const;
    string getType() const;
    int getJoinTime() const;
    int* getHealth();
    int getPower() const;
    int getAttackCapacity() const;
    void setID(int);
    void setHealth(int);
    void setAttackCapacity(int);
    void setPower(int);
    void printID();
    int getTroopCount();

};
