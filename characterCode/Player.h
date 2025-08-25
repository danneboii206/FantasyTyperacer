//
// Created by rasmu on 2025-08-24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"
#include <fstream>
class Player : public Character
{
private:
    std::string filepath = "../data";
    //int itemCount
    //int inventorySize = 10
    //Item *items = new Item[inventorySize]

public:
    Player();
    void savePlayerData();
    void loadPlayerData();
    void resetPlayerData();
    virtual ~Player();
};
#endif //PLAYER_H
