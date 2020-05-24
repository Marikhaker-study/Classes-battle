#pragma once
#include "libraries.h"
#include "GameWindow.h"
#include "StateMachine.h"
#include "Player.h"
#include "StartState.h"
#include "MainState.h"

using namespace sf;

class Game
{
private:

	std::shared_ptr<IWindow> G_window; // Game window instance
	std::shared_ptr< IState > m_startstate;
	std::shared_ptr< MainState> m_mainstate;
	Event event;
	// IoC container
	std::shared_ptr< Hypodermic::Container > m_container;
	std::shared_ptr< IStateMachine > m_states;
	std::shared_ptr< Player > m_player;

	int game_state = 0; // 0 start state; 1 started; 2 main state; 3 win; 4 lose;

public:

	Game();
	~Game();
	
	template<class T1, class T2>
	bool ck_collision(T1 object1, T2 object2, RenderWindow &window)
	{
		if (object1.getModel().getGlobalBounds().intersects(object2.getModel().getGlobalBounds()))
		{
			//std::cout << "Intersection" << std::endl;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void render();
	void run();
	void update();
	void ioc_container_configurate();

	
};

