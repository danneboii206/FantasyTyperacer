#include "consumable.h"

consumable::consumable(std::string itemName, std::string description, double wpmBoost, double accBoost,
    double hpBoost, int duration, double instantHeal)
        : item(itemName, description, wpmBoost, accBoost, hpBoost),
          duration(duration), instantHeal(instantHeal)
{
}

consumable::~consumable()
{
}

std::string consumable::getType() const
{
    return "consumable";
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
