#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H

#include "item.h"
#include <string>

class Equippable : public item
{
private:
  bool isEquipped;
  std::string type;
public:
  Equippable() = delete;
  Equippable(std::string itemName, std::string description, double wpmBoost,
    double accBoost, double hpBoost, std::string type);
  ~Equippable() override;
  std::string getType() const;
  bool getIsEquipped() const;
  void setIsEquipped(bool isEquipped);
};



#endif //EQUIPPABLE_H
