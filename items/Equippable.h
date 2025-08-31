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
  Equippable(std::string itemName);
  ~Equippable() override;
  void getDataFromName(std::string name) override;
  std::string getType() const;
  bool getIsEquipped() const;
  void setIsEquipped(bool isEquipped);
};



#endif //EQUIPPABLE_H
