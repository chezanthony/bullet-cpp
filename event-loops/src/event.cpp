#include "event-type.hpp"
#include "event.hpp"

namespace event_loops
{

namespace oop
{

Event::Event(event_loops::core::EventType event, std::any payload) :
  m_eventType(event),
  m_payload(std::move(payload))
{
}

event_loops::core::EventType Event::getEventType(void) const
{
  return m_eventType;
}

} // oop

} // event_loops
