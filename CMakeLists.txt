cmake_minimum_required(VERSION 3.30)
project(FantasyTyperacer)

set(CMAKE_CXX_STANDARD 20)



add_executable(FantasyTyperacer main.cpp combat.cpp menus.cpp rooms.cpp
        characterCode/character.cpp
        characterCode/character.h
        characterCode/enemy.cpp
        characterCode/enemy.h
        characterCode/goblin.cpp
        characterCode/goblin.h
        characterCode/skeleton.cpp
        characterCode/skeleton.h)
