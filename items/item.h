#ifndef ITEM_H
#define ITEM_H

#include <string>

enum wpmMod
{
  NO_WPM_BOOST = 0,
  LOW_WPM_BOOST = 5,
  MEDIUM_WPM_BOOST = 10,
  HIGH_WPM_BOOST = 20,
  MAX_WPM_BOOST = 40
};

enum accBoost
{
  NO_ACC_BOOST = 0,
  LOW_ACC_BOOST = 5,
  MEDIUM_ACC_BOOST = 10,
  HIGH_ACC_BOOST = 15,
  MAX_ACC_BOOST = 20
};

enum healthBoost
{
  NO_HP_BOOST = 0,
  LOW_HP_BOOST = 50,
  MEDIUM_HP_BOOST = 75,
  HIGH_HP_BOOST = 150,
  MAX_HP_BOOST = 220
};

class item
{
private:
  std::string itemName;
  std::string description;
  double wpmBoost; //flat wpm adder
  double accBoost; //flat accuracy boost
  double hpBoost; //flat hp bonus
public:
  item() = delete; //no default constructor, only with args
  item(std::string itemName, std::string description, double wpmBoost,
    double accBoost, double hpBoost);
  virtual ~item();
  std::string getDescription() const;
  std::string getName() const;
  virtual std::string getType() const = 0;
  double getWpmBoost() const;
  double getAccuracyBoost() const;
  double getHpBoost() const;
};



#endif //ITEM_H
