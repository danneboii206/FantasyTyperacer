//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include <string>

class armor : public item
{
public:
    armor() = delete;
    armor(std::string itemName, std::string description, double wpmBoost,
          double accBoost, double hpBoost, std::string type = "armor" );
    ~armor() override;
};



#endif //ARMOR_H
