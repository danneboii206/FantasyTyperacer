#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "./items/item.h"
#include <vector>
#include <memory>
#include "./items/allItems.h"
class Rooms {
private:

  int itemCount = 0;
  std::vector<std::shared_ptr<item>> allItems{
      std::make_shared<shinyStone>(), std::make_shared<shinyStone>(), std::make_shared<shinyStone>(), std::make_shared<shinyStone>(),
      std::make_shared<accPotion>(), std::make_shared<accPotion>(), std::make_shared<accPotion>(),
      std::make_shared<hpPotion>(), std::make_shared<hpPotion>(), std::make_shared<hpPotion>(),
      std::make_shared<rasmusStick>(), std::make_shared<rasmusStick>(),
      std::make_shared<bigHpPotion>(), std::make_shared<divineSword>(), std::make_shared<dragonArmor>(), std::make_shared<dungeonMastersSpear>()
    };
  std::vector<std::shared_ptr<item>> roomItems;
  bool hasEnemy = false;
  std::string description;
  void generateRoom();
  std::string descriptionSelector();
public:
  //item** getItems();
  bool getHasEnemy();
  std::string getDescription();

  Rooms();
  ~Rooms();

};



#endif //ROOMS_H
