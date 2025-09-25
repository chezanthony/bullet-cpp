#ifndef IEVENT_RECEIVER_H
#define IEVENT_RECEIVER_H

namespace event_loops
{

namespace oop
{

class Event;

class IEventReceiver
{
public:
  virtual ~IEventReceiver(void) = default;
  virtual void publishEvent(event_loops::oop::Event& event) = 0;
};

} // oop

} // event_loops

#endif // !IEVENT_RECEIVER_H
