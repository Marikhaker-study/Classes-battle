#pragma once
#include "libraries.h"
using namespace sf;

class IWindow
{
protected:

public:

	virtual std::shared_ptr<RenderWindow> &get_window() = 0;

	virtual void configurate(int width, int height, char *name) = 0;

	virtual ~IWindow() {}
};

