#include "StateMachine.h"

StateMachine::StateMachine()
{
}

void StateMachine::AddState(StateRef &newState, bool isReplacing) 
{
	m_isAdding = true;
	m_isReplacing = isReplacing;
	//processing ref of parameter to member
	//m_newState = std::move(newState); // old version for unique_ptr
	m_newState = std::move(newState);
} 

void StateMachine::RemoveState()
{
	m_isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (m_isRemoving && !m_states.empty())
	{
		m_states.pop();

		if (!m_states.empty())
		{
			//m_states.top()->Resume();
		}
		m_isRemoving = false;
	}

	if (m_isAdding)
	{
		if (!m_states.empty())
		{
			if (m_isReplacing)
			{
				m_states.pop();
			}
			else
			{
				// Pause prev state if adding new
				//m_states.top()->Pause();
			}
		}

		// push input state
		m_states.push(m_newState);
		m_states.top()->Init();
		m_isAdding = false;
	}
}

void StateMachine::Update()
{
	ProcessStateChanges();

	m_states.top()->Update();
}

StateRef &StateMachine::get_ActiveState()
{
	return m_states.top();
}

bool StateMachine::isEmpty()
{
	if (m_states.empty()) return true;
	else return false;
}


StateMachine::~StateMachine()
{
}
