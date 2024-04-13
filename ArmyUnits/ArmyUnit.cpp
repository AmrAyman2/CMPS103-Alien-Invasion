#include "ArmyUnit.h"
ArmyUnit::ArmyUnit(int id, const string& unitType, int tj, int hp, int pow, int attackCap)
    : ID(id),
    type(unitType),
    TJ(tj),
    health(hp),
    power(pow),
    attackCapacity(attackCap)
{
    troopCount++;
}

// Member function implementations
int ArmyUnit::getID() const {
    return ID;
}

string ArmyUnit::getType() const {
    return type;
}

int ArmyUnit::getJoinTime() const {
    return TJ;
}

int* ArmyUnit::getHealth(){
    return &health;
}

int ArmyUnit::getPower() const {
    return power;
}

int ArmyUnit::getAttackCapacity() const {
    return attackCapacity;
}

void ArmyUnit::setID(int id) {
    ID = id;
}

void ArmyUnit::setHealth(int h) {
    health = h;
}

void ArmyUnit::setAttackCapacity(int a) {
    attackCapacity = a;
}

void ArmyUnit::setPower(int p) {
    power = p;
}

void ArmyUnit::printID()
{
    cout << ID << endl;
}

int ArmyUnit::getTroopCount() {
    return troopCount;
}