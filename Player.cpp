#include "Player.h"



Player::Player()
{
}

// size, r, g, b, window
void Player::Init(int s, int r, int g, int b, std::shared_ptr<RenderWindow> &window)
{
	this->size = s;
	model.setSize(Vector2f(size, size));

	model.move(size, size);
	model.setFillColor(Color(r, g, b));
}

void Player::move(Gdirection way, std::shared_ptr<RenderWindow> &window)
{

	switch (way)
	{
	case Gdirection::UP:
		if (model.getPosition().y >= size) model.move(0, -size);

		else model.setPosition(model.getPosition().x, window->getSize().y - size); break;

	case Gdirection::DOWN:

		if (model.getPosition().y <= window->getSize().y - size * 2) model.move(0, size);

		else model.setPosition(model.getPosition().x, 0); break;

	case Gdirection::LEFT:

		if (model.getPosition().x >= size) model.move(-size, 0);

		else model.setPosition(window->getSize().x - size, model.getPosition().y); break;

	case Gdirection::RIGHT:

		if (model.getPosition().x <= window->getSize().x - size * 2) model.move(size, 0);

		else model.setPosition(0, model.getPosition().y); break;

	}
}

// collider == 1 -> death; collider == 1 -> win 
void Player::update(std::shared_ptr<RenderWindow> &window, Event &event, int collider)
{

	// handling live key actions
	// for smooth movement
	/*	if (Keyboard::isKeyPressed(Keyboard::W))
	{
	move(Gdirection::UP, window, deltatime);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
	move(Gdirection::DOWN, window, deltatime);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
	move(Gdirection::LEFT, window, deltatime);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
	move(Gdirection::RIGHT, window, deltatime);
	}*/

	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == Keyboard::W)
		{
			move(Gdirection::UP, window);
		}
		if (event.key.code == Keyboard::S)
		{
			move(Gdirection::DOWN, window);
		}
		if (event.key.code == Keyboard::A)
		{
			move(Gdirection::LEFT, window);
		}
		if (event.key.code == Keyboard::D)
		{
			move(Gdirection::RIGHT, window);
		}
	}

	if (collider == 1) std::cout << "Wasted" << std::endl;
	if (collider == 2) std::cout << "You win dat game" << std::endl;


}

void Player::Render(std::shared_ptr<RenderWindow> &window)
{
	window->draw(model);
}

Player::~Player()
{
}
