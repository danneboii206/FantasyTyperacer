#include "menus.h"
#include "rooms.h"
#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

int main()
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Rooms room = Rooms();

    while (true)
    {
        if (printMainMenu() == -5)
        {
            return 0;
        }
    }
}

