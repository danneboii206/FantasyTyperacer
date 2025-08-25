//
// Created by rasmu on 2025-08-24.
//
#include "Player.h"
#include <iostream>
Player::Player()
{
    this->inventory = new item*[inventorySize]{nullptr};
    this->consumedPotions = new item*[inventorySize]{nullptr};
    loadPlayerData();
}

void Player::savePlayerData()
{
    std::string maxHp = std::to_string(this->getMaxHealth());
    std::string Hp = std::to_string(this->getHealth());

    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << maxHp << std::endl;
    saveFile << Hp << std::endl;

    saveFile.close();
}

void Player::loadPlayerData()
{
    std::ifstream saveFile(this->filepath + "/PlayerData.txt");
    std::string line;

    int i = 0;
    while (std::getline(saveFile, line))
    {
        i++;
        switch (i)
        {
            case 1:
                setMaxHealth(std::stoi(line));
                break;
            case 2:
                setHealth(std::stoi(line));
        }
    }

}

void Player::resetPlayerData()
{
    std::ofstream saveFile(this->filepath + "/PlayerData.txt");
    saveFile << 200 << std::endl;
    saveFile << 200 << std::endl;

    saveFile.close();
}

Player::~Player()
{
    std::cout<<"destroying player"; //for testing purposes
}
