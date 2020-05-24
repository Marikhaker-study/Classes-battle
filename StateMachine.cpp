#include "StateMachine.h"

StateMachine::StateMachine()
{
}

void StateMachine::AddState(StateRef &newState, bool isReplacing) 
{
	m_isAdding = true;
	m_isReplacing = isReplacing;

	//m_newState = std::move(newState); // old version for unique_ptr

	//processing ref of parameter to member
	m_newState = std::move(newState);
} 

void StateMachine::RemoveState()
{
	m_isRemoving = true;
}

void StateMachine::ProcessStateChanges(std::shared_ptr<RenderWindow> &window)
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
		m_states.top()->Init(window);
		m_isAdding = false;
	}
	
}

// 0 start state; 1 started; 2 main state; 3 win; 4 lose;
int StateMachine::Update(std::shared_ptr<RenderWindow> &window, Event &event)
{
	ProcessStateChanges(window);

	if (game_state == 0)
	{
		game_state = m_states.top()->Update(window, event);
		return 0;
	}
	else if (game_state == 1)
	{
		game_state = 2;
		return 1;
	}

	return 2;
	
}

//void StateMachine::StateControls

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
