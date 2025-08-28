#include "Enemy.h"
#include <iostream>

Enemy::Enemy(double damage, double maxHealth, std::string name)
  : damage(damage), Character(maxHealth), name(name)
{
}

Enemy::~Enemy()
{
}

void Enemy::setName(std::string name)
{
  this->name = name;
}
void Enemy::setDescriptionPath(std::string descriptionPath)
{
	this->descriptionPath = descriptionPath;
}
void Enemy::setArtPath(std::string artPath)
{
	this->artPath = artPath;
}
void Enemy::setDamage(double damage)
{
  this->damage = damage;
}


std::string Enemy::getName()
{
	return name;
}
std::string Enemy::getDescriptionPath()
{
  return descriptionPath;
}
std::string Enemy::getArtPath()
{
  return artPath;
}

double Enemy::getDamage() const
{
  return damage;
}
