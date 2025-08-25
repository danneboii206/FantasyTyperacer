#ifndef ROOMS_H
#define ROOMS_H

#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>

class Rooms {
private:
  int itemCount = 0;
  //Item *items = new Item[itemCount];
  bool hasEnemy = false;
  std::string description;
  void generateRoom();
  std::string descriptionSelector();
public:
  Rooms();

};



#endif //ROOMS_H
