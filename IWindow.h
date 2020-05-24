#pragma once
#include "libraries.h"
using namespace sf;

class IWindow
{
private:

public:

	virtual std::shared_ptr<RenderWindow> &get_GameWindow() = 0;

	virtual void configurate(int width, int height, char *name) = 0;

	virtual ~IWindow() {}
};

