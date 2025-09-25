#include "state-machine.hpp"
#include "state-type.hpp"
#include "ievent-receiver.hpp"
#include "event-type.hpp"

using std::shared_ptr;
using std::move;
using event_loops::core::StateType;
using event_loops::core::EventType;
using event_loops::oop::IEventReceiver;

namespace event_loops
{

namespace oop
{

StateMachine::StateMachine(std::shared_ptr<IEventReceiver> pEventReceiver) :
  m_currentState(StateType::None),
  m_pEventReceiver(move(pEventReceiver)),
  m_stateChangedEvent(EventType::StateChanged, 0)
{
}

bool StateMachine::changeState(StateType state)
{
  if (m_currentState == state)
  {
    return true;
  }

  m_currentState = state;
  const Event stateChangedEvent(EventType::StateChanged, state);
  m_pEventReceiver->publishEvent(stateChangedEvent);
  return true;
}

StateType StateMachine::getCurrentState(void) const
{
  return m_currentState;
}

} // oop

} // event_loops
