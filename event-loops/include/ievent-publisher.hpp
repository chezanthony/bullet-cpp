#ifndef IEVENT_PUBLISHER_H
#define IEVENT_PUBLISHER_H

namespace event_loops
{

namespace oop
{

class IEventPublisher
{
public:
  virtual ~IEventPublisher() = default;

  virtual bool publishEvent(const event_loops::oop::Event& event) = 0;
};

} // oop

} // event_loops

#endif // !IEVENT_PUBLISHER_H
