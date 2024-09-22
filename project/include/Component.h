#ifndef COMPONENT_H
#define COMPONENT_H

#include "Session.h"

namespace GameEngine {
class Component
{
public:
	virtual void mouseDown(int x, int y) {}
	virtual void mouseUp(int x, int y) {}
	virtual void leftKey(int x, int y) {}
	virtual void rightKey(int x, int y) {}
	virtual void actionKeyDown(int x, int y){}
	virtual void spaceKeyUp(int x, int y){}
	virtual void draw() const;
	virtual int getHealth(){return 0;}
	virtual bool isPlayer(){return false;}
	SDL_Rect getRect() const { return rect; }
	SDL_Texture* getTexture() const {return texture;}
	void changeTexture(SDL_Texture* t) {texture = t;}
	int getPlayerNumber() {return playerNumber;}
	void changePlayerNumber(int n) {playerNumber = n;}
	virtual void tick(){}
	bool checkCollision(Component* other);
	virtual ~Component(){SDL_DestroyTexture(texture);};
	
protected:
	Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	Component(std::string file, int x, int y, int w, int h);
	SDL_Rect rect;

private:
	int playerNumber;
	SDL_Texture* texture;
	Component operator=(const Component &other) const = delete;
	Component(const Component &) = delete;
};
}
#endif
