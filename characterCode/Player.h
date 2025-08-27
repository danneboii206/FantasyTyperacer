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
#include <vector>
#include <memory>

#include <fstream>
class Player : public Character
{
private:
    std::string filepath = "../data";

    double accBoost;
    double wpmBoost;
    int potionsConsumedAmount;
    int equippedArmorIndex;
    int equippedWeaponIndex;
    const int MAX_INVENTORY_SIZE = 10;
    std::vector<std::unique_ptr<item>> inventory;
    std::vector<std::unique_ptr<consumable>> consumedPotionsList;

public:
    Player();
    ~Player() override;
    void savePlayerData();
    void loadPlayerData();
    void resetPlayerData();
    std::string addItemToInventory(item& Item);
    std::string removeItemFromInventory(int index);
    std::string equipItem(int index);
    std::string unequipItem(int index);
    //it is an item as everything in the loop is thought of as an item. We cast it as
    //a consumable inside this function
    void consumePotion(int index);
    std::string potionCheckValidity();
    double getAccBoost() const;
    double getWpmBoost() const;
    int getEquippedArmorIndex() const;
    int getEquippedWeaponIndex() const;
    void printItems() const;
    item getItemAtIndex(int index) const;
    int getMAX_INVENTORY_SIZE();

    //FOR TESTING, REMOVE B4 INLÄMNING
    void printStats() const;

};
#endif //PLAYER_H
