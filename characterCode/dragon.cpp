//
// Created by rasmu on 2025-08-26.
//

#include "dragon.h"

Dragon::Dragon()
{
    setName("Dragon");
    setDescription("../descriptions/enemyDescriptions/dragonDescription.txt");
    setArt("../art/enemyPortraits/dragon.txt");
    setDamage(30);
    setMaxHealth(200);
    setHealth(200);
}