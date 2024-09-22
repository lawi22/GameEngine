#include "Component.h"
#include "iostream"

namespace GameEngine {

Component::Component(std::string file, int x, int y, int w, int h)
{
    rect = { x,y,w,h };
    texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + file).c_str());
}

void Component::draw() const
{
    SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
}

bool Component::checkCollision(Component* other){
    const SDL_Rect& rect1 = getRect();
    const SDL_Rect& rect2 = other->getRect();
    if(  SDL_HasIntersection(&rect1, &rect2) == SDL_TRUE)
        {
            return true;
        }
    return false;
}
}