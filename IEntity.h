#pragma once
#include "libraries.h"
using namespace sf;

// Запилити фабричний метод для ентіті
class IEntity
{
protected:
	RectangleShape model;

public:

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual RectangleShape getModel()
	{
		return model;
	}

	virtual ~IEntity() {}

};

