#include "bigHpPotion.h"

bigHpPotion::bigHpPotion()
    : consumable("Big Healing Potion", "Heals 100 HP",
                 NO_WPM_BOOST, NO_ACC_BOOST, NO_HP_BOOST, ONE_TIME_USE, MEDIUM_HEAL_AMOUNT)
{
}

bigHpPotion::~bigHpPotion()
{
}
