//
// Created by Daniel Abu Ramadan on 2025-01-10.
//

#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include "characterCode/goblin.h"
void combat();
float typeRacer(Enemy& enemy,
    int& wordsWritten, int& lettersWritten, int& wrongLetters,
    double& damage, double& accuracyPercent, double& wordsPerMinute);
int wordCount(std::string word);
int lineAccuracy(std::string line1, std::string line2);
std::string lyricSelector();
void printBattle(Enemy enemy, std::string line);

#endif //COMBAT_H
