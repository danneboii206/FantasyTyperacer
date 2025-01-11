#include <iostream>
#include <string>
#include "menus.h"
#include "combat.h"

#define prt(x) std::cout << x << std::endl

int main()
{
    printMainMenu();

    combat();

    return 0;
}