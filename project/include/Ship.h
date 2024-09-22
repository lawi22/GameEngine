#ifndef SHIP_H
#define SHIP_H

#include "Component.h"


using namespace GameEngine;

class Ship : public Component {
public:
    Ship();
    Ship(int n, int x, int y, int w, int h);
    Ship(std::string file, int n, int x, int y, int w, int h);
    bool isPlayer() override {return true;}
    int getHealth() override;
    void decreaseHealth();
    void tick() override;
    void leftKey(int x, int y) override;
    void rightKey(int x, int y) override;
    void actionKeyDown(int x, int y) override;
    void spaceKeyUp(int x, int y) override;
    void onCollisionDamage();


private:
    static const int movementSpeed = 50;
    int counter;
    int health = 10;
    std::string bulletFile;
};



#endif