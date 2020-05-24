#include "StartState.h"



StartState::StartState()
{
}

void StartState::Init(std::shared_ptr<RenderWindow> &window)
{
	m_sprite = AssetManager::create_gamestate_sprite("Game start sprite.png", m_texture);
	m_isActive = true;
}

// 1 ->active; 2->notactive
int StartState::Update(std::shared_ptr<RenderWindow> &window, Event &event)
{

	//for some reason this part of code doesnt work

	//while (window->pollEvent(event))
	//{
	//	//window->clear(Color(250, 220, 100, 0));
	//	//if (Keyboard::isKeyPressed(Keyboard::Escape))
	//	//{
	//	//	//Render(window);
	//	//	std::cout << "ENTER" << std::endl;
	//	//	return 1;
	//	//}

	//	//if (event.type == Event::KeyPressed)
	//	//{
	//	//	if (event.key.code == Keyboard::Enter)
	//	//	{
	//	//		std::cout << "enter" << std::endl;
	//	//	}

	//	//}
	//}
	return 0;
}


void StartState::Render(std::shared_ptr<RenderWindow> &window)
{
	window->draw(m_sprite);
}

StartState::~StartState()
{
}
