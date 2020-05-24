#include "Game.h"



Game::Game()
{
	ioc_container_configurate();

	G_window = m_container->resolve<IWindow>();

	G_window->configurate(500, 500, "Classes battle");

}

void Game::ioc_container_configurate()
{
	Hypodermic::ContainerBuilder builder;

	// Registering dependencies
	builder.registerType< StateMachine >().as< IStateMachine >();
	builder.registerType< StartState >().as< IState >();
	//builder.registerType< MainState >().as< IState >();
    builder.registerType< GameWindow >().as< IWindow >();

	m_mainstate = std::make_shared< MainState >();
	m_player = std::make_shared< Player >();

	builder.registerInstance(m_mainstate);
	builder.registerInstance(m_player);

	m_container = builder.build();
}


Game::~Game()
{
	
}

// Put render not inside of classes because rendering inside them cause texture blinking for some reason
void Game::render()
{
	if (game_state == 0)
	{
		m_states->get_ActiveState()->Render(G_window->get_window());
	}
	else if (game_state == 2)
	{
		G_window->get_window()->clear(Color(250, 220, 100, 0));
		m_player->Render(G_window->get_window());
	}
	G_window->get_window()->display();
}

void Game::update()
{

	while (G_window->get_window()->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			G_window->get_window()->close();
			return;
		}

		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				G_window->get_window()->close();
				return;
			}
		}

		if (game_state == 0)
		{
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
					game_state = 1;
				}
			}
		}
		if(game_state == 2) m_player->update(G_window->get_window(), event, 0);
	}

	if (game_state == 0)
	{
		game_state = m_states->Update(G_window->get_window(), event);
	}
	else if (game_state == 1)
	{
		m_mainstate->Init(G_window->get_window());
		m_player->Init(10, 14, 222, 50, G_window->get_window());
		game_state = 2;
	}
	
}

void Game::run()
{
	m_states = m_container->resolve<IStateMachine>();

	m_startstate = m_container->resolve<IState>();

	m_states->AddState(m_startstate);
	
	while (G_window->get_window()->isOpen() )
	{
		update();
		render();
	}
}
