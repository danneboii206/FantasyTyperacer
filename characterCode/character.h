#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
private:
    double health;
    double maxHealth;
public:
    Character(double maxHealth);
    Character() = delete;
    virtual ~Character();
    void takeDamage(double damage);
    void setHealth(double health);
    void setMaxHealth(double health);
    double getHealth() const;
    double getMaxHealth() const;
    virtual void setName(std::string name) = 0;
};
#endif //CHARACTER_H
