cmake_minimum_required(VERSION 3.30)
project(FantasyTyperacer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")



add_executable(FantasyTyperacer main.cpp combat.cpp menus.cpp Rooms.cpp
        characterCode/character.cpp
        characterCode/enemy.cpp
        characterCode/goblin.cpp
        characterCode/skeleton.cpp
        characterCode/skeleton.h
        characterCode/Player.cpp
        characterCode/Player.h
        items/item.cpp
        items/hpPotion.cpp
        items/shinyStone.cpp
        items/divineSword.cpp
        items/dragonArmor.cpp
        items/bigHpPotion.cpp
        items/dungeonMastersSpear.cpp
        items/weapon.cpp
        items/consumable.cpp
        items/armor.cpp
        items/rasmusStick.cpp
        items/accPotion.cpp
        RoomManager.cpp
        RoomManager.h
        characterCode/dragon.cpp
        characterCode/dragon.h
)
