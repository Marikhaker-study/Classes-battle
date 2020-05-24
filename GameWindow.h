#pragma once
#include "IWindow.h"

class GameWindow: public IWindow
{
private:
	std::shared_ptr<RenderWindow> m_window;
public:

	GameWindow();

	std::shared_ptr<RenderWindow> &GameWindow::get_GameWindow() override;

	void configurate(int width, int height, char *name) override;

	virtual ~GameWindow();


};

