#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include "combat.h"
#include <filesystem>

#define prt(x) std::cout << x << std::endl
///central method for combat which initiates the combat.
void combat()
{
    int wordsWritten = 0;
    int lettersWritten = 0;
    int wrongLetters = 0;
    double damage = 0;
    double accuracyPercent = 0;
    double wordsPerMinute = 0;
    bool typing = true;
    std::string line;
    std::string input;
    std::fstream lyrics("../lyrics/lyrics1.txt");
    std::chrono::duration<double> totalTime;
    auto initialTime = std::chrono::system_clock::now();
    auto currentTime = std::chrono::system_clock::now();

    while (getline(lyrics, line))
    {
        prt(line);
        getline(std::cin, input);
        wrongLetters += lineAccuracy(line, input);
        currentTime = std::chrono::system_clock::now();
        totalTime = currentTime - initialTime;
        wordsWritten += wordCount(input);
        lettersWritten += line.length();
    }

    accuracyPercent = (lettersWritten - wrongLetters) / static_cast<double>(wrongLetters);
    wordsPerMinute = wordsWritten / (totalTime.count() / 60);
    damage = wordsPerMinute * accuracyPercent;

    //prints just for testing purposes
    prt("total time: " << totalTime.count());
    prt("words written: " << wordsWritten);
    prt("wpm: " << wordsPerMinute);
    prt("letters written: " << lettersWritten);
    prt("wrong letters: " << wrongLetters);
    //prevents divide by zero

    prt("accuracy: " << accuracyPercent * 100 << "%");

    prt("damage: " << damage);

}

/// inputs string returns word count of string
int wordCount(std::string word)
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

///returns random .txt file from lyrics directory
std::string lyricSelector()
{
    std::string filePath = "../lyrics";
    int directorySize = 0;

    //iterates through files in lyrics directory to gauge its' size
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

    srand((unsigned int)time(NULL));
    int randIndex = rand() % (directorySize);

    std::string selectedFile = filesInDirectory[randIndex];
    delete[] filesInDirectory;
    return selectedFile;
}

///input two lines, each letter of line2 is compared against line1
///returns the number of incorrect letters
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