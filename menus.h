//
// Created by Daniel Abu Ramadan on 2025-01-10.
//

#include <string>
#include "./characterCode/Player.h"
#ifndef MENUS_H
#define MENUS_H

int printMainMenu();
int menuInput(int menuChoices);
bool isNumber(std::string input);
void printFile(std::string filePath);
void clearScreen();
void openInventory(Player& player);
void interactWithItem(Player& player, int index);

#endif //MENUS_H
