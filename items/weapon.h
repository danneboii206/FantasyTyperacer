//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "item.h"

class weapon : public item
{
private:
    std::string type = "weapon";
public:
    weapon() = delete;
    weapon(std::string itemName, std::string description, double wpmBoost, double accuracyBoost, double hpBoost);
};



#endif //WEAPON_H
