#include "item.h"

item::item()    : itemName(""), description("description"),
                    wpmBoost(0), accBoost(0), hpBoost(0)
{

}

item::item(std::string itemName, std::string description,
      std::string wpmBoost, std::string accBoost, std::string hpBoost)
    : itemName(itemName), description(description)
{
    this->wpmBoost = strToWpm(wpmBoost);
    this->accBoost = strToAcc(accBoost);
    this->hpBoost = strToHp(hpBoost);
}

item::~item()
{
}


int item::strToWpm(const std::string& wpm) {
    static const std::unordered_map<std::string, int> map = {
        {"NO_WPM_BOOST", 0},
        {"LOW_WPM_BOOST", 5},
        {"MEDIUM_WPM_BOOST", 10},
        {"HIGH_WPM_BOOST", 20},
        {"MAX_WPM_BOOST", 40}
    };
    auto it = map.find(wpm);
    if (it != map.end()) return it->second;
    throw std::invalid_argument("Invalid WPM string: " + wpm);
}

int item::strToAcc(const std::string& acc) {
    static const std::unordered_map<std::string, int> map = {
        {"NO_ACC_BOOST", 0},
        {"LOW_ACC_BOOST", 5},
        {"MEDIUM_ACC_BOOST", 10},
        {"HIGH_ACC_BOOST", 15},
        {"MAX_ACC_BOOST", 20}
    };
    auto it = map.find(acc);
    if (it != map.end()) return it->second;
    throw std::invalid_argument("Invalid ACC string: " + acc);
}

int item::strToHp(const std::string& hp) {
    static const std::unordered_map<std::string, int> map = {
        {"NO_HP_BOOST", 0},
        {"LOW_HP_BOOST", 50},
        {"MEDIUM_HP_BOOST", 75},
        {"HIGH_HP_BOOST", 150},
        {"MAX_HP_BOOST", 220}
    };
    auto it = map.find(hp);
    if (it != map.end()) return it->second;
    throw std::invalid_argument("Invalid HP string: " + hp);
}


std::string item::getDescription() const
{
    return this->description;
}

std::string item::getName() const
{
    return this->itemName;
}

std::string item::getType() const
{
}

double item::getWpmBoost() const
{
    return this->wpmBoost;
}

double item::getAccuracyBoost() const
{
    return this->accBoost;
}

double item::getHpBoost() const
{
    return this->hpBoost;
}
