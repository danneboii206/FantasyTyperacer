//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class item
{
private:
  std::string itemName;
  std::string description;
  double wpmBoost; //flat wpm adder
  double accuracyBoost; //flat accuracy boost
  double hpBoost; //flat hp bonus
  std::string type;
public:
  item() = delete; //no default constructor, only with args
  item(std::string itemName, std::string description, double wpmBoost,
    double accuracyBoost, double hpBoost, std::string type);
  virtual ~item();
  std::string getDescription() const;
  std::string getName() const;
  std::string getType() const;
  double getWpmBoost() const;
  double getAccuracyBoost() const;
  double getHpBoost() const;
};



#endif //ITEM_H
