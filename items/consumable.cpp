#include "consumable.h"

#include <semaphore>

consumable::consumable(std::string itemName)
        : item(itemName, "", 0, 0, 0)
{
    getDataFromName(itemName);
}

consumable::~consumable()
{
}

//gets data from text files using name of object
void consumable::getDataFromName(std::string name)
{
    std::string dir = "../items/Consumables/";
    static const std::unordered_map<std::string, std::string> map = {
        {"Accuracy Potion", "accuracyPotion.txt"},
        {"Big Healing Potion", "bigHealingPotion.txt"},
        {"Healing Potion", "healingPotion.txt"},
        {"Shiny Stone", "shinyStone.txt"}
    };
    auto it = map.find(name)->second;
    dir += it;
    std::ifstream file (dir);
    std::string line;
    int linecount = 0;
    while (getline(file, line))
    {
        linecount++;
        switch (linecount)
        {
        case 2:
            this->description = line;
        break;

        case 3:
            wpmBoost = this->strToWpm(line);
        break;

        case 4:
            accBoost = this->strToAcc(line);
        break;

        case 5:
            hpBoost = this->strToHp(line);
        break;

        case 6:
            duration = this->strToTimeOfEffect(line);
        break;

        case 7:
            instantHeal = this->strToHealAmount(line);
        break;

        }

    }

}

//using maps to avoid magic numbers
int consumable::strToTimeOfEffect(const std::string& str) {
    static const std::unordered_map<std::string, int> map = {
        {"ONE_TIME_USE", 0},
        {"DURATION_ONE_ROUND", 1},
        {"DURATION_TWO_ROUNDS", 2},
        {"DURATION_THREE_ROUNDS", 3}
    };

    auto it = map.find(str);
    if (it != map.end()) return it->second;
    throw std::invalid_argument("Invalid timeOfEffect string: " + str);
}

double consumable::strToHealAmount(const std::string& str) {
    static const std::unordered_map<std::string, double> map = {
        {"NO_HEAL_AMOUNT", 0},
        {"VERY_VERY_LOW_HEAL_AMOUNT", 5},
        {"LOW_HEAL_AMOUNT", 50},
        {"MEDIUM_HEAL_AMOUNT", 100}
    };

    auto it = map.find(str);
    if (it != map.end()) return it->second;
    throw std::invalid_argument("Invalid healAmount string: " + str);
}

std::string consumable::getType() const
{
    return "Consumable";
}

void consumable::roundOver()
{
    --this->duration;
}

int consumable::getDuration() const
{
    return this->duration;
}

double consumable::getInstantHeal() const
{
    return this->instantHeal;
}
