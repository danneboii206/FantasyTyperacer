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
/*
//for testing purposes
    item* items[4];
    items[0] = new accPotion;
    items[1] = new dragonArmor;
    items[2] = new dungeonMastersSpear;
    items[3] = new divineSword;

    for (int i = 0; i < 4; i++)
    {
        std::cout << "name: " + items[i]->getName() + "type: " + items[i]->getType() << std::endl;
    }
    std::cout << "--creating items & player";
    std::cout << "---------------------------" << std::endl;
    Player player;
    player.addItemToInventory(*items[0]);
    player.printItems();

    std::cout << "--adding to inventory";
    std::cout << "---------------------------" << std::endl;
    player.addItemToInventory(*items[1]);
    player.addItemToInventory(*items[2]);
    player.addItemToInventory(*items[3]);
    player.printItems();

    std::cout << "--removing from inventory";
    std::cout << "---------------------------" << std::endl;
    player.removeItemFromInventory(*items[0]);
    player.printItems();

    std::cout << "--hp stat change";
    std::cout << "---------------------------" << std::endl;
    std::cout << "max hp before: " + std::to_string(player.getMaxHealth()) << std::endl;
    std::cout << player.equipItem(0) << std::endl;
    std::cout << "max hp after: " + std::to_string(player.getMaxHealth()) << std::endl;

    std::cout << "--accuracy & wpm stat change";
    std::cout << "---------------------------" << std::endl;
    std::cout << "accuracy b4: " + std::to_string(player.getAccBoost()) +
                 " wpm b4: " + std::to_string(player.getWpmBoost()) << std::endl;
    std::cout << player.equipItem(2) << std::endl;;
    std::cout << "accuracy after: " + std::to_string(player.getAccBoost()) +
                 " wpm after: " + std::to_string(player.getWpmBoost()) << std::endl;

    std::cout << "--Trying to equip two swords";
    std::cout << "---------------------------" << std::endl;
    std::cout << "accuracy b4: " + std::to_string(player.getAccBoost()) +
                 " wpm b4: " + std::to_string(player.getWpmBoost()) << std::endl;
    std::cout << player.equipItem(1) << std::endl;;
    std::cout << "accuracy after: " + std::to_string(player.getAccBoost()) +
                 " wpm after: " + std::to_string(player.getWpmBoost()) << std::endl;

    std::cout << "--un-equipping weapon";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.unequipItem(2) << std::endl;
    std::cout << "accuracy after: " + std::to_string(player.getAccBoost()) +
                 " wpm after: " + std::to_string(player.getWpmBoost()) << std::endl;

    std::cout << "--re-equipping weapon";
    std::cout << "---------------------------" << std::endl;
    std::cout << player.equipItem(1) << std::endl;;
    std::cout << "accuracy after: " + std::to_string(player.getAccBoost()) +
                 " wpm after: " + std::to_string(player.getWpmBoost()) << std::endl;

    std::cout << "--un-equipping armor";
    std::cout << "---------------------------" << std::endl;
    std::cout << "max hp before: " + std::to_string(player.getMaxHealth()) << std::endl;
    std::cout << player.unequipItem(0) << std::endl;
    std::cout << "max hp after: " + std::to_string(player.getMaxHealth()) << std::endl;

    std::cout << "--re-equipping armor";
    std::cout << "---------------------------" << std::endl;
    std::cout << "max hp before: " + std::to_string(player.getMaxHealth()) << std::endl;
    std::cout << player.equipItem(0) << std::endl;
    std::cout << "max hp after: " + std::to_string(player.getMaxHealth()) << std::endl;
   //TODO: TRY OUT POTIONS!/////////////////////////////////////////////////////////////////////////
*/
    Rooms room = Rooms();



    while (true)
    {


        printMainMenu();

    }




    return 0;
}

