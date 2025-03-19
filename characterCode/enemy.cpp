//
// Created by rasmu on 2025-02-21.
//

#include "Enemy.h"
#include <iostream>


Enemy::Enemy(float damage, float maxHealth)
  :damage(damage), Character(maxHealth)
{
}
Enemy::Enemy(): damage(10)
{
}

void Enemy::setName(std::string name)
{
  this->name = name;
}
void Enemy::setDescription(std::string description)
{
	this->description = description;
}
void Enemy::setArt(std::string art)
{
	this->art = art;
}
void Enemy::setDamage(float damage)
{
  this->damage = damage;
}

std::string Enemy::getName()
{
	return name;
}
std::string Enemy::getDescription()
{
  return description;
}
std::string Enemy::getArt()
{
  return art;
}

int Enemy::getDamage() const
{
  return damage;
}
