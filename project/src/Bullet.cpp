#include "Session.h"
#include "Bullet.h"
#include "System.h"

using namespace GameEngine;

	Bullet* Bullet::getInstance(std::string file, int x, int y, int playerNumber) {
		return new Bullet(file, x, y, playerNumber);
	}

	Bullet::Bullet(std::string file, int x, int y, int pNumber) : Component(file, x, y, 40,40){

		changePlayerNumber(pNumber);
	}

	void Bullet::tick() {
	
	if (getPlayerNumber() == 1) {
		counter++;
		if (rect.y <= 0)
			engine.remove(this);
		else if (counter % 1 == 0) //MOVEMENT FOR BULLET
			rect.y -= 6;
	}
	if (getPlayerNumber() == 2) {
		counter++;
		if (rect.y <= 0)
			engine.remove(this);
		else if (counter % 1 == 0) //MOVEMENT FOR BULLET
			rect.y += 6;
	}
	}


