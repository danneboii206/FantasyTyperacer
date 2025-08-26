//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "hpPotion.h"

hpPotion::hpPotion()
    : consumable("Healing Potion", "Heals you 50 HP",
        NO_WPM_BOOST, NO_ACC_BOOST, NO_HP_BOOST, ONE_TIME_USE, LOW_HEAL_AMOUNT)
{
}

hpPotion::~hpPotion()
{
}
