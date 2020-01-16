#pragma once
#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene(Game* owner) : Scene(owner) { initialize(); }
	virtual void initialize();
};

