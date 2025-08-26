//
// Created by rasmu on 2025-08-26.
//
#include "roomManager.h"
#include "./characterCode/skeleton.h"
#include <iostream>

#include "characterCode/dragon.h"


void roomManager()
{

    int roomCount = 10; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        std::cout << "room number: " << i << std::endl;
        Rooms room = Rooms();
        roomPrint(room);
        roomInput(room);
    }
    combat(new Dragon());
}


void roomPrint(Rooms room)
{
    printFile(room.getDescription());
    std::cout<< "\n" << "1: Proceed" << "\n";
    std::cout<< "\n" << "2: Use item" << "\n";
}

int roomInput(Rooms room)
{

    int input = menuInput(2);
    switch (input)
    {
        case 1:
            triggerEvent(room);
        break;

        case 2:
            //use item
        break;

    }
    return 1;
}

int triggerEvent(Rooms room)
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
        combat(enemy);

        enemy = nullptr;
        delete enemy;
        finishRoom(room);

    }
    std::cout << "test";
    return 1;
}

int finishRoom(Rooms room)
{
    //give loot
    return 1;
}