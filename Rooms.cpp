//
// Created by Daniel Abu Ramadan on 2025-01-10.
//

#include "rooms.h"
#include <iostream>
#include <fstream>
#include <random>

Rooms::Rooms()
{
    generateRoom();
    description = descriptionSelector();
}

Rooms::~Rooms()
{
}

/*
item** Rooms::getItems()
{
    return roomItems;
}
*/

bool Rooms::getHasEnemy()
{
    return hasEnemy;
}

std::string Rooms::getDescription()
{
    return description;
}

void Rooms::generateRoom()

{
    //srand(time(nullptr));
    //std::random_device rd;
    //std::mt19937 gen(rd());
    //std::uniform_int_distribution<int> distr1(0, 1);

    srand(time(nullptr));

    hasEnemy = rand() % 2;



    if (hasEnemy == true)


        itemCount = rand() % 3 + 1;

    else itemCount = rand() % 3;

    itemCount = 3;
    hasEnemy = false;

    if (itemCount == 0)
        return;

    for (int i = 0; i < itemCount; i++)
    {
        int randIndex = rand() % (allItems.size() - 1);
        roomItems.push_back(allItems[randIndex]);
    }
}

std::string Rooms::descriptionSelector()
{
    std::string filePath = "../descriptions/roomDescriptions";
    if (hasEnemy == true)
        filePath += "/enemyRooms";
    else filePath += "/lootRooms";
    int directorySize = 0;

    //iterates through files in lyrics directory to gauge its size
    for (auto theFile : std::filesystem::directory_iterator(filePath))
        directorySize++;


    std::string* filesInDirectory = new std::string[directorySize];
    int i = 0;

    //iterates again but adds filepath and filenames to a dynamic array
    for (auto theFile : std::filesystem::directory_iterator(filePath))
    {
        filesInDirectory[i] = theFile.path().string();
        i++;
    }

    srand(time(nullptr));
    int randIndex = rand() % directorySize;

    std::string selectedFile = filesInDirectory[randIndex];
    delete[] filesInDirectory;
    filesInDirectory = nullptr;

    return selectedFile;
}

int Rooms::getItemCount()
{
    return itemCount;
}

std::shared_ptr<item> Rooms::getItemAtIndex(int index)
{
    if (index >= itemCount)
        return nullptr;

    return roomItems[index];

}
