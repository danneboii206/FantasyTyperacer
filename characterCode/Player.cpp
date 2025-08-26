//
// Created by rasmu on 2025-08-24.
//
#include "Player.h"
#include <iostream>

Player::Player()
    : accBoost(0), wpmBoost(0), itemCount(0), potionsConsumedAmount(0),
      equippedArmorIndex(-1), equippedWeaponIndex(-1)
{
    loadPlayerData();
}

Player::~Player()
{
    for (int i = 0; i < itemCount; i++)
    {
        delete this->inventory[i];
        this->inventory[i] = nullptr;
    }
    for (int i = 0; i < potionsConsumedAmount; i++)
    {
        delete this->consumedPotionsList[i];
        this->consumedPotionsList[i] = nullptr;
    }

    std::cout<<"destroying player"; //for testing purposes
}

void Player::savePlayerData()
{
    std::string maxHp = std::to_string(this->getMaxHealth());
    std::string Hp = std::to_string(this->getHealth());

    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << maxHp << std::endl;
    saveFile << Hp << std::endl;

    saveFile.close();
}

void Player::loadPlayerData()
{
    std::ifstream saveFile(this->filepath + "/PlayerData.txt");
    std::string line;

    int i = 0;
    while (std::getline(saveFile, line))
    {
        i++;
        switch (i)
        {
            case 1:
                setMaxHealth(std::stoi(line));
                break;
            case 2:
                setHealth(std::stoi(line));
        }
    }

}

void Player::resetPlayerData()
{
    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << 200 << std::endl;
    saveFile << 200 << std::endl;

    saveFile.close();
}

std::string Player::addItemToInventory(item& Item)
{
    //first check if there is space
    if (this->itemCount == 10)
    {
        return "Space is full!";
    }

    if (Item.getType() == "consumable")
    {   //due to consumable being the only one with extra data (duration), everything else is just an item basically.
        consumable* potionPtr = dynamic_cast<consumable*>(&Item);

        inventory[itemCount] = new consumable(*potionPtr);
    } else
    {
        inventory[itemCount] = new item(Item);
    }

    ++itemCount;

    return "Picked up item: " + inventory[itemCount - 1]->getName() + ".";
}

std::string Player::removeItemFromInventory(item& Item)
{
    std::string itemToRemove = Item.getName();
    for (int i = 0; i < itemCount; i++)
    {
        if (this->inventory[i]->getName() == itemToRemove)
        {
            delete this->inventory[i];
            this->inventory[i] = nullptr;
            arrayShifter(i, "inventory");
            --this->itemCount;
            return "Dropped " + itemToRemove + ".";
        }
    }
    return "Item not found"; //should not ever happen
}

std::string Player::equipItem(int index)
{
    std::string type = this->inventory[index]->getType();

    //first, check if there's nothing equipped in its place
    if (type == "armor" && equippedArmorIndex != -1)
    {
        return "Please unequip the armor: " + this->inventory[equippedArmorIndex]->getName() + ".";
    }
    else if (type == "weapon" && equippedWeaponIndex != -1)
    {
        return "Please unequip the weapon: " + this->inventory[equippedWeaponIndex]->getName() + ".";
    }

    //then add the stats from the item to the players stats.
    this->accBoost += this->inventory[index]->getAccuracyBoost();
    this->setMaxHealth(this->getMaxHealth() + this->inventory[index]->getHpBoost());
    this->wpmBoost += this->inventory[index]->getWpmBoost();
    if (type == "armor")
    {
        this->equippedArmorIndex = index;
    } else
    {
        this->equippedWeaponIndex = index;
    }
    return "Equipped " + this->inventory[index]->getName() + ".";
}


std::string Player::unequipItem(int index)
{
    std::string type = this->inventory[index]->getType();

    this->accBoost -= this->inventory[index]->getAccuracyBoost();
    this->setMaxHealth(this->getMaxHealth() - this->inventory[index]->getHpBoost());
    this->wpmBoost -= this->inventory[index]->getWpmBoost();

    if (type == "armor")
    {
        equippedArmorIndex = -1;
    }
    else if (type == "weapon")
    {
        equippedWeaponIndex = -1;
    }
    return "Un-equipped " + inventory[index]->getName() + ".";

}

//For potion effect to wear off, there should always be a check on what the duration is.
//If duration is 0, then removePotionEffect should be called, so implement that in the game loop or something.
//Alright Rasmus?
//FYI: void roundOver(); is a function inside ../items/consumables.h, you can call that with the help of a loop
//checking if consumedPotionsList[i] != nullptr :)
void Player::consumePotion(item& potion)
{
    std::string type = "consumable";
    std::string potName = potion.getName();

    consumable* potionPtr = dynamic_cast<consumable*>(&potion);
    for (int i = 0; i < itemCount; i++)
    {
        if (this->inventory[i]->getName() == potName)
        {
            this->consumedPotionsList[potionsConsumedAmount] = new consumable(*potionPtr);
            delete this->inventory[i];

            arrayShifter(i, "inventory");
            --itemCount;
        }
    }
    ++this->potionsConsumedAmount;
}

void Player::arrayShifter(int index, std::string type)
{
    if (type == "inventory")
    {
        for (int i = index; i < itemCount; i++)
        {
            inventory[i] = inventory[i + 1]; //replaces the one that's currently here with the one that's next
        }
        inventory[itemCount - 1] = nullptr; //so the last one doesn't repeat twice
    }
    else if (type == "potions")
    {
        for (int i = index; i < itemCount; i++)
        {
            consumedPotionsList[i] = consumedPotionsList[i + 1]; //replaces the one that's currently here with the one that's next
        }
        consumedPotionsList[itemCount - 1] = nullptr; //so the last one doesn't repeat twice
    }
}

std::string Player::removePotionEffect()
{
    std::string potConcat = "";
    for (int i = 0; i < potionsConsumedAmount; i++)
    {
        if (this->consumedPotionsList[i]->getDuration() == 0)
        {
            this->wpmBoost -= this->consumedPotionsList[i]->getWpmBoost();
            this->setMaxHealth(this->getMaxHealth() - this->consumedPotionsList[i]->getHpBoost());
            this->accBoost -= this->consumedPotionsList[i]->getAccuracyBoost();

            potConcat += this->consumedPotionsList[i]->getName();
        }
    }
    return "Potion effects cleared: " + potConcat;
}

double Player::getAccBoost() const
{
    return this->accBoost;
}

double Player::getWpmBoost() const
{
    return this->wpmBoost;
}

int Player::getEquippedArmorIndex() const
{
    return this->equippedArmorIndex;
}

int Player::getEquippedWeaponIndex() const
{
    return this->equippedWeaponIndex;
}

//STRICTLY FOR TESTING, REMOVE B4 INLÄMNING
void Player::printItems()
{
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << "name: " + this->inventory[i]->getName() + " type: " + this->inventory[i]->getType() << std::endl;
    }
}
