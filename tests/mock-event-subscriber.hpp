#include <gmock/gmock.h>
#include "ievent-subscriber.hpp"
#include "event-type.hpp"

namespace event_loops
{

namespace oop
{

class MockEventSubscriber : public IEventSubscriber
{
public:
  MOCK_METHOD(bool, onEvent, (const event_loops::core::EventType& event), (override));
};

} // oop

} // event_loops
