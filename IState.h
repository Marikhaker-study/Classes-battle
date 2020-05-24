#pragma once
#include "libraries.h"
#include "AssetManager.h"
#include "IWindow.h"
using namespace sf;

class IState
{
protected:
	Texture m_texture;
	Sprite m_sprite;
	bool m_isActive = 0;
	//std::shared_ptr<IWindow> m_window;

public:

	virtual ~IState() {};

	virtual void Init(std::shared_ptr<RenderWindow> &window) = 0;

	//virtual void HandleInput() = 0;

	virtual int Update(std::shared_ptr<RenderWindow> &window, Event &event) = 0;
	virtual void Render(std::shared_ptr<RenderWindow> &window) = 0;

	virtual bool isActive()
	{
		return m_isActive;
	}

	//virtual void Render(float dt) = 0;

	//virtual void Pause() {}
	//virtual void Resume() {}
};

