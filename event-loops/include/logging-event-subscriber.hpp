#ifndef LOGGING_EVENT_SUBSCRIBER_H
#define LOGGING_EVENT_SUBSCRIBER_H

#include "ievent-subscriber.hpp"

namespace event_loops
{

namespace oop
{

enum class EventType : uint16_t;

class LoggingEventSubscriber : public IEventSubscriber
{
public:
  LoggingEventSubscriber(void) = default;
  ~LoggingEventSubscriber(void) = default;

  bool onEvent(const EventType& event) override;
};

} // oop

} // event_loops

#endif // !LOGGING_EVENT_SUBSCRIBER_H
