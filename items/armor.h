//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include <string>

class armor : public item
{
private:
  std::string type = "armor";
public:
    armor() = delete;
    armor(std::string itemName, std::string description, double wpmBoost, double accuracyBoost, double hpBoost);
};



#endif //ARMOR_H
