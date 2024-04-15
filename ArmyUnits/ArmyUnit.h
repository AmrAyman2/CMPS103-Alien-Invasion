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
    ArmyUnit(int id = 0, string unitType ="", int jointime=0, int hp=0, int pow=0, int attackcap=0);
    // Member functions
    string getType() const;
    int getID() const;
    int getJoinTime() const;
    int* getHealth();
    int getPower() const;
    int getAttackCapacity() const;
    int getTroopCount();//used in setting ID in generator, counts the number of troops created from each type


    void setID(int);
    void setHealth(int);
    void setAttackCapacity(int);
    void setPower(int);
    void setJoinTime(int);
    void setTA(int);
    void setTD(int);
    void setDF(int);
    void setDd(int);
    void setBt(int);
    

    void printID();
    
};
