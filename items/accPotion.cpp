//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#include "accPotion.h"

accPotion::accPotion()
    : consumable("Accuracy Potion", "Increases accuracy by +10% for one round",
        NO_WPM_BOOST, MEDIUM_ACC_BOOST, NO_HP_BOOST, DURATION_ONE_ROUND, NO_HEAL_AMOUNT)
{
}

accPotion::~accPotion()
{
}
