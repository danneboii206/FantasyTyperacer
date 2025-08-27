#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "item.h"

class weapon : public item
{
private:
    bool isEquipped;
public:
    weapon() = delete;
    weapon(std::string itemName, std::string description,
        double wpmBoost, double accBoost, double hpBoost, std::string type = "weapon");
    ~weapon() override;
    bool getIsEquipped() const;
    void setIsEquipped(bool isEquipped);
};



#endif //WEAPON_H
