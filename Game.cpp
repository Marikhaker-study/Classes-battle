#include "Game.h"

//
//#define m_window G_window->get_GameWindow() 

Game::Game()
{
	ioc_container_configurate();

	G_window = m_container->resolve<IWindow>();

	G_window->configurate(900, 900, "Classes battle");

	/*Hypodermic::ContainerBuilder builder;
	builder.registerType< Entity >().as< IEntity >();

	auto container = builder.build();

	auto instanceOfBWithStaticTypeA = container->resolve<IEntity >();
	
	instanceOfBWithStaticTypeA->Draw();*/

	//run();
}

void Game::ioc_container_configurate()
{
	Hypodermic::ContainerBuilder builder;

	// Registering dependencies
	builder.registerType< StateMachine >().as< IStateMachine >();
	builder.registerType< StartState >().as< IState >();
    builder.registerType< GameWindow >().as< IWindow >();
	//G_window = std::make_shared< GameWindow >();

	//builder.registerInstance(G_window);

	m_container = builder.build();
}


Game::~Game()
{
	
}

void Game::render()
{
	//G_window->get_GameWindow()->clear(Color(250, 220, 100, 0));

	G_window->get_GameWindow()->display();
}

void Game::update()
{
	
	G_window->get_GameWindow()->clear(Color(250, 220, 100, 0));

	while (G_window->get_GameWindow()->pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			G_window->get_GameWindow()->close();
			return;
		}

		m_states->Update();

	}
}

void Game::run()
{
	m_states = m_container->resolve<IStateMachine>();

	m_startstate = m_container->resolve<IState>();

	m_states->AddState(m_startstate);
	
	while (G_window->get_GameWindow()->isOpen() )
	{
		update();
		render();
	}
}
