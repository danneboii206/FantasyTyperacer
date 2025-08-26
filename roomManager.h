//
// Created by rasmu on 2025-08-26.
//

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "rooms.h"
#include "combat.h"
#include "menus.h"
void roomManager();
void roomPrint(Rooms room);
int roomInput(Rooms room);
int triggerEvent(Rooms room);
int finishRoom(Rooms room);
#endif //ROOMMANAGER_H
