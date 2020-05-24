#pragma once
#include "libraries.h"
#include "IWindow.h"
using namespace sf;

class IEntity
{
protected:
	RectangleShape model;

public:

	virtual void Init(int s, int r, int g, int b, std::shared_ptr<RenderWindow> &window) = 0;

	virtual RectangleShape getModel()
	{
		return model;
	}

	virtual void update(std::shared_ptr<RenderWindow> &window, Event &event, int collider) = 0;

	virtual void Render(std::shared_ptr<RenderWindow> &window) = 0;

	virtual ~IEntity() {}

};

