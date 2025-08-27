#include <fstream>
#include <random>
#include "rooms.h"
#include "./items/allItems.h"
#include <memory>

Rooms::Rooms()

{
    allItems =
        {
      std::make_shared<shinyStone>(), std::make_shared<shinyStone>(), std::make_shared<shinyStone>(), std::make_shared<shinyStone>(),
      std::make_shared<accPotion>(), std::make_shared<accPotion>(), std::make_shared<accPotion>(),
      std::make_shared<hpPotion>(), std::make_shared<hpPotion>(), std::make_shared<hpPotion>(),
      std::make_shared<rasmusStick>(), std::make_shared<rasmusStick>(),
      std::make_shared<bigHpPotion>(), std::make_shared<divineSword>(), std::make_shared<dragonArmor>(), std::make_shared<dungeonMastersSpear>()
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
