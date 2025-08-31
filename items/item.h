#ifndef ITEM_H
#define ITEM_H
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <fstream>


class item
{
protected:
  std::string itemName;
  std::string description;
  double wpmBoost; //flat wpm adder
  double accBoost; //flat accuracy boost
  double hpBoost; //flat hp bonus
public:
  item();
  item(std::string itemName, std::string description, std::string  wpmBoost,
    std::string  accBoost, std::string  hpBoost);
  virtual ~item();
  virtual void getDataFromName(std::string name) = 0;
  int strToWpm(const std::string& str);
  int strToAcc(const std::string& str);
  int strToHp(const std::string& str);
  std::string getDescription() const;
  std::string getName() const;
  virtual std::string getType() const = 0;
  double getWpmBoost() const;
  double getAccuracyBoost() const;
  double getHpBoost() const;
};



#endif //ITEM_H
