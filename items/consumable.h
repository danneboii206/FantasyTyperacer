//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <string>

class consumable : public item
{
    int duration; //how many enemy rounds
public:
    consumable() = delete;
    consumable(std::string itemName, std::string description, double wpmBoost,
        double accuracyBoost, double hpBoost, int duration, std::string type = "consumable");
    ~consumable() override;
    void roundOver();
    int getDuration() const;
};



#endif //CONSUMABLE_H
