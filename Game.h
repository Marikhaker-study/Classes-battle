#pragma once
#include "libraries.h"
#include "GameWindow.h"
#include "StateMachine.h"
#include "Entity.h"
#include "StartState.h"

using namespace sf;

class Game
{
private:

	std::shared_ptr<IWindow> G_window; // Game window instance
	std::shared_ptr< IState > m_startstate;
	Event event;
	// IoC container
	std::shared_ptr< Hypodermic::Container > m_container;
	std::shared_ptr< IStateMachine > m_states;

public:

	Game();
	~Game();
	void render();
	void run();
	void update();
	void ioc_container_configurate();

	
};

