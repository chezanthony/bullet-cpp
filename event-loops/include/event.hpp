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
  // Event(event_loops::core::EventType event);
  Event(event_loops::core::EventType event, std::any payload);
  ~Event() = default;

  event_loops::core::EventType getEventType(void) const;
  
  // template <typename T>
  // void setPayload(const T& value)
  // {
  //   m_payload.resize(sizeof(T));
  //   std::memcpy(m_payload.data(), &value, sizeof(T));
  // }

  template <typename T>
  T getPayload(void) const
  {
    // T value;
    // std::memcpy(&value, m_payload.data(), sizeof(T));
    // return value;
    return std::any_cast<const T&>(m_payload);
  }

private:
  event_loops::core::EventType m_eventType;
  // std::vector<std::byte> m_payload;
  std::any m_payload;
};

} // oop

} // event_loops

#endif // !EVENT_H
