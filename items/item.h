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
  std::string descripton;
  double wpmBoost; //flat wpm adder
  double accuracyBoost; //flat accuracy boost
  double hpBoost; //flat hp bonus
public:
  item() = delete; //no default constructor, only with args
  item(std::string itemName, std::string description, double wpmBoost, double accuracyBoost, double hpBoost);
  std::string getDescription() const;
  std::string getName() const;
  double getWpmBoost() const;
  double getAccuracyBoost() const;
  double getHpBoost() const;
};



#endif //ITEM_H
