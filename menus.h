#include "./characterCode/Player.h"
#ifndef MENUS_H
#define MENUS_H

void printMainMenu();
int menuInput(int menuChoices);
bool isNumber(std::string input);
void printFile(std::string filePath);
void clearScreen();
void openInventory(Player& player);
void interactWithItem(Player& player, int index);

#endif //MENUS_H
