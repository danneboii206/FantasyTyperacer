//
// Created by Daniel Abu Ramadan on 2025-08-25.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <string>

enum timeOfEffect
{
    ONE_TIME_USE = 0,
    DURATION_ONE_ROUND = 1,
    DURATION_TWO_ROUNDS = 2,
    DURATION_THREE_ROUNDS = 3
};

enum healAmount
{
    NO_HEAL_AMOUNT = 0,
    VERY_VERY_LOW_HEAL_AMOUNT = 5,
    LOW_HEAL_AMOUNT = 50,
    MEDIUM_HEAL_AMOUNT = 100
};

class consumable : public item
{
    int duration; //how many enemy rounds
    double instantHeal;
public:
    consumable() = delete;
    consumable(std::string itemName, std::string description, double wpmBoost,
               double accBoost, double hpBoost, int duration, double instantHeal, std::string type = "consumable");
    ~consumable() override;
    void roundOver();
    int getDuration() const;
    double getInstantHeal() const;
};



#endif //CONSUMABLE_H
