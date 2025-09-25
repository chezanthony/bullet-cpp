#include "base-event-publisher.hpp"
#include "ievent-receiver.hpp"

namespace event_loops
{

namespace oop
{

BaseEventPublisher::BaseEventPublisher(shared_ptr<IEventReceiver> pEventReceiver) :
  m_pEventReceiver()
{
}

bool BaseEventPublisher::publishEvent(const event_loops::oop::Event& event)
{

}

} // oop

} // event_loops
