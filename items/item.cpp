//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "item.h"

item::item(std::string itemName, std::string description, double wpmBoost, double accuracyBoost, double hpBoost)
    : itemName(itemName), descripton(descripton), wpmBoost(wpmBoost), accuracyBoost(accuracyBoost), hpBoost(hpBoost)
{
}

std::string item::getDescription() const
{
    return this->descripton;
}

std::string item::getName() const
{
    return this->itemName;
}

double item::getWpmBoost() const
{
    return this->wpmBoost;
}

double item::getAccuracyBoost() const
{
    return this->accuracyBoost;
}

double item::getHpBoost() const
{
    return this->hpBoost;
}
