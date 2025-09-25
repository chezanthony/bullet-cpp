#include <gtest/gtest.h>
#include <vector>
#include <cstdint>
#include <typeinfo>
#include <array>
#include "event.hpp"
#include "event-type.hpp"

using std::vector;
using event_loops::core::EventType;
using event_loops::oop::Event;

TEST(EventTest, VerifyEventType)
{
  vector<EventType> eventTypes = {
    // System Events
    EventType::Startup,
    EventType::Shutdown,
    EventType::Tick,
    EventType::Error,
    EventType::ConfigReloaded,

    // Input Events
    EventType::KeyDown,
    EventType::KeyUp,
    EventType::MouseMove,
    EventType::MouseDown,
    EventType::MouseUp,
    EventType::MouseWheel,
    EventType::GamepadButtonDown,
    EventType::GamepadButtonUp,
    EventType::TouchStart,
    EventType::TouchEnd,
    EventType::TouchMove,

    // Window Events
    EventType::Resize,
    EventType::FocusGained,
    EventType::FocusLost,
    EventType::Minimized,
    EventType::Maximized,
    EventType::Restored,
    EventType::Closed,
    EventType::Redraw,

    // File Events
    EventType::FileOpened,
    EventType::FileClosed,
    EventType::FileRead,
    EventType::FileWritten,
    EventType::FileError,

    // Network Events
    EventType::NetConnected,
    EventType::NetDisconnected,
    EventType::NetDataReceived,
    EventType::NetDataSent,
    EventType::NetError,

    // Application Events
    EventType::StateChanged,
    EventType::ActionTriggered,
    EventType::DataUpdated,
    EventType::Notification,

    // User Events
    EventType::UserEvent1,
    EventType::UserEvent2,
    EventType::UserEvent3,
    EventType::UserEvent4,
    EventType::UserEvent5,
    EventType::UserEvent6,
    EventType::UserEvent7,
    EventType::UserEvent8,
    EventType::UserEvent9,
    EventType::UserEvent10,
    EventType::UserEvent11,
    EventType::UserEvent12,
    EventType::UserEvent13,
    EventType::UserEvent14,
    EventType::UserEvent15,
    EventType::UserEvent16,
    EventType::UserEvent17,
    EventType::UserEvent18,
    EventType::UserEvent19,
    EventType::UserEvent20,

    EventType::Unknown,
  };

  int nTestPayload = 100;

  for (auto eventType : eventTypes)
  {
    // Event event(eventType);
    Event event(eventType, nTestPayload);
    ASSERT_EQ(eventType, event.getEventType());
    ASSERT_EQ(nTestPayload, event.getPayload<int>());
  }
}

TEST(EventTest, VerifyIntPayload)
{
  const int nTestPayload(100);
  Event testEvent(EventType::NetDataReceived, nTestPayload);

  const int nActualPayload = testEvent.getPayload<int>();

  ASSERT_EQ(nTestPayload, nActualPayload);
  ASSERT_EQ(typeid(nTestPayload).name(), typeid(nActualPayload).name());
}

TEST(EventTest, VerifyIntVectorPayload)
{
  const vector<int> testPayload{1, 2, 3, 4, 5};
  Event testEvent(EventType::NetDataReceived, testPayload);

  const vector<int> actualPayload = testEvent.getPayload<vector<int>>();

  ASSERT_EQ(testPayload, actualPayload);
  ASSERT_EQ(typeid(testPayload).name(), typeid(actualPayload).name());
}

TEST(EventTest, VerifyCustomTypePayload)
{
  struct TestStruct {
    int sourceId;
    int size;
    std::array<int, 256> data;
    bool operator==(const TestStruct& other) const {
      return
        sourceId  == other.sourceId &&
        size      == other.size     &&
        data      == other.data;
    }
  };

  const TestStruct testPayload{45, 5, {'H', 'e', 'l', 'l', 'o'}};
  Event testEvent(EventType::NetDataReceived, testPayload);

  const TestStruct actualPayload = testEvent.getPayload<TestStruct>();

  ASSERT_EQ(testPayload, actualPayload);
  ASSERT_EQ(typeid(testPayload).name(), typeid(actualPayload).name());
}
