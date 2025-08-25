//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <string>

class consumable : public item
{
private:
    std::string type = "consumable";
    int duration; //how many enemy rounds
public:
    consumable() = delete;
    consumable(std::string itemName, std::string description, double wpmBoost,
        double accuracyBoost, double hpBoost, int duration);
    void roundOver();
    int getDuration();
};



#endif //CONSUMABLE_H
