#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../items/item.h"
#include "../items/consumable.h"
#include <vector>
#include <memory>

#include <fstream>
class Player : public Character
{
private:
    const double MAX_HEALTH = 200;
    const int MAX_INVENTORY_SIZE = 10;
    double accBoost;
    double wpmBoost;
    int potionsConsumedAmount;
    int equippedArmorIndex;
    int equippedWeaponIndex;
    std::vector<std::unique_ptr<item>> inventory;
    std::vector<std::unique_ptr<consumable>> consumedPotionsList;
public:
    Player();
    ~Player() override;
    std::string addItemToInventory(item& Item);
    std::string removeItemFromInventory(int index);
    std::string equipItem(int index);
    std::string unequipItem(int index);
    void consumePotion(int index);
    std::string potionCheckValidity();
    double getAccBoost() const;
    double getWpmBoost() const;
    int getEquippedArmorIndex() const;
    int getEquippedWeaponIndex() const;
    void printItems() const;
    item* getItemAtIndex(int index) const;
    int getMAX_INVENTORY_SIZE() const;
    void printStats() const;
};
#endif //PLAYER_H
