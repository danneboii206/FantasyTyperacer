#include "skeleton.h"

Skeleton::Skeleton()
    : Enemy(20, 50, "Skeleton")
{
    setName("Skeleton");
    setDescriptionPath("../descriptions/enemyDescriptions/skeletonDescription.txt");
    setArtPath("../art/enemyPortraits/skeleton.txt");
}

Skeleton::~Skeleton()
{

}
