#ifndef BASE_EVENT_PUBLISHER_H
#define BASE_EVENT_PUBLISHER_H

#include <memory>
#include "ievent-publisher.hpp"

using std::shared_ptr;

namespace event_loops
{

namespace oop
{

class IEventReceiver;

class BaseEventPublisher : public IEventPublisher
{
public:
  BaseEventPublisher(shared_ptr<IEventReceiver> pEventReceiver);
  ~BaseEventPublisher(void);

  bool publishEvent(const event_loops::oop::Event& event) override;

private:
  shared_ptr<IEventReceiver> m_pEventReceiver;
};

} // oop

} // event_loops

#endif // !BASE_EVENT_PUBLISHER_H
