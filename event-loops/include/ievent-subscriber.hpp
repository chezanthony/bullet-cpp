#ifndef IEVENT_SUBSCRIBER_H
#define IEVENT_SUBSCRIBER_H

namespace event_loops
{

namespace core
{

enum class EventType : uint16_t;

} // core

namespace oop
{

class IEventSubscriber
{
public:
  virtual ~IEventSubscriber() = default;

  virtual bool onEvent(const event_loops::core::EventType& event) = 0;
};

} // oop

} // event_loops

#endif // !IEVENT_SUBSCRIBER_H
