#pragma once
#include "IState.h"
class StartState : public IState
{
public:
	StartState();
	virtual void Init() override;
	//virtual void HandleInput() = 0;
	virtual void Update() override;
	//virtual void Render(float dt) = 0;

	virtual void Pause() {}
	virtual void Resume() {}
	virtual ~StartState();
};

