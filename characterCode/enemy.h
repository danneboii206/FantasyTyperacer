#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <string>


class Enemy : public Character
{
private:
    std::string name;
    std::string descriptionPath;
    std::string artPath; //filepath to txt file
    double damage;
public:
    Enemy(double damage, double maxHealth);
    Enemy();
    virtual ~Enemy();
    void setName(std::string name);
    void setDescriptionPath(std::string descriptionPath);
    void setArtPath(std::string artPath);
    void setDamage(double damage);
    std::string getName();
    std::string getDescriptionPath();
    std::string getArtPath();
    double getDamage() const;
};

#endif //ENEMY_H