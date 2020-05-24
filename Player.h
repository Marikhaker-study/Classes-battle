#pragma once
#include "IEntity.h"

enum class Gdirection
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

class Player :
	public IEntity
{

private:

	// model ref
	RectangleShape model;

	//Step size == size
	int size;

public:

	Player();
	
	// size, r, g, b, window
	void Init(int s, int r, int g, int b, std::shared_ptr<RenderWindow> &window) override;

	void move(Gdirection way, std::shared_ptr<RenderWindow> &window);

	// collider == 1 -> death; collider == 1 -> win 
	virtual void update(std::shared_ptr<RenderWindow> &window, Event &event, int collider) override;

	void Render(std::shared_ptr<RenderWindow> &window) override;

	virtual ~Player();

};

