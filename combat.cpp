#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "combat.h"
#define prt(x) std::cout << x << std::endl

void combat()
{
    float baseDamage = 0;
    float totalDamage = 0;
    int wordsWritten = 0;
    int wrongLetters = 0;
    bool typing = true;
    std::string line;
    std::string input;
    std::fstream lyrics("lyrics1.txt");
    std::chrono::duration<double> totalTime;
    auto initialTime = std::chrono::system_clock::now();
    int wordCount;
    auto currentTime = std::chrono::system_clock::now();

    while (getline(lyrics, line))
    {
        prt(line);
        getline(std::cin, input);
        wrongLetters += lineAccuracy(line, input);
        currentTime = std::chrono::system_clock::now();
        totalTime = currentTime - initialTime;
    }

    prt(totalTime.count());
}

int wordCount(std::string word)
{
    int words = 0;
    char lastChar = ' ';

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] != ' ' && lastChar == ' ')
            words++;

        lastChar = word[i];
    }

    return words;
}


int lineAccuracy(std::string line1, std::string line2)
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