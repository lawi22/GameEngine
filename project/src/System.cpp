#include "System.h"

namespace GameEngine {

System::System() {

	SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("GameDemo", 10, 10, 1024, 576, 0);
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	musik = Mix_LoadWAV((constants::gResPath + "sounds/bg_music.mp3").c_str());
	hit = Mix_LoadWAV((constants::gResPath + "sounds/hit.mp3").c_str());
	Mix_PlayChannel(-1, musik, -1);
	TTF_Init();
	font = TTF_OpenFont((constants::gResPath + "fonts/font.ttf").c_str(), 50);
		if (!font) 
		{
			std::cerr << "Error: Unable to locate font " << TTF_GetError() << std::endl;
		}	
}

System::~System() {
	Mix_FreeChunk(musik);
	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

void System::playHit() 
{
	Mix_PlayChannel(-1, hit, 0);
}

void System::renderValue(std::string stringValue, int x, int y, int w, int h) 
	{
		SDL_Color color = {255, 255, 255};

		SDL_Surface *textSurface = TTF_RenderText_Solid(font, stringValue.c_str(), color);

		if (!textSurface) 
		{
			std::cerr << "Error: Unable to create surface " << TTF_GetError() << std::endl;
		}	

		SDL_Texture *textTexture = SDL_CreateTextureFromSurface(ren, textSurface);

		if (!textTexture) 
		{
			std::cerr << "Error: Unable to create texture " << TTF_GetError() << std::endl;
		}

		SDL_Rect textPosition = {x, y, w, h};

		SDL_RenderCopy(ren, textTexture, nullptr, &textPosition); 

		SDL_FreeSurface(textSurface);
		SDL_DestroyTexture(textTexture);
	}
System sys;
}
