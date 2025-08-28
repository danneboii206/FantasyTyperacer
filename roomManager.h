#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "rooms.h"
#include "menus.h"

void roomManager(Player& player);
void roomPrint(Rooms room);
int roomInput(Rooms room, Player& player);
int triggerEvent(Rooms room, Player& player);
int finishRoom(Rooms room, Player& player);
#endif //ROOMMANAGER_H
