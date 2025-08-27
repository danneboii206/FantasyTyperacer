#include "goblin.h"

Goblin::Goblin()
{
    setName("Goblin");
    setDescriptionPath("../descriptions/enemyDescriptions/goblinDescription.txt");
    setArtPath("../art/enemyPortraits/goblin.txt");
    setDamage(10);
    setMaxHealth(100);
    setHealth(100);
}

Goblin::~Goblin()
{
}
