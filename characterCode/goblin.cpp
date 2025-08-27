#include "goblin.h"

Goblin::Goblin()
    : Enemy(10, 100, "Goblin")
{
    setDescriptionPath("../descriptions/enemyDescriptions/goblinDescription.txt");
    setArtPath("../art/enemyPortraits/goblin.txt");
}

Goblin::~Goblin()
{
}
