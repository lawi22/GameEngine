#include "Ship.h"
#include "Bullet.h"
#include "System.h"
#include "Session.h"

using namespace std;
using namespace GameEngine;

Ship::Ship() : Component(0, 0, 0, 0) //Defaultkonstruktor
{
    changePlayerNumber(0);
}

Ship::Ship(int n, int xPos, int yPos, int wSize, int hSize) : Component(xPos, yPos, wSize, hSize) {

    changePlayerNumber(n);

}

Ship::Ship(std::string file, int n, int xPos, int yPos, int wSize, int hSize) : Component(file, xPos, yPos, wSize, hSize) {

    changePlayerNumber(n);
    if (n == 1) 
    {
        bulletFile = "images/bullet.png";
    }
    if (n == 2) 
    {
        bulletFile = "images/bullet_player2.png";
    }
}
void Ship::tick() {

        counter++;
		if (rect.x <= 0)
        {
            rect.x +=movementSpeed;
        }
		else if (rect.x >= 924) 
        {
            rect.x -= movementSpeed;
        }
         onCollisionDamage(); 
	}

void Ship::leftKey(int x, int y) {
    rect.x -= movementSpeed;
}

void Ship::rightKey(int x, int y) {
    rect.x += movementSpeed;
}

void Ship::actionKeyDown(int x, int y) {
    Bullet* b = Bullet::getInstance(bulletFile, rect.x + 28, rect.y, getPlayerNumber());
    engine.add(b);
}

void Ship::spaceKeyUp(int x, int y) {

}

void Ship::decreaseHealth() {
    health--;
}

int Ship::getHealth() {
    return health;
}

void Ship::onCollisionDamage() 
	{
		for (Component* c : engine.getComponents()) 
		{
			if (dynamic_cast<Bullet*>(c) != nullptr && c->getPlayerNumber() != getPlayerNumber()) 
			{
				if (checkCollision(c)) 
				{
					decreaseHealth();
                    sys.playHit();
                    engine.remove(c);
				}
			}
		}
	}