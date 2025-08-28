#include <iostream>
#include <fstream>
#include <string>
#include "menus.h"
#include "roomManager.h"
#include "./characterCode/Player.h"
#include "items/weapon.h"
#include "items/armor.h"
//#include <sanitizer/lsan_interface.h>
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#define prt(x) std::cout << x << std::endl

void printMainMenu()
{
    clearScreen();
    //prints logo
    printFile("../bardic.txt");

    prt("enter the number corresponding to the choice you would like to make.");
    std::cout << std::endl;
    prt("1) start game");
    std::cout << std::endl;
    prt("2) exit game");
    std::cout << std::endl;
    Player player;
    std::string name;
    int input = menuInput(2);
    switch (input)
    {
        case 1:
            prt("What's your name?");
            std::cin >> name;
            player.setName(name);
            roomManager(player);
            break;
        case 2:
            //__lsan_do_leak_check();
            //_CrtDumpMemoryLeaks();
            exit(0);
    }
}

void clearScreen()
{
    for (int i = 0; i < 80; i++)
        std::cout << std::endl;
}

void printFile(std::string filePath)
{
    std::ifstream file(filePath); // Changed to ifstream for reading
    if (file.is_open()) {
        // Print the contents of the file
        std::cout << file.rdbuf();
        std::cout << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Unable to open" << filePath << std::endl;
        //prt(std::filesystem::current_path());
    }
}

int menuInput(int menuChoices)
{
    std::string strInput;
    int selecting = true;
    int input = 0;

    while (selecting == true) //iterates through a while loop until input is valid
    {
        input = 0;
        std::cin >> strInput;

        if (isNumber(strInput) == false)
        {
            prt("Wrong input, press enter to try again.");
            std::cin >> strInput;
            break;
        }

        input = stoi(strInput);

        if (input > 0 && input <= menuChoices)
        {
            selecting = false;
            break;
        }


        prt("Wrong input, press enter to try again.");
        std::cin >> strInput;
    }

    return input;

}

bool isNumber(const std::string input)
{
    for (int i = 0; i < input.length(); i++) //iterates through string. returns false if char can't be converted to int.
    {
        if (!isdigit(input[i]))
        {
            return false; //exists for-loop
        }
    }
    return true; //incase for-loop continued (isdigit = true)
}

//prints information about a given item
void openInventory(Player& player)
{

    std::vector<std::shared_ptr<item>> playerItems;
    int itemCount = player.getMAX_INVENTORY_SIZE();

    while (true)
    {
        item* itemTest = player.getItemAtIndex(1);
        clearScreen();

        std::cout << "\n";
        std::cout << "type the corresponding number to interact with the item" << "\n";
        //give loot
        int menuChoices = 0;


        for (int i = 0; i < itemCount; i++)
        {
            auto item = player.getItemAtIndex(i);
            if (item == nullptr)
            {
                std::cout<< "\n" << i+1 << ": empty" << "\n";

            }
            else
            {
                std::cout<< "\n" << i+1 << ": select " << item->getName() << "\n";

            }
            menuChoices++;

        }

        std::cout<< "\n" << menuChoices+1 << ": leave" << "\n";
        int input = menuInput(menuChoices + 1);
        std::cout << input;

        if (input == menuChoices+1)
            return;

         for (int i = 0; i < menuChoices; i++)
         {
             std::cout << "\n" << i << "\n";
             if (i == input - 1)
             {
                 interactWithItem(player, i);

             }
         }


    }

}

void interactWithItem(Player& player, int index)
{
    clearScreen();
        if (player.getItemAtIndex(index) == nullptr)
        {
            std::cout << "\n there is no item. \n";
            std::cout << "press enter to return\n";
            menuInput(1);

            return;
        }

    item* itemAtIndex = player.getItemAtIndex(index);
    std::string type = itemAtIndex->getType();
    bool equipped = false;

    if (type == "armor")
    {
        armor* armorPtr = dynamic_cast<armor*>(itemAtIndex);
        equipped = armorPtr->getIsEquipped();
    } else if (type == "weapon")
    {
        weapon* weaponPtr = dynamic_cast<weapon*>(itemAtIndex);
        equipped = weaponPtr->getIsEquipped();
    }

    std::cout << "\n" << itemAtIndex->getName() << "\n";
    std::cout << "\n" << itemAtIndex->getDescription() << "\n";
    std::cout << "\n" << "type: " << type << "\n";

    if (type == "consumable")
    {
        std::cout << "\n" << "1: use item" << "\n";
        std::cout<< "\n" << "2: discard item" << "\n";
        std::cout << "\n" << "3: leave" << "\n";
    } else if (type != "consumable" && equipped == false)
    {
        std::cout << "\n" << "1: equip item" << "\n";
        std::cout<< "\n" << "2: discard item" << "\n";
        std::cout << "\n" << "3: leave" << "\n";
    } else
    {
        std::cout << "\n" << "1: un-equip item" << "\n";
        std::cout<< "\n" << "2: discard item" << "\n";
        std::cout << "\n" << "3: leave" << "\n";
    }

    int input = menuInput(3);

    if (input == 1)
    {
        if (type == "consumable")
            player.consumePotion(index);
        else if (type != "consumable" && equipped == false )
            player.equipItem(index);
        else
            player.unequipItem(index);
    }
    else if (input == 2)
        player.removeItemFromInventory(index);
    else
        return;

}