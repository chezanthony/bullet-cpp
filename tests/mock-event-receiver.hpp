#ifndef MOCK_EVENT_RECEIVER_H
#define MOCK_EVENT_RECEIVER_H

#include <gmock/gmock.h>
#include "ievent-receiver.hpp"
#include "event.hpp"

namespace event_loops
{

namespace oop
{

class MockEventReceiver : public IEventReceiver
{
public:
  MOCK_METHOD(void, publishEvent, (const event_loops::oop::Event& event), (override));
};

} // oop

} // event_loops

#endif // !MOCK_EVENT_RECEIVER_H
