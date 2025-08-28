#include <iostream>
#include "roomManager.h"
#include "./characterCode/skeleton.h"
#include "combat.h"
#include "characterCode/dragon.h"

void roomManager(Player& player)
{
    int roomCount = 4; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        std::cout << "room number: " << i << std::endl;
        Rooms room = Rooms();
        roomPrint(room);

        roomInput(room, player);
    }
    Dragon* dragon = new Dragon();
    std::string waitInp;
    if (combat(dragon, player) == 0)
    {
        delete dragon;
        dragon = nullptr;

        std::cout << "you died! press any key + enter to return to main menu.";
        std::cin >> waitInp;
        return;
    }
    clearScreen();
    printFile("../Art/winText.txt");
    std::cout << std::endl << "Congratulations " << player.getName() <<
                 ", you have defeated the dragon and all the dungeons riches are now yours!" << std::endl;
    std::cout << "\npress any key + enter to return to main menu. \n";
    std::cin >> waitInp;

    delete dragon;
    dragon = nullptr;

    return;
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
    bool eventTriggered = false;

    while (!eventTriggered)
    {
        roomPrint(room);
        int input = menuInput(2);
        switch (input)
        {
            case 1:
                triggerEvent(room, player);
                eventTriggered = true;
            break;

            case 2:
                openInventory(player);
            break;

        }
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
        if (combat(enemy, player) == 0)
        {
            std::cout << "you died! press 1 to return to main menu.";
            menuInput(1);
            printMainMenu();
        }

        delete enemy;
        enemy = nullptr;
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
    }
    return 1;
}