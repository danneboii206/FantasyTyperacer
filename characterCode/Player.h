//
// Created by rasmu on 2025-08-24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../items/item.h"
#include "../items/consumable.h"
#include "../items/armor.h"
#include "../items/weapon.h"
#include <fstream>

const int inventorySize = 10;

class Player : public Character
{
private:
    std::string filepath = "../data";
    double accBoost;
    double wpmBoost;
    int itemCount;
    int potionsConsumedAmount;
    int equippedArmorIndex;
    int equippedWeaponIndex;
    item *inventory[10]{nullptr};
    consumable *consumedPotionsList[10]{nullptr};

public:
    Player();
    ~Player();
    void savePlayerData();
    void loadPlayerData();
    void resetPlayerData();
    std::string addItemToInventory(item& Item);
    std::string removeItemFromInventory(item& Item);
    std::string equipItem(int index);
    std::string unequipItem(int index);
    //it is an item as everything in the loop is thought of as an item. We cast it as
    //a consumable inside this function
    void consumePotion(item& potion);
    void arrayShifter(int index, std::string type);
    std::string removePotionEffect();
    double getAccBoost() const;
    double getWpmBoost() const;
    int getEquippedArmorIndex() const;
    int getEquippedWeaponIndex() const;
    //FOR TESTING, REMOVE B4 INLÄMNING
    void printItems();
};
#endif //PLAYER_H
