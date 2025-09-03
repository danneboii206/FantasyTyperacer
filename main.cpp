#include "roomManager.h"

int main()
{
    RoomManager roomManager = RoomManager();
    while (true)
    {
        if (roomManager.printMainMenu() == -5)
        {
            return 0;
        }
    }
}

