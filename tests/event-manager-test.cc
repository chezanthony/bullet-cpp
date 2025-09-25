#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "event-manager.hpp"
#include "event-type.hpp"
#include "event.hpp"
#include "mock-event-subscriber.hpp"

using std::shared_ptr;
using std::make_shared;
using std::vector;
using ::testing::Return;
using ::testing::_;
using event_loops::core::EventType;
using event_loops::oop::Event;
using event_loops::oop::EventManager;
using event_loops::oop::IEventSubscriber;
using event_loops::oop::MockEventSubscriber;

class EventManagerTest : public testing::Test
{
protected:
  EventManagerTest(void) :
    m_testPayload(100),
    m_startupEvent(EventType::Startup, m_testPayload),
    m_shutdownEvent(EventType::Shutdown, m_testPayload),
    m_tickEvent(EventType::Tick, m_testPayload),
    m_errorEvent(EventType::Error, m_testPayload),
    m_configReloadedEvent(EventType::ConfigReloaded, m_testPayload),
    m_mockEventSubscriber1(make_shared<MockEventSubscriber>()),
    m_mockEventSubscriber2(make_shared<MockEventSubscriber>()),
    m_theEvents{
      m_startupEvent,
      m_shutdownEvent,
      m_tickEvent,
      m_errorEvent,
      m_configReloadedEvent,
    }
  {
  }

  void SetUp(void) override
  {
    m_eventManager.registerSubscriber(m_mockEventSubscriber1);
    m_eventManager.registerSubscriber(m_mockEventSubscriber2);

    ON_CALL(*m_mockEventSubscriber1, onEvent(_))
      .WillByDefault(Return(true));
    ON_CALL(*m_mockEventSubscriber2, onEvent(_))
      .WillByDefault(Return(true));
  }

  int m_testPayload;
  Event m_startupEvent;
  Event m_shutdownEvent;
  Event m_tickEvent;
  Event m_errorEvent;
  Event m_configReloadedEvent;
  shared_ptr<MockEventSubscriber> m_mockEventSubscriber1;
  shared_ptr<MockEventSubscriber> m_mockEventSubscriber2;
  vector<Event> m_theEvents;
  EventManager m_eventManager;
};

TEST_F(EventManagerTest, VerifyPublishEventStoresEvent)
{
  size_t nCurrentCount = 0;

  for (auto currentEvent : m_theEvents)
  {
    m_eventManager.publishEvent(currentEvent);
    ++nCurrentCount;

    const size_t nActualEventCount = m_eventManager.getPendingEventCount();
    ASSERT_EQ(nCurrentCount, nActualEventCount);

    const EventType expectedEventType = currentEvent.getEventType();
    ASSERT_TRUE(m_eventManager.hasEventOfType(expectedEventType));
  }
}

TEST_F(EventManagerTest, VerifyHandleEventsDoNotCrashWhenQueueEmpty)
{
  const size_t nExpectedEventCount = 0;
  const size_t nActualEventCount = m_eventManager.getPendingEventCount();

  ASSERT_EQ(nExpectedEventCount, nActualEventCount);

  ASSERT_NO_THROW(m_eventManager.handleEvents());
}

TEST_F(EventManagerTest, VerifyHandleEventsCallRegisteredSubscribers)
{
  for (auto currentEvent : m_theEvents)
  {
    m_eventManager.publishEvent(currentEvent);
  }

  EXPECT_CALL(*m_mockEventSubscriber1, onEvent(_));
  EXPECT_CALL(*m_mockEventSubscriber2, onEvent(_));

  m_eventManager.handleEvents();
}

TEST_F(EventManagerTest, VerifyHandleEventsReturnsTrueWhenQueueEmpty)
{
  const size_t nExpectedEventCount = 0;
  const size_t nActualEventCount = m_eventManager.getPendingEventCount();

  ASSERT_EQ(nExpectedEventCount, nActualEventCount);
  
  ASSERT_TRUE(m_eventManager.handleEvents());
}

TEST_F(EventManagerTest, VerifyHandleEventsRemovesEventInFrontOfQueue)
{
  for (auto currentEvent : m_theEvents)
  {
    m_eventManager.publishEvent(currentEvent);
  }

  size_t nCurrentCount = m_eventManager.getPendingEventCount();

  while (0 != m_eventManager.getPendingEventCount())
  {
    m_eventManager.handleEvents();
    --nCurrentCount;

    const size_t nActualEventCount = m_eventManager.getPendingEventCount();

    ASSERT_EQ(nCurrentCount, nActualEventCount);

    const size_t nCurrentIndex = 4 - nCurrentCount;
    const Event currentEvent = m_theEvents.at(nCurrentIndex);
    const EventType expectedRemovedType = currentEvent.getEventType();
    
    ASSERT_FALSE(m_eventManager.hasEventOfType(expectedRemovedType));
  }
}

TEST_F(EventManagerTest, VerifyHandleEventsReturnsEarlyWhenSubscriberReturnsFalse)
{
  ON_CALL(*m_mockEventSubscriber1, onEvent(_))
    .WillByDefault(Return(false));

  for (auto currentEvent : m_theEvents)
  {
    m_eventManager.publishEvent(currentEvent);
  }

  EXPECT_CALL(*m_mockEventSubscriber2, onEvent(_))
    .Times(0);
  
  m_eventManager.handleEvents();
}

TEST_F(EventManagerTest, VerifyHandleEventsReturnsFalseWhenSubscriberReturnsFalse)
{
  ON_CALL(*m_mockEventSubscriber2, onEvent(_))
    .WillByDefault(Return(false));

  for (auto currentEvent : m_theEvents)
  {
    m_eventManager.publishEvent(currentEvent);
  }

  ASSERT_FALSE(m_eventManager.handleEvents());
}
