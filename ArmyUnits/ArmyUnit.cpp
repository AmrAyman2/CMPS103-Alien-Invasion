#include "ArmyUnit.h"
ArmyUnit::ArmyUnit(int id, const string& unitType, int tj, int hp, int pow, int attackCap)
    : ID(id),
    type(unitType),
    TJ(tj),
    health(hp),
    power(pow),
    attackCapacity(attackCap)
{}

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

int ArmyUnit::getHealth() const {
    return health;
}

int ArmyUnit::getPower() const {
    return power;
}

int ArmyUnit::getAttackCapacity() const {
    return attackCapacity;
}