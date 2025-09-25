#include "event-type.hpp"
#include "event.hpp"

using std::any;
using std::move;
using event_loops::core::EventType;

namespace event_loops
{

namespace oop
{

Event::Event(EventType event, any payload) :
  m_eventType(event),
  m_payload(move(payload))
{
}

EventType Event::getEventType(void) const
{
  return m_eventType;
}

const std::any& Event::getPayload(void) const
{
  return m_payload;
}

} // oop

} // event_loops
