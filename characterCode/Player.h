#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "../items/item.h"
#include "../items/Equippable.h"
#include "../items/consumable.h"
#include <vector>
#include <memory>

#include <fstream>
class Player : public Character
{
private:
    const int MAX_INVENTORY_SIZE = 10;
    std::string name;
    double accBoost;
    double wpmBoost;
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
    void setName(std::string name) override;
    std::string getName() const;
    double getAccBoost() const;
    double getWpmBoost() const;
    int getEquippedArmorIndex() const;
    int getEquippedWeaponIndex() const;
    item* getItemAtIndex(int index) const;
    int getMAX_INVENTORY_SIZE() const;
    void printItems() const;
    void printStats() const;
};
#endif //PLAYER_H
