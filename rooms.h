#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "./items/item.h"
#include <vector>
#include "./items/allItems.h"
class Rooms {
private:

  int itemCount = 0;
  int individualItems = 16; //represents number of items in itemList
  item **itemList = new item*[individualItems]
  {new shinyStone(), new shinyStone(), new shinyStone(), new shinyStone(),
    new accPotion(), new accPotion(), new accPotion(),
    new hpPotion(), new hpPotion(), new hpPotion(),
    new rasmusStick(), new rasmusStick(),
    new bigHpPotion(), new divineSword(), new dragonArmor(), new dungeonMastersSpear()};
  item **items;
  bool hasEnemy = false;
  std::string description;
  void generateRoom();
  std::string descriptionSelector();
public:

  Rooms();
  ~Rooms();

};



#endif //ROOMS_H
