//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "consumable.h"

consumable::consumable(std::string itemName, std::string description, double wpmBoost, double accBoost,
    double hpBoost, int duration, double instantHeal, std::string type)
        : item(itemName, description, wpmBoost, accBoost, hpBoost, type),
          duration(duration), instantHeal(instantHeal)
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

double consumable::getInstantHeal() const
{
    return this->instantHeal;
}
