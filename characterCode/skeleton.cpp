//
// Created by rasmu on 2025-03-23.
//

#include "skeleton.h"
Skeleton::Skeleton()
{
    setName("Skeleton");
    setDescription("../descriptions/enemyDescriptions/skeletonDescription.txt");
    setArt("../art/enemyPortraits/skeleton.txt");
    setDamage(20);
    setMaxHealth(50);
    setHealth(50);
}

Skeleton::~Skeleton()
{

}
