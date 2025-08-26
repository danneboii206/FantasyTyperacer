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
/*
    for (int i = 0; i < itemCount; i++)
    {
        std::cout << items[i]->getName() << std::endl;
    }
    */
}

Rooms::~Rooms()
{
    for (int i = 0; i < individualItems; i++)
    {
        itemList[i] = nullptr;
        delete itemList[i];
    }
    delete[] itemList;

    for (int i = 0; i < itemCount; i++)
    {
        items[i] = nullptr;
        delete items[i];
    }
    delete[] items;


}

item** Rooms::getItems()
{
    return itemList;
}

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


        itemCount = rand() % 4 + 1;

    else itemCount = rand() % 3;

    if (itemCount == 0)
        return;

    items = new item*[itemCount]{nullptr};

    for (int i = 0; i < itemCount; i++)
    {
        items[i] = itemList[rand() % (individualItems - 1)];
        //std::cout << items[i]->getName() << std::endl;
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