#include "Constants.h" //gResPath-contains path to your resources.
#include <SDL2/SDL.h>
#include "Session.h"
#include "Bullet.h"
#include "Ship.h"
#include "Background.h"
#include <SDL2/SDL_image.h>
#include "System.h"
#include <string>
#include "iostream"

using namespace GameEngine;

int main(int argc, char** argv) {

	//Skapar en bakgrund med angivet filnamn
	Background* background = new Background("images/bg.png");
    engine.add(background);

	//Skapar två spelare
	Ship* playerOne = new Ship("images/ship.png", 1, 300, 400, 100, 100);
	Ship* playerTwo = new Ship("images/ship2.png", 2, 300, 50, 100, 100);

	//Initialiserar spelarna i spelet
	engine.InitializePlayers(playerOne);
	engine.InitializePlayers(playerTwo);

	//Startar spelet. OBS! Kan endast göras när minst två spelare initialiserats.
	engine.run();
	
	return 0;


}
