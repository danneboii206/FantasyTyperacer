#include "weapon.h"

weapon::weapon(std::string itemName, std::string description,
              double wpmBoost, double accBoost, double hpBoost, std::string type)
    : item(itemName, description, wpmBoost, accBoost, hpBoost, type), isEquipped(false)
{
}

weapon::~weapon()
{
}

bool weapon::getIsEquipped() const
{
    return this->isEquipped;
}

void weapon::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}
