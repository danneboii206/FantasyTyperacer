#include "item.h"

item::item(std::string itemName, std::string description,
      double wpmBoost, double accBoost, double hpBoost, std::string type)
    : itemName(itemName), description(description), wpmBoost(wpmBoost),
      accBoost(accBoost), hpBoost(hpBoost), type(type)
{
}

item::~item()
{
}

std::string item::getDescription() const
{
    return this->description;
}

std::string item::getName() const
{
    return this->itemName;
}

std::string item::getType() const
{
    return this->type;
}

double item::getWpmBoost() const
{
    return this->wpmBoost;
}

double item::getAccuracyBoost() const
{
    return this->accBoost;
}

double item::getHpBoost() const
{
    return this->hpBoost;
}
