//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "item.h"

item::item(std::string itemName, double wpmBoost, double accuracyBoost)
    : itemName(itemName), wpmBoost(wpmBoost), accuracyBoost(accuracyBoost)
{
}

std::string item::getName()
{
    return this->itemName;
}

double item::getWpmBoost()
{
    return this->wpmBoost;
}

double item::getAccuracyBoost()
{
    return this->accuracyBoost;
}
