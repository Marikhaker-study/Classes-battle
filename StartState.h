#pragma once
#include "IState.h"
class StartState : public IState
{
private:

public:

	StartState();

	virtual void Init(std::shared_ptr<RenderWindow> &window) override;
	//virtual void HandleInput() = 0;
	virtual int Update(std::shared_ptr<RenderWindow> &window, Event &event) override;
	virtual void Render(std::shared_ptr<RenderWindow> &window) override;
	//virtual void Render(float dt) = 0;

	//virtual void Pause() {}
	//virtual void Resume() {}
	virtual ~StartState();
};

