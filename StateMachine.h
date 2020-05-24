#pragma once

#include "libraries.h"
using namespace sf;

#include "IStateMachine.h"

//typedef std::shared_ptr<IState> StateRef;

class StateMachine : public IStateMachine
{
private:
	int game_state = 0;

public:
	StateMachine();
	virtual ~StateMachine();

	virtual void AddState(StateRef&, bool = true) override;

	//pop front
	virtual void RemoveState() override;

	virtual int Update(std::shared_ptr<RenderWindow> &window, Event &event) override;

	virtual void ProcessStateChanges(std::shared_ptr<RenderWindow> &window) override;

	virtual StateRef &get_ActiveState() override;

	virtual bool isEmpty() override;
	
};



