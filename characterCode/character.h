#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
private:
    double health;
    double maxHealth;

public:
    Character(double maxHealth);
    Character();
    virtual ~Character();
    void takeDamage(double damage);
    void setHealth(double health);
    void setMaxHealth(double health);
    virtual double getHealth() const;
    virtual double getMaxHealth() const;
};
#endif //CHARACTER_H
