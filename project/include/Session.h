#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "System.h"

namespace GameEngine {

class Component;

class Session
{
public:
	void add(Component* comp);
	void remove(Component* comp);
	void InitializePlayers(Component* player);
	void run();
	void GameOver(Component* player);
	const std::vector<Component*>& getComponents() const;

private:
	std::vector<Component*> comps;
	std::vector<Component*> added, removed;
	bool gameOn = true;
};
	extern Session engine;
}
#endif