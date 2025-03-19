//
// Created by rasmu on 2025-02-21.
//

#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <string>


class Enemy : public Character
{
private:
    std::string name;
    std::string description;
    std::string art; //filepath to txt file
    float damage;

public:
    explicit Enemy(float damage, float maxHealth);
    Enemy();
    void setName(std::string name);
    void setDescription(std::string description);
    void setArt(std::string art);
    void setDamage(float damage);
    std::string getName();
    std::string getDescription();
    std::string getArt();
    int getDamage() const;
};

#endif //ENEMY_H