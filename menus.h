
#ifndef MENUS_H
#define MENUS_H
#include "./characterCode/Player.h"
//#include "roomManager.h"
#define prt(x) std::cout << x << std::endl

//class RoomManager;

class menus
{
    private:
    //RoomManager* theRoomManager;
    bool isNumber(std::string input);

    public:
    menus();
    int printMainMenu();
    int menuInput(int menuChoices);
    void clearScreen();
    void printFile(std::string filePath);
    void openInventory(Player& player);
    void interactWithItem(Player& player, int index);

};

#endif //MENUS_H
