//
// Created by rasmu on 2025-02-10.
//

#ifndef CHARACTER_H
#define CHARACTER_H
class Character
{
private:
    float health;
    float maxHealth;

public:
    explicit Character(float maxHealth);
    Character();
    void takeDamage(float damage);
    void setHealth(float health);
    void setMaxHealth(float health);
    virtual float getHealth() const;
    virtual float getMaxHealth() const;
};
#endif //CHARACTER_H
