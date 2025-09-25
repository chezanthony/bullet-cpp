#include "state-machine.hpp"
#include "state-type.hpp"

using event_loops::core::StateType;
using std::move;

namespace event_loops
{

namespace oop
{

StateMachine::StateMachine(std::shared_ptr<IEventReceiver> pEventReceiver) :
  m_currentState(StateType::None),
  m_pEventReceiver(move(pEventReceiver))
{
}

bool StateMachine::changeState(StateType state)
{
  if (m_currentState == state)
  {
    return;
  }

  m_currentState = state;
  m_pEventReceiver->publishEvent(EventType::StateChanged);
}

} // oop

} // event_loops
