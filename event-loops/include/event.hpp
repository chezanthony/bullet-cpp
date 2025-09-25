#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <cstring>
#include <any>

namespace event_loops
{

namespace core
{
  enum class EventType : std::uint16_t;
} // core

namespace oop
{

class Event
{
public:
  Event(event_loops::core::EventType event, std::any payload);
  ~Event() = default;

  event_loops::core::EventType getEventType(void) const;

  template <typename T>
  T getPayloadAs(void) const
  {
    return std::any_cast<const T&>(m_payload);
  }

  const std::any& getPayload(void) const;

private:
  event_loops::core::EventType m_eventType;
  std::any m_payload;
};

} // oop

} // event_loops

#endif // !EVENT_H
