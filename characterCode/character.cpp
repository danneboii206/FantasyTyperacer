//
// Created by rasmu on 2025-02-10.
//

#include "character.h"


Character::Character(const double maxHealth):maxHealth(maxHealth)
{
    health = maxHealth;
}
Character::Character():maxHealth(40)
{
    health = maxHealth;
}
void Character::takeDamage(const double damage)
{
    health -= damage;
}
void Character::setHealth(const double health)
{
    this->health = health;
}
void Character::setMaxHealth(const double health)
{
    this->maxHealth = health;
}
double Character::getHealth() const
{
    return health;
}
double Character::getMaxHealth() const
{
    return maxHealth;
}


