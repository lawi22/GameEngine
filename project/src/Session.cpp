#include "Session.h"
#include <SDL2/SDL.h>
#include "Component.h"
#include "System.h"
#include "iostream"
#include <set>
#include "Constants.h"

using namespace std;

namespace GameEngine {
//lokal variabel i session där p1 p2 har ett värde. Dessa mst vara initierade annars startar inte spelet (Engine)

Component* playerOne;
Component* playerTwo;
int playerCount = 0;
bool initialized = false;


#define FPS 60

void Session::add(Component* comp) {
	added.push_back(comp);
}

void Session::remove(Component* comp) {
	removed.push_back(comp);
}

const std::vector<Component*> &Session::getComponents() const {
	return comps;
}

void Session::InitializePlayers(Component* player) 
{

	if (player->getPlayerNumber() ==1) 
	{
		playerOne = player;
		add(player);
		playerCount++;
	}
	if (player->getPlayerNumber() == 2) 
	{
		playerTwo = player;
		add(player);
		playerCount++;
	}
	if (playerCount >= 2) 
	{
		initialized = true;
	}
}

void Session::run() {	
	bool quit = false;

	Uint32 tickInterval = 1000 / FPS;
if (initialized){
	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; break;
			case SDL_KEYDOWN:

		if(gameOn){
			//PLAYER ONE
			if(playerOne){
			if (event.key.keysym.sym == SDLK_c) {
				playerOne->actionKeyDown(event.button.x, event.button.y);
				break;
				
			}
			if (event.key.keysym.sym == SDLK_a) 
			{
				playerOne->leftKey(event.button.x, event.button.y);
				break;
			}
					
			if (event.key.keysym.sym == SDLK_d) 
			{
				playerOne->rightKey(event.button.x, event.button.y);
				break;
			}
			}

			//PLAYER TWO
		if(playerTwo) {
			if (event.key.keysym.sym == SDLK_n) {
				playerTwo->actionKeyDown(event.button.x, event.button.y);
				break;
				
			}
			if (event.key.keysym.sym == SDLK_j) 
			{
				playerTwo->leftKey(event.button.x, event.button.y);
				break;
			}
					
			if (event.key.keysym.sym == SDLK_l) 
			{
				playerTwo->rightKey(event.button.x, event.button.y);
				break;
			}	
			}	
			}	
			} //switch
		} //inre while

		for (Component* c : added){
			comps.push_back(c);
			}
			added.clear();

		for (Component* c : removed) {
			for (vector<Component*>::iterator i = comps.begin(); i != comps.end();)
			{
				if (*i == c) 
				{
					i = comps.erase(i);
					delete c; //Minneshantering
				}
				else {
					i++;
				}
			}
		}
		removed.clear();

		SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		SDL_RenderClear(sys.getRen());
		for (Component* c : comps) 
		{
			c->tick();
			c->draw();
		if(c->isPlayer()) {	
			if (c->getPlayerNumber() ==1){
    			sys.renderValue(to_string(c->getHealth()), c->getRect().x, c->getRect().y-10, 60, 30);
				if (c->getHealth() <= 0) 
				{
					gameOn = false;
					remove(c);
				}
			}
			if(c->getPlayerNumber() == 2){
				sys.renderValue(to_string(c->getHealth()), c->getRect().x, c->getRect().y-10, 60, 30);
				if (c->getHealth() <= 0) 
				{
					gameOn = false;
					remove(c);
				}
			}		
		}
		}

		SDL_RenderPresent(sys.getRen());
		

		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);
	} // yttre while
	}
}
	Session engine; //Nå engine över hela programmet

}
