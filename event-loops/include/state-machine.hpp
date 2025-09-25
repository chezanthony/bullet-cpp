#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <cstdint>
#include <memory>
#include "event.hpp"

namespace event_loops
{

namespace core
{
  enum class EventType : std::uint16_t;
  enum class StateType : std::uint16_t;
} // core

namespace oop
{

class IEventReceiver;

class StateMachine
{
public:
  StateMachine(std::shared_ptr<IEventReceiver> pEventReceiver);
  ~StateMachine(void) = default;

  bool changeState(event_loops::core::StateType state);
  event_loops::core::StateType getCurrentState(void) const;

private:
  event_loops::core::StateType m_currentState;
  std::shared_ptr<IEventReceiver> m_pEventReceiver;
  event_loops::oop::Event m_stateChangedEvent;
};

} // oop

} // event_loops

#endif // !STATE_MACHINE_H
