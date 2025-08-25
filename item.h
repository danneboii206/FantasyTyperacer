//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class item {
private:
  std::string itemName;
  double wpmBoost;
  double accuracyBoost;
public:
  item(std::string itemName, double wpmBoost, double accuracyBoost);
  std::string getName();
  double getWpmBoost();
  double getAccuracyBoost();
};



#endif //ITEM_H
