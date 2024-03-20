#pragma once
#include <string>
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


public:
    // Constructor
    ArmyUnit(int id, const string& unitType, int jointime, int hp, int pow, int attackcap);

    // Member functions
    int getID() const;
    string getType() const;
    int getJoinTime() const;
    int getHealth() const;
    int getPower() const;
    int getAttackCapacity() const;
    virtual void Attack()=0;


};
