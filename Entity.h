#pragma once
#include "libraries.h"
#include "IEntity.h"
using namespace sf;

class Entity: public IEntity
{
public:
	Entity();

	void Draw() override { std::cout << 1; }
	void Update() override {}

	virtual ~Entity();
};

