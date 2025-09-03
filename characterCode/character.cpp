#include "character.h"

Character::Character(const double maxHealth)
    : health(maxHealth), maxHealth(maxHealth)
{
}

Character::~Character()
{
}

void Character::takeDamage(const double damage)
{
    health -= damage;
}
void Character::setHealth(const double health)
{
    this->health = health;
}
void Character::setMaxHealth(const double maxHealth)
{
    this->maxHealth = maxHealth;
}
double Character::getHealth() const
{
    return health;
}
double Character::getMaxHealth() const
{
    return maxHealth;
}


