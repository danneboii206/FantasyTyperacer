#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "combat.h"
#include "menus.h"
#include <filesystem>
#include "characterCode/Player.h"

#define prt(x) std::cout << x << std::endl

Combat::Combat()
{
    menu = menus();
}


///central method for combat which initiates the combat.
int Combat::combat(Enemy* enemy, Player& player)
{
    int wordsWritten = 0;
    int lettersWritten = 0;
    int wrongLetters = 0;
    double damage = 0;
    double accuracyPercent = 0;
    double wordsPerMinute = 0;

    bool inCombat = true;
    while(inCombat == true)
    {
        menu.printFile(enemy->getArtPath());
        std::cout << enemy->getName() << ": " << enemy->getHealth() << "/" << enemy->getMaxHealth() << " hp" << std::endl;
        menu.printFile(enemy->getDescriptionPath());
        prt("Would you like to:");
        prt("1: Attack");
        prt("2: Use item");

        int input = menu.menuInput(2);

        if (input == 1)
        {
            typeRacer(*enemy, wordsWritten, lettersWritten, wrongLetters, damage, accuracyPercent, wordsPerMinute, player);
        }

        if (input == 2)
        {
            menu.openInventory(player);
            continue;
        }

        if (enemy->getHealth() <= 0)
        {
            inCombat = false;
        }

        if (player.getHealth() <= 0)
            return 0;

        player.takeDamage(enemy->getDamage());
    }


    player.potionCheckValidity();
    return 1;
}


double Combat::typeRacer(Enemy& enemy,
    int& wordsWritten, int& lettersWritten, int& wrongLetters,
    double& damage, double& accuracyPercent, double& wordsPerMinute,
    Player& player)
{
    std::string line;
    std::string input;
    std::fstream lyrics(lyricSelector());
    std::chrono::duration<double> totalTime;
    auto initialTime = std::chrono::system_clock::now();
    auto currentTime = std::chrono::system_clock::now();
    while (getline(lyrics, line))
    {
        printBattle(enemy, line, player);
        getline(std::cin, input);
        wrongLetters += lineAccuracy(line, input);
        currentTime = std::chrono::system_clock::now();
        totalTime = currentTime - initialTime;
        wordsWritten += wordCount(input);
        lettersWritten += line.length();
    }
    lyrics.clear();
    lyrics.seekg(0, std::ios::beg);
    accuracyPercent = 1 - (static_cast<double>(wrongLetters) / lettersWritten);

    wordsPerMinute = wordsWritten / (totalTime.count() / 60 ) + player.getWpmBoost();
    double multiplier = (accuracyPercent * 2 + player.getAccBoost()); //multiplied by 2 so it feels more rewarding to have good accuracy
    damage = wordsPerMinute * multiplier;
    enemy.takeDamage(damage);

    return enemy,
    wordsWritten, lettersWritten, wrongLetters,
    damage, accuracyPercent, wordsPerMinute;
}

/// inputs string returns word count of string
int Combat::wordCount(std::string word)
{
    int words = 0;
    char lastChar = ' ';
    //checks for non-space char after last char was space this prevents
    //multiple words being registered if multiple spaces are written repeatedly
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != ' ' && lastChar == ' ')
            words++;

        lastChar = word[i];
    }

    return words;
}

///returns name of random .txt file from lyrics directory
std::string Combat::lyricSelector()
{
    std::string filePath = "../lyrics";
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

///input two lines, each letter of line2 is compared against line1
///returns the number of incorrect letters
int Combat::lineAccuracy(std::string line1, std::string line2)
{
    int incorrectLetters = 0;

    for (int i = 0; i < line1.length(); i++)
    {
        if (i < line2.length())
        {
            if (line2[i] != line1[i])
                incorrectLetters++;
        }

        else
        {

            if (line2.length() >= line1.length())
                incorrectLetters += line2.length() - line1.length();

            else
            {
                incorrectLetters += line1.length() - line2.length();
            }
            break;
        }

    }

    return incorrectLetters;
}

void Combat::printOptions(Player & player)
{
    menu.clearScreen();
    prt("would you like to use an item)");
    player.printItems();
}

void Combat::printBattle(Enemy enemy, std::string line, Player& player)
{
    menu.clearScreen();
    menu.printFile(enemy.getArtPath());
    std::cout << enemy.getName() << ": " << enemy.getHealth() << "/" << enemy.getMaxHealth() << " hp" << std::endl;
    //printFile(enemy.getDescriptionPath());
    prt("player hp: " << player.getHealth());
    prt("type the following line to attack:");
    prt(line);
}



