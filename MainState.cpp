#include "MainState.h"



MainState::MainState()
{
}

void MainState::Init(std::shared_ptr<RenderWindow> &window)
{
	m_isActive = true;
}

// 1 ->active; 2->notactive
int MainState::Update(std::shared_ptr<RenderWindow> &window, Event &event)
{
	Render(window);
	return 2;
}


void MainState::Render(std::shared_ptr<RenderWindow> &window)
{
	window->clear(Color(250, 220, 100, 0));
	//window->draw(m_sprite);
}

MainState::~MainState()
{
}
