#include <iostream>
#include <string>
#include "menus.h"
#include "combat.h"
#include "./characterCode/goblin.h"

#define prt(x) std::cout << x << std::endl

int main()
{
    //printMainMenu();

    combat();

    Goblin goblin;

    return 0;
}

