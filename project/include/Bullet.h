#ifndef BULLET_H
#define BULLET_H

#include "Component.h" 

using namespace GameEngine;

class Bullet : public Component {
public:
    static Bullet* getInstance(std::string file, int x, int y, int playerNumber);
    void tick() override;
    void leftKey(int x, int y) override{}
    void rightKey(int x, int y)override{}
    void actionKeyDown(int x, int y)override{}
    void spaceKeyUp(int x, int y)override{}
private:
    Bullet(std::string file, int x, int y, int playerNumber);
    int counter;
};

#endif