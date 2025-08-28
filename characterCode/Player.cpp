#include "Player.h"
#include <iostream>
#include "../items/armor.h"
#include "../items/weapon.h"

Player::Player()
    : Character(200), accBoost(0), wpmBoost(0)
{
}

Player::~Player()
{
}

std::string Player::addItemToInventory(item& Item)
{
    std::string type = Item.getType();

    //first check if there is space
    if (this->inventory.size() == MAX_INVENTORY_SIZE)
    {
        return "Space is full! Consider dropping an item";
    }

    if (type == "consumable")
    {   //due to consumable being the only one with extra data (duration), everything else is just an item basically.
        consumable* potionPtr = dynamic_cast<consumable*>(&Item);

        inventory.push_back(std::make_unique<consumable>(*potionPtr));
    } else if (type == "weapon")
    {
        weapon* weaponPtr = dynamic_cast<weapon*>(&Item);

        inventory.push_back(std::make_unique<weapon>(*weaponPtr));
    } else
    {
        armor* armorPtr = dynamic_cast<armor*>(&Item);

        inventory.push_back(std::make_unique<armor>(*armorPtr));
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
    item* itemAtIndex = this->getItemAtIndex(index);
    std::string type = itemAtIndex->getType();

    //first, check if there's nothing equipped in its place
    if (type == "armor" && this->getEquippedArmorIndex() != -1)
    {
        return "Please un-equip the armor: " + this->inventory[this->getEquippedArmorIndex()]->getName() + ".";
    }
    else if (type == "weapon" && this->getEquippedWeaponIndex() != -1)
    {
        return "Please un-equip the weapon: " + this->inventory[this->getEquippedWeaponIndex()]->getName() + ".";
    }

    //then add the stats from the item to the players stats.
    this->accBoost += itemAtIndex->getAccuracyBoost();
    this->setMaxHealth(this->getMaxHealth() + itemAtIndex->getHpBoost());
    this->wpmBoost += itemAtIndex->getWpmBoost();
    if (type == "armor")
    {
        armor* armorPtr = dynamic_cast<armor*>(itemAtIndex);
        armorPtr->setIsEquipped(true);
    } else
    {
        weapon* weaponPtr = dynamic_cast<weapon*>(itemAtIndex);
        weaponPtr->setIsEquipped(true);
    }
    return "Equipped " + itemAtIndex->getName() + ".";
}


std::string Player::unequipItem(int index)
{
    item* itemAtIndex = this->getItemAtIndex(index);
    std::string type = this->inventory[index]->getType();

    this->accBoost -= itemAtIndex->getAccuracyBoost();
    this->setMaxHealth(this->getMaxHealth() - itemAtIndex->getHpBoost());
    if (this->getHealth() > this->getMaxHealth()) //incase the item made your max-hp lower
    {
        this->setHealth(this->getMaxHealth());
    }
    this->wpmBoost -= itemAtIndex->getWpmBoost();

    if (type == "armor")
    {
        armor* armorPtr = dynamic_cast<armor*>(itemAtIndex);
        armorPtr->setIsEquipped(false);
    }
    else if (type == "weapon")
    {
        weapon* weaponPtr = dynamic_cast<weapon*>(itemAtIndex);
        weaponPtr->setIsEquipped(false);
    }
    return "Un-equipped " + itemAtIndex->getName() + ".";

}

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
}

std::string Player::potionCheckValidity()
{
    std::string potConcatExpired;
    std::string potConcatValid;
    for (int i = 0; i < consumedPotionsList.size(); i++)
    {
        if (this->consumedPotionsList[i]->getDuration() == 0)
        {
            this->wpmBoost -= this->consumedPotionsList[i]->getWpmBoost();
            this->setMaxHealth(this->getMaxHealth() - this->consumedPotionsList[i]->getHpBoost());
            this->accBoost -= this->consumedPotionsList[i]->getAccuracyBoost();

            consumedPotionsList.erase(consumedPotionsList.begin() + i);

            potConcatExpired += this->consumedPotionsList[i]->getName();
        } else
        {
            this->consumedPotionsList[i]->roundOver();

            potConcatExpired += this->consumedPotionsList[i]->getName();
        }
    }
    return "Potions still in effect: " + potConcatValid + "Potions effects cleared: " + potConcatExpired;
}

void Player::setName(std::string name)
{
    this->name = name;
}

std::string Player::getName() const
{
    return this->name;
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
    for (int i = 0; i < this->inventory.size(); i++)
    {
        bool equipped = false;

        armor* armorPtr = dynamic_cast<armor*>(this->inventory[i].get());
        if (armorPtr != nullptr)
        {
            equipped = armorPtr->getIsEquipped();

            if (equipped == true)
            {
                return i;
            }
        }
    }
    return -1;
}

int Player::getEquippedWeaponIndex() const
{
    for (int i = 0; i < this->inventory.size(); i++)
    {
        bool equipped = false;

        weapon* weaponPtr = dynamic_cast<weapon*>(this->inventory[i].get());
        if (weaponPtr != nullptr)
        {
            equipped = weaponPtr->getIsEquipped();

            if (equipped == true)
            {
                return i;
            }
        }
    }
    return -1;
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

int Player::getMAX_INVENTORY_SIZE() const
{
    return this->MAX_INVENTORY_SIZE;
}
