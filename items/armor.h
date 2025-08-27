#ifndef ARMOR_H
#define ARMOR_H

#include "item.h"
#include <string>

class armor : public item
{
private:
    bool isEquipped;
public:
    armor() = delete;
    armor(std::string itemName, std::string description, double wpmBoost,
          double accBoost, double hpBoost, std::string type = "armor" );
    ~armor() override;
    bool getIsEquipped() const;
    void setIsEquipped(bool isEquipped);
};



#endif //ARMOR_H
