#include "dragon.h"

Dragon::Dragon()
{
    setName("Dragon");
    setDescriptionPath("../descriptions/enemyDescriptions/dragonDescription.txt");
    setArtPath("../art/enemyPortraits/dragon.txt");
    setDamage(30);
    setMaxHealth(200);
    setHealth(200);
}

Dragon::~Dragon()
{
}
