//
// Created by rasmu on 2025-08-26.
//
#include "roomManager.h"

#include <iostream>


void roomManager()
{

    int roomCount = 10; //amount of rooms to explore before the boss is encountered

    for (int i = 0; i < roomCount; i++)
    {
        Rooms room = Rooms();
        roomPrint(room);
        roomInput(room);
    }
}

void roomPrint(Rooms room)
{
    printFile(room.getDescription());
    std::cout<< "\n" << "1: Proceed" << "\n";
    std::cout<< "\n" << "2: Use item";
}

void roomInput(Rooms room)
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
}

void triggerEvent(Rooms room)
{
    if (room.getHasEnemy() == true)
        combat();

    finishRoom(room);
}

void finishRoom(Rooms room)
{
    //give loot
}