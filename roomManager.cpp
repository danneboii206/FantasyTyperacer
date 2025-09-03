#include <iostream>
#include "roomManager.h"
#include "combat.h"
#include "rooms.h"
#include "menus.h"


RoomManager::RoomManager()
{
    menu = menus();
    theCombat = Combat();
}

int RoomManager::printMainMenu()
{
    menu.clearScreen();
    //prints logo
    menu.printFile("../bardic.txt");

    prt("enter the number corresponding to the choice you would like to make.");
    std::cout << std::endl;
    prt("1) start game");
    std::cout << std::endl;
    prt("2) exit game");
    std::cout << std::endl;
    Player player;
    std::string name;
    int input = menu.menuInput(2);
    switch (input)
    {
        case 1:
            prt("What's your name?");
        std::cin >> name;
        player.setName(name);
        roomManager(player);
        break;
        case 2:
            return -5;
    }
    return 0;
}

void RoomManager::roomManager(Player& player)
{
    const int roomCount = 4; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        std::cout << "room number: " << i << std::endl;
        Rooms room = Rooms();
        roomPrint(room);

        roomInput(room, player);
    }
    Enemy* dragon = new Enemy(50, 200, "Dragon");
    dragon->setDescriptionPath("../descriptions/enemyDescriptions/dragonDescription.txt");
    dragon->setArtPath("../art/enemyPortraits/dragon.txt");
    std::string waitInp;
    if (theCombat.combat(dragon, player) == 0)
    {
        delete dragon;
        dragon = nullptr;

        std::cout << "you died! press any key + enter to return to main menu.";
        std::cin >> waitInp;
        return;
    }
    menu.clearScreen();
    menu.printFile("../Art/winText.txt");
    std::cout << std::endl << "Congratulations " << player.getName() <<
                 ", you have defeated the dragon and all the dungeons riches are now yours!" << std::endl;
    std::cout << "\n press any key + enter to return to main menu. \n";
    std::cin >> waitInp;

    delete dragon;
    dragon = nullptr;
}


void RoomManager::roomPrint(Rooms room)
{
    menu.clearScreen();
    menu.printFile(room.getDescription());
    std::cout<< "\n" << "1: Proceed" << "\n";
    std::cout<< "\n" << "2: Use item" << "\n";
}

int RoomManager::roomInput(Rooms room, Player& player)
{
    bool eventTriggered = false;

    while (!eventTriggered)
    {
        roomPrint(room);
        int input = menu.menuInput(2);
        switch (input)
        {
            case 1:
                triggerEvent(room, player);
                eventTriggered = true;
            break;

            case 2:
                menu.openInventory(player);
            break;

        }
    }
    return 1;
}

int RoomManager::triggerEvent(Rooms room, Player& player)
{
    if (room.getHasEnemy() == true)
    {
        srand(time(NULL));
        int rnd = rand() % 2;
        Enemy* enemy = nullptr;
        switch (rnd)
        {
            case 0:
                enemy = new Enemy(10, 100, "Goblin");
                enemy->setDescriptionPath("../descriptions/enemyDescriptions/goblinDescription.txt");
                enemy->setArtPath("../art/enemyPortraits/goblin.txt");

            break;

            case 1:
                enemy = new Enemy(20, 50, "Skeleton");
                enemy->setDescriptionPath("../descriptions/enemyDescriptions/skeletonDescription.txt");
                enemy->setArtPath("../art/enemyPortraits/skeleton.txt");

        }
        theCombat = Combat();
        if (theCombat.combat(enemy, player) == 0)
        {
            std::cout << "you died! press 1 to return to main menu.";
            menu.menuInput(1);
            printMainMenu();
        }

        delete enemy;
        enemy = nullptr;
    }
    finishRoom(room, player);
    std::cout << "test";
    return 1;
}

int RoomManager::finishRoom(Rooms room, Player& player)
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
        menu.clearScreen();

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
        int input = menu.menuInput(menuChoices + 1);
        std::cout << input;

        if (input == menuChoices+1)
            return 1;


        player.addItemToInventory(*roomItems[input-1]);
        roomItems.erase(roomItems.begin() + input-1);
        itemCount--;
    }
    return 1;
}