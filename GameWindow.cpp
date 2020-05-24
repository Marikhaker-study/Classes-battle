#include "GameWindow.h"

GameWindow::GameWindow()
{
}

void GameWindow::configurate(int width, int height, char *name)
{
	// Anti-aliasing
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	m_window = std::make_shared<RenderWindow>(VideoMode(width, height), name, Style::Default, settings);
	m_window->setFramerateLimit(60); // Frame limit to less cpu load

	//m_window->setVerticalSyncEnabled(1);
}

std::shared_ptr<RenderWindow> &GameWindow::get_window()
{
	return m_window;
}

GameWindow::~GameWindow()
{
}
