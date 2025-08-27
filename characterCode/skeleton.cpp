#include "skeleton.h"

Skeleton::Skeleton()
{
    setName("Skeleton");
    setDescriptionPath("../descriptions/enemyDescriptions/skeletonDescription.txt");
    setArtPath("../art/enemyPortraits/skeleton.txt");
    setDamage(20);
    setMaxHealth(50);
    setHealth(50);
}

Skeleton::~Skeleton()
{

}
