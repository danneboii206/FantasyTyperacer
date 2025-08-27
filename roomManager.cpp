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
    int roomCount = 10; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        std::cout << "room number: " << i << std::endl;
        Rooms room = Rooms();
        roomPrint(room);
        roomInput(room, player);
    }
    combat(new Dragon(), player);
}


void roomPrint(Rooms room)
{
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
            //use item
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
        finishRoom(room, player);

    }
    std::cout << "test";
    return 1;
}

int finishRoom(Rooms room, Player& player)
{
    //give loot
    return 1;
}