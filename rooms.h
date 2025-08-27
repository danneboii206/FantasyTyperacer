#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <vector>
#include <memory>
#include "./items/item.h"

class Rooms {
private:
  int itemCount = 0;
  std::vector<std::shared_ptr<item>> allItems;
  std::vector<std::shared_ptr<item>> roomItems;
  bool hasEnemy = false;
  std::string description;
  void generateRoom();
  std::string descriptionSelector();
public:
  Rooms();
  ~Rooms();
  bool getHasEnemy();
  std::string getDescription();
  int getItemCount();
  std::shared_ptr<item> getItemAtIndex(int index);
};



#endif //ROOMS_H
