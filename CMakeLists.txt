cmake_minimum_required(VERSION 3.30)
project(FantasyTyperacer)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        combat.cpp
        menus.cpp
        rooms.cpp
)

add_executable(FantasyTyperacer ${SOURCES})
