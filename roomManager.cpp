//
// Created by rasmu on 2025-08-26.
//
#include "roomManager.h"
#include "./characterCode/skeleton.h"
#include <iostream>

#include "characterCode/dragon.h"


void roomManager()
{

    Player player = Player();
    int roomCount = 5; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        std::cout << "room number: " << i << std::endl;
        Rooms room = Rooms();
        roomPrint(room);

        roomInput(room, player);
    }
    combat(new Dragon(), player);
    printFile("../Art/winText.txt");
    std::cout << "\n you defeated the evil dragon and earned his treasures! \n";
    std::cout << "\n 1: return to main menu. \n";
    menuInput(1);
    printMainMenu();
}


void roomPrint(Rooms room)
{
    clearScreen();
    printFile(room.getDescription());
    std::cout<< "\n" << "1: Proceed" << "\n";
    std::cout<< "\n" << "2: Use item" << "\n";
}

int roomInput(Rooms room, Player& player)
{

    int input = menuInput(2);
    switch (input)
    {
        case 1:
            triggerEvent(room, player);
        break;

        case 2:
            openInventory(player);
        break;

    }
    return 1;
}

int triggerEvent(Rooms room, Player& player)
{
    if (room.getHasEnemy() == true)
    {
        srand(time(NULL));
        int rnd = rand() % 2;
        Enemy* enemy = nullptr;
        switch (rnd)
        {
            case 0:
                enemy = new Goblin();
            break;

            case 1:
                enemy = new Skeleton();

        }
        combat(enemy, player);

        enemy = nullptr;
        delete enemy;


    }
    finishRoom(room, player);
    std::cout << "test";
    return 1;
}

int finishRoom(Rooms room, Player& player)
{
    std::vector<std::shared_ptr<item>> roomItems;
    int itemCount = room.getItemCount();

    for (int i = 0; i < itemCount; i++)
    {
        roomItems.push_back(room.getItemAtIndex(i));
    }


    while (true)
    {

        //give loot
        int menuChoices = 0;
        clearScreen();

        if (itemCount == 0)
            std::cout << " \n There are no items to pick up \n";
        else
            std::cout << "\n you may pick any number of these items: \n";


        for (int i = 0; i < itemCount; i++)
        {
            auto item = roomItems[i];
            if (item == nullptr)
                break;
            std::cout<< "\n" << i+1 << ": take " << item->getName() << "\n";
            menuChoices++;

        }

        std::cout<< "\n" << menuChoices+1 << ": leave" << "\n";
        int input = menuInput(menuChoices + 1);
        std::cout << input;

        if (input == menuChoices+1)
            return 1;


        player.addItemToInventory(*roomItems[input-1]);
        roomItems.erase(roomItems.begin() + input-1);
        itemCount--;

        player.printItems();

           /* for (int i = 0; i < menuChoices; i++)
            {
                std::cout << "\n" << i << "\n";
                if (i == input + 1)
                {
                    item itemCopy = *room.getItemAtIndex(i);
                    player.addItemToInventory(itemCopy);
                    std::cout << itemCopy.getName();

                }
            }*/


    }
    return 1;
}