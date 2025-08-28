#include "dragon.h"

Dragon::Dragon()
    : Enemy(50, 200, "Dragon")
{
    setName("Dragon");
    setDescriptionPath("../descriptions/enemyDescriptions/dragonDescription.txt");
    setArtPath("../art/enemyPortraits/dragon.txt");
}

Dragon::~Dragon()
{
}
