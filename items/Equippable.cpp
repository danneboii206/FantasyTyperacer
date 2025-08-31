#include "Equippable.h"


Equippable::Equippable(std::string itemName)
        : item(itemName, "", "", "", ""), type(""), isEquipped(false)
{
    getDataFromName(itemName);
}

Equippable::~Equippable()
{
}

void Equippable::getDataFromName(std::string name)
{
    std::string dir = "consumables/";
    static const std::unordered_map<std::string, std::string> map = {
        {"Divine Sword", "divineSword.txt"},
        {"Dragon Armor", "dragonArmor.txt"},
        {"Dungeon Masters Spear", "dungeonMastersSpear.txt"},
        {"Rasmus' stick", "rasmusStick.txt"}
    };
    auto it = map.find(name);
    dir += name;
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
                this->wpmBoost = this->strToWpm(line);
            break;

            case 4:
                accBoost = this->strToAcc(line);
            break;

            case 5:
                hpBoost = this->strToHp(line);
            break;
            case 6:
                type = line;
            break;


        }

    }
}



std::string Equippable::getType() const
{
    return this->type;
}

bool Equippable::getIsEquipped() const
{
    return this->isEquipped;
}

void Equippable::setIsEquipped(bool isEquipped)
{
    this->isEquipped = isEquipped;
}
