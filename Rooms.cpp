#include <fstream>
#include <random>
#include "rooms.h"
#include "items/item.h"
#include "items/consumable.h"
#include "items/Equippable.h"
#include <memory>
#include <filesystem>

Rooms::Rooms()

{
    //item pool of room
    allItems =
        {
      std::make_shared<consumable>("Shiny Stone"), std::make_shared<consumable>("Shiny Stone"),
        std::make_shared<consumable>("Shiny Stone"), std::make_shared<consumable>("Shiny Stone"),
      std::make_shared<consumable>("Accuracy Potion"), std::make_shared<consumable>("Accuracy Potion"),
        std::make_shared<consumable>("Accuracy Potion"), std::make_shared<consumable>("Healing Potion"),
        std::make_shared<consumable>("Healing Potion"), std::make_shared<consumable>("Healing Potion"),
      std::make_shared<Equippable>("Rasmus' stick"), std::make_shared<Equippable>("Rasmus' stick"),
      std::make_shared<consumable>("Big Healing Potion"), std::make_shared<Equippable>("Divine Sword"),
        std::make_shared<Equippable>("Dragon Armor"), std::make_shared<Equippable>("Dungeon Masters Spear")
        };

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

bool Rooms::getHasEnemy() const
{
    return hasEnemy;
}

std::string Rooms::getDescription() const
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

    //itemCount = 3;
    //hasEnemy = false;

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

int Rooms::getItemCount() const
{
    return itemCount;
}

std::shared_ptr<item> Rooms::getItemAtIndex(int index) const
{
    if (index >= itemCount)
        return nullptr;

    return roomItems[index];

}
