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
void roomInput(Rooms room);
void triggerEvent(Rooms room);
void finishRoom(Rooms room);
#endif //ROOMMANAGER_H
