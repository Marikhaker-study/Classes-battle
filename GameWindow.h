#pragma once
#include "libraries.h"
#include "IWindow.h"
using namespace sf;

class GameWindow: public IWindow
{
private:
	std::shared_ptr<RenderWindow> m_window;
public:

	GameWindow();

	std::shared_ptr<RenderWindow> &GameWindow::get_GameWindow();

	void configurate(int width, int height, char *name) override;

	virtual ~GameWindow();


};

