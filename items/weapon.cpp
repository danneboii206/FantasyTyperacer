#include "weapon.h"

weapon::weapon(std::string itemName, std::string description,
              double wpmBoost, double accBoost, double hpBoost)
    : item(itemName, description, wpmBoost, accBoost, hpBoost), isEquipped(false)
{
}

weapon::~weapon()
{
}

std::string weapon::getType() const
{
    return "weapon";
}

bool weapon::getIsEquipped() const
{
    return this->isEquipped;
}

void weapon::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}
