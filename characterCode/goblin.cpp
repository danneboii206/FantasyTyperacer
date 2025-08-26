//
// Created by rasmu on 2025-02-22.
//

#include "goblin.h"

Goblin::Goblin()
{
    setName("Goblin");
    setDescription("../descriptions/enemyDescriptions/goblinDescription.txt");
    setArt("../art/enemyPortraits/goblin.txt");
    setDamage(10);
    setMaxHealth(100);
    setHealth(100);
}

Goblin::~Goblin()
{
}
