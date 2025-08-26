//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "armor.h"

armor::armor(std::string itemName, std::string description,
    double wpmBoost, double accBoost, double hpBoost, std::string type)
    : item(itemName, description, wpmBoost, accBoost, hpBoost, type)
{
}

armor::~armor()
{
}
