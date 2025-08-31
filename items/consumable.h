#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "item.h"
#include <string>




class consumable : public item
{
    int duration; //how many enemy rounds
    double instantHeal;
public:
    consumable() = delete;
    explicit consumable(std::string itemName);
    ~consumable() override;
    void getDataFromName(std::string name) override ;
    int strToTimeOfEffect(const std::string& str);
    double strToHealAmount(const std::string& str);
    std::string getType() const override;
    void roundOver();
    int getDuration() const;
    double getInstantHeal() const;
};



#endif //CONSUMABLE_H
