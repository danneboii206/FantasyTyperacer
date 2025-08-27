//
// Created by rasmu on 2025-08-24.
//
#include "Player.h"
#include <iostream>

Player::Player()
    : accBoost(0), wpmBoost(0), potionsConsumedAmount(0),
      equippedArmorIndex(-1), equippedWeaponIndex(-1), Character(200)
{
    //loadPlayerData();
}

Player::~Player()
{
    std::cout<<"destroying player"; //for testing purposes
}

void Player::savePlayerData()
{
    //obsolete
    std::string maxHp = std::to_string(this->getMaxHealth());
    std::string Hp = std::to_string(this->getHealth());

    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << maxHp << std::endl;
    saveFile << Hp << std::endl;

    saveFile.close();
}

void Player::loadPlayerData()
{
    //obsolete
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
    //obsolete
    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << 200 << std::endl;
    saveFile << 200 << std::endl;

    saveFile.close();
}

std::string Player::addItemToInventory(item& Item)
{
    //first check if there is space
    if (this->inventory.size() == MAX_INVENTORY_SIZE)
    {
        return "Space is full! Consider dropping an item";
    }

    if (Item.getType() == "consumable")
    {   //due to consumable being the only one with extra data (duration), everything else is just an item basically.
        consumable* potionPtr = dynamic_cast<consumable*>(&Item);

        inventory.push_back(std::make_unique<consumable>(*potionPtr));
    } else
    {
        inventory.push_back(std::make_unique<item>(Item));
    }

    return "Picked up item: " + this->inventory[this->inventory.size() - 1]->getName() + ".";
}

std::string Player::removeItemFromInventory(int index)
{
    std::string itemName = inventory[index]->getName();

    inventory.erase(inventory.begin() + index);

    return "Dropped item: " + itemName + ".";
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
    if (this->getHealth() > this->getMaxHealth()) //incase the item made your max-hp lower
    {
        this->setHealth(this->getMaxHealth());
    }
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
void Player::consumePotion(int index)
{
    consumable* potPtr = dynamic_cast<consumable*>(this->inventory[index].get());
    std::string potName = potPtr->getName();

    if (potName == "Healing Potion" || potName == "Big Healing Potion" )
    {
        double hpAm = potPtr->getInstantHeal();
        double hpFinal = this->getHealth() + hpAm;

        if (hpFinal > this->getMaxHealth())
        {
            this->setHealth(this->getMaxHealth());
        } else
        {
            this->setHealth(hpFinal);
        }
    } else
    {
        consumedPotionsList.push_back(std::make_unique<consumable>(*potPtr));
        this->wpmBoost += potPtr->getWpmBoost();
        this->accBoost += potPtr->getAccuracyBoost();
        this->setMaxHealth(this->getMaxHealth() + potPtr->getHpBoost());
    }
    this->removeItemFromInventory(index);

    ++this->potionsConsumedAmount;
}

std::string Player::potionCheckValidity()
{
    std::string potConcat;
    for (int i = 0; i < potionsConsumedAmount; i++)
    {
        if (this->consumedPotionsList[i]->getDuration() == 0)
        {
            this->wpmBoost -= this->consumedPotionsList[i]->getWpmBoost();
            this->setMaxHealth(this->getMaxHealth() - this->consumedPotionsList[i]->getHpBoost());
            this->accBoost -= this->consumedPotionsList[i]->getAccuracyBoost();

            potConcat += this->consumedPotionsList[i]->getName();
        } else
        {
            this->consumedPotionsList[i]->roundOver();
            return potConcat;
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

void Player::printItems() const
{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        std::cout << "index: [" << i << "], " <<"name: " + this->inventory[i]->getName() +
            ", type: " + this->inventory[i]->getType() << std::endl;
    }
}

//STRICTLY FOR TESTING, REMOVE B4 INLÄMNING
void Player::printStats() const
{
    std::cout << "wpm boost: +" << this->wpmBoost << "wpm, accuracy boost: +"
              << this->accBoost << "%, maxHP: " << std::to_string(this->getMaxHealth()) << std::endl;
}

item* Player::getItemAtIndex(int index) const
{
    if (index >= this->inventory.size())
        return nullptr;
    return this->inventory[index].get();
}

int Player::getMAX_INVENTORY_SIZE()
{
    return this->MAX_INVENTORY_SIZE;
}

