//
// Created by Daniel Abu Ramadan on 2025-01-10.
//

#include "rooms.h"
#include <iostream>
#include <fstream>

Rooms::Rooms()
{
    generateRoom();
    description = descriptionSelector();
}

void Rooms::generateRoom()
{
    srand(time(nullptr));

    hasEnemy = rand() % 1;

    if (hasEnemy == true)
        itemCount = rand() % 3 + 1;

    else itemCount = rand() % 2;

    items = new item*[itemCount];

    for (int i = 0; i < itemCount; i++)
    {

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

    return selectedFile;
}