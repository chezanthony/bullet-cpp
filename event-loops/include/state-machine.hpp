#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <cstdint>
#include <memory>

namespace event_loops
{

namespace core
{
  enum class StateType : std::uint16_t;
} // core

namespace oop
{

class IEventReceiver;

class StateMachine
{
public:
  StateMachine(std::shared_ptr<IEventReceiver> pEventReceiver);
  ~StateMachine(void);

  bool changeState(event_loops::core::StateType state);
  event_loops::core::StateType getCurrentState(void) const;

private:
  event_loops::core::StateType m_currentState;
  std::shared_ptr<IEventReceiver> m_pEventReceiver;
};

} // oop

} // event_loops

#endif // !STATE_MACHINE_H
