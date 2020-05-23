#pragma once

#include "libraries.h"
using namespace sf;

#include "IState.h"

typedef std::shared_ptr<IState> StateRef;

class IStateMachine : public IState
{
protected:
	std::stack<StateRef> m_states;
	StateRef m_newState;
	bool m_isRemoving, m_isAdding, m_isReplacing;
public:

	virtual void Init() override {};
	virtual ~IStateMachine() {}

	//push front
	virtual void AddState(StateRef&, bool = true) = 0;

	//pop front
	virtual void RemoveState() = 0;

	virtual void ProcessStateChanges() = 0;

	virtual StateRef &get_ActiveState() = 0;

	virtual bool isEmpty() = 0;
};