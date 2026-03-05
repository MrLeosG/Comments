#ifndef HITPOINTS_H
#define HITPOINTS_H

class Hitpoints {
public:
    Hitpoints(int initial);
    void takeDamage(int amount);
    int getCurrent() const;
private:
    int currentHitpoints;
};

#endif // HITPOINTS_H
