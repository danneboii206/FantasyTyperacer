//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "weapon.h"

weapon::weapon(std::string itemName, std::string description, double wpmBoost, double accuracyBoost, double hpBoost)
    : item(itemName, description, wpmBoost, accuracyBoost, hpBoost)
{
}
