//
// Created by rasmu on 2025-08-24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <fstream>
#include "../item.h"
class Player : public Character
{
private:
    std::string filepath = "../data";
    int itemCount;
    int inventorySize = 10;
    item **items = new item*[inventorySize];

public:
    Player();
    void savePlayerData();
    void loadPlayerData();
    void resetPlayerData();
    virtual ~Player();
};
#endif //PLAYER_H
