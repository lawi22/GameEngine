#ifndef SYSTEM_H
#define SYSTEM_H

#include "Constants.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

namespace GameEngine {
class System
{
public:
	System();
	~System();
	void renderValue(std::string stringValue, int x, int y, int w, int h);
	void renderValue(int intValue, int x, int y, int w, int h);
	void playHit();
	SDL_Window* getWin() {return win;}
	SDL_Renderer* getRen() {return ren;}

private:

	SDL_Window* win;
	SDL_Renderer* ren;
	TTF_Font* font;
	Mix_Chunk* musik;
	Mix_Chunk* hit;
};
extern System sys; //Nå system i programmet
}
#endif
