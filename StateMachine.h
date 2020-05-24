#pragma once

#include "libraries.h"
using namespace sf;

#include "IStateMachine.h"

//typedef std::shared_ptr<IState> StateRef;

class StateMachine : public IStateMachine
{
private:
	
public:
	StateMachine();
	virtual ~StateMachine();

	virtual void AddState(StateRef&, bool = true) override;

	//pop front
	virtual void RemoveState() override;

	virtual void Update() override;

	virtual void ProcessStateChanges() override;

	virtual StateRef &get_ActiveState() override;

	virtual bool isEmpty() override;



	
};



