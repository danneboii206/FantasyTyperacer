#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include "characterCode/goblin.h"
#include "characterCode/Player.h"

int combat(Enemy* enemy, Player& player);
double typeRacer(Enemy& enemy,
    int& wordsWritten, int& lettersWritten, int& wrongLetters,
    double& damage, double& accuracyPercent, double& wordsPerMinute,
    Player& player);
int wordCount(std::string word);
int lineAccuracy(std::string line1, std::string line2);
std::string lyricSelector();
void printBattle(Enemy enemy, std::string line, Player& player);

#endif //COMBAT_H
