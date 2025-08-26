//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "consumable.h"

consumable::consumable(std::string itemName, std::string description, double wpmBoost, double accuracyBoost,
    double hpBoost, int duration, std::string type)
        : item(itemName, description, wpmBoost, accuracyBoost, hpBoost, type), duration(duration)
{
}

consumable::~consumable()
{
}

void consumable::roundOver()
{
    --this->duration;
}

int consumable::getDuration() const
{
    return this->duration;
}
