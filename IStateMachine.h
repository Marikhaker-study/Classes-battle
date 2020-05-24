#pragma once
#include "IState.h"
#include "IWindow.h"

typedef std::shared_ptr<IState> StateRef;

class IStateMachine
{
protected:
	std::stack<StateRef> m_states;
	StateRef m_newState;
	bool m_isRemoving = 0, m_isAdding = 0, m_isReplacing = 0;
public:

	//IStateMachine() {}

	virtual ~IStateMachine() {};

	//push front
	virtual void AddState(StateRef&, bool = true) = 0;

	//pop front
	virtual void RemoveState() = 0;

	virtual int Update(std::shared_ptr<RenderWindow> &window, Event &event) = 0;

	virtual void ProcessStateChanges(std::shared_ptr<RenderWindow> &window) = 0;

	virtual StateRef &get_ActiveState() = 0;

	virtual bool isEmpty() = 0;
};