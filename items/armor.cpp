#include "armor.h"

armor::armor(std::string itemName, std::string description,
    double wpmBoost, double accBoost, double hpBoost)
    : item(itemName, description, wpmBoost, accBoost, hpBoost), isEquipped(false)
{
}

armor::~armor()
{
}

std::string armor::getType() const
{
    return "armor";
}

bool armor::getIsEquipped() const
{
    return this->isEquipped;
}

void armor::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}
