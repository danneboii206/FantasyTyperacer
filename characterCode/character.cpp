//
// Created by rasmu on 2025-02-10.
//

#include "character.h"


Character::Character(const float maxHealth):maxHealth(maxHealth)
{
    health = maxHealth;
}
Character::Character():maxHealth(40)
{
    health = maxHealth;
}
void Character::takeDamage(const float damage)
{
    health -= damage;
}
void Character::setHealth(const float health)
{
    this->health = health;
}
void Character::setMaxHealth(const float health)
{
    this->maxHealth = health;
}
float Character::getHealth() const
{
    return health;
}
float Character::getMaxHealth() const
{
    return maxHealth;
}


