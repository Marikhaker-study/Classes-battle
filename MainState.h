#pragma once
#include "IState.h"
class MainState :
	public IState
{
public:
	MainState();

	virtual void Init(std::shared_ptr<RenderWindow> &window) override;

	//virtual void HandleInput() = 0;

	virtual int Update(std::shared_ptr<RenderWindow> &window, Event &event) override;
	virtual void Render(std::shared_ptr<RenderWindow> &window) override;

	virtual ~MainState();
};

