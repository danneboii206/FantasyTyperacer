#include "Equippable.h"

Equippable::Equippable(std::string itemName, std::string description, double wpmBoost, double accBoost, double hpBoost,
    std::string type)
        : item(itemName, description, wpmBoost, accBoost, hpBoost), type(type), isEquipped(false)
{
}

Equippable::~Equippable()
{
}

std::string Equippable::getType() const
{
    return this->type;
}

bool Equippable::getIsEquipped() const
{
    return this->isEquipped;
}

void Equippable::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}
