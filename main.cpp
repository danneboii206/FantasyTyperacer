#include <iostream>
#include <string>
#include "menus.h"
#include "combat.h"
#include "./characterCode/goblin.h"
#include "rooms.h"

/* // TESTING PURPOSES
#include "items/accPotion.h"
#include "items/dragonArmor.h"
#include "items/dungeonMastersSpear.h"
#include "characterCode/Player.h"
#include "items/divineSword.h"
*/

#define prt(x) std::cout << x << std::endl

int main()
{

//for testing purposes
    int nrOfItems = 5;
    item* items[nrOfItems];
    items[0] = new accPotion;
    items[1] = new dragonArmor;
    items[2] = new dungeonMastersSpear;
    items[3] = new divineSword;
    items[4] = new hpPotion;

    for (int i = 0; i < nrOfItems; i++)
    {
        std::cout << "items[" << i << "] = " << items[i]->getName() << " type: " << items[i]->getType() << std::endl;
    }

    //testing adding items in inventory and using player specific functions
    std::cout << "--creating items & player and adding items[0] to inventory";
    std::cout << "---------------------------" << std::endl;
    Player player;
    player.addItemToInventory(*items[0]);
    player.printItems();

    std::cout << "--adding to inventory items[1] -> items[3]";
    std::cout << "---------------------------" << std::endl;
    player.addItemToInventory(*items[1]);
    player.addItemToInventory(*items[2]);
    player.addItemToInventory(*items[3]);
    std::cout << "--printing inventory objects" << std::endl;
    player.printItems();

    //testing how inventory acts when an object is removed
    std::cout << "--removing from inventory items[0] (acc_potion)";
    std::cout << "---------------------------" << std::endl;
    player.removeItemFromInventory(*items[0]);
    std::cout << "--printing inventory objects" << std::endl;
    player.printItems();

    //testing how items effect status (hpBoost, etc.)
    std::cout << "--printing player stats with no equipped item(s)";
    std::cout << "---------------------------" << std::endl;
    std::cout << "--printing player stats" << std::endl;
    player.printStats();

    std::cout << "--equipping items[1] (Dragon Armor)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(0) << std::endl;
    std::cout << "--printing player stats" << std::endl;
    player.printStats();

    std::cout << "--equipping items[3] (Divine sword)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(2) << std::endl;;
    std::cout << "--printing player stats" << std::endl;
    player.printStats();

    //double equipping
    std::cout << "--Trying to equip two weapons (dungeon masters spear)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(1) << std::endl;;
    player.printStats();

    std::cout << "--un-equipping weapon (divine sword)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.unequipItem(2) << std::endl;
    player.printStats();

    std::cout << "--re-trying to equip weapon (dungeon masters spear)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(1) << std::endl;;
    player.printStats();

    std::cout << "--un-equipping armor (dragon armor)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.unequipItem(0) << std::endl;
    player.printStats();

    std::cout << "--re-equipping armor";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(0) << std::endl;
    player.printStats();

    //testing health potions
    Player player2;

    std::cout << "--picking up health potion";
    std::cout << "---------------------------" << std::endl;
    player2.addItemToInventory(*items[4]);

    std::cout << "--printing items";
    std::cout << "---------------------------" << std::endl;
    player2.printItems();

    std::cout << "--printing hp";
    std::cout << "---------------------------" << std::endl;
    std::cout << player2.getHealth() << std::endl;

    std::cout << "--consuming health potion";
    std::cout << "---------------------------" << std::endl;
    player2.consumePotion(0);

    std::cout << "--checking if item still inventory";
    std::cout << "---------------------------" << std::endl;
    player2.printItems();

    std::cout << "--printing hp (should be same)";
    std::cout << "---------------------------" << std::endl;
    std::cout << player2.getHealth() << std::endl;

    std::cout << "--taking damage (-20hp)";
    std::cout << "---------------------------" << std::endl;
    player2.takeDamage(20);

    std::cout << "--printing hp (should be 180)" << std::endl;
    std::cout << player2.getHealth() << std::endl;

    std::cout << "--picking up health potion";
    std::cout << "---------------------------" << std::endl;
    player2.addItemToInventory(*items[4]);

    std::cout << "--checking if item in inventory";
    std::cout << "---------------------------" << std::endl;
    player2.printItems();

    std::cout << "--healing +50 hp (should be capped at 200)" << std::endl;
    player2.consumePotion(0);
    std::cout << "--printing hp (should be 200)" << std::endl;
    std::cout << player2.getHealth() << std::endl;

    //freeing upp memory from all the items in the array
    for (int i = 0; i < nrOfItems; i++)
    {
        delete items[i];
    }

   //TODO: TRY OUT POTIONS!/////////////////////////////////////////////////////////////////////////
/*
    Rooms room = Rooms();



    while (true)
    {


        printMainMenu();

    }



*/
    return 0;
}

