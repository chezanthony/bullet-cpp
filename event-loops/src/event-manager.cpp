#include "event-manager.hpp"
#include "event-type.hpp"
#include "event.hpp"
#include "ievent-subscriber.hpp"

using std::shared_ptr;

namespace event_loops
{

namespace oop
{

EventManager::EventManager(void)
{
}

EventManager::~EventManager(void)
{
}

void EventManager::publishEvent(const Event& event)
{
  m_eventQueue.push_back(event);
}

bool EventManager::handleEvents(void)
{
  if (m_eventQueue.empty())
  {
    return true;
  }

  const Event currentEvent = m_eventQueue.front();
  m_eventQueue.pop_front();

  for (auto& eventSubscriber : m_eventSubscribers)
  {
    const event_loops::core::EventType eventType = currentEvent.getEventType();
    if (!eventSubscriber->onEvent(eventType))
    {
      return false;
    }
  }

  return true;
}

void EventManager::registerSubscriber(shared_ptr<IEventSubscriber> subscriber)
{
  m_eventSubscribers.push_back(subscriber);
}

// test functions
size_t EventManager::getPendingEventCount(void) const
{
  return m_eventQueue.size();
}

size_t EventManager::getRegisteredSubscriberCount(void) const
{
  return m_eventSubscribers.size();
}

bool EventManager::hasEventOfType(event_loops::core::EventType type) const
{
  // const event_loops::core::EventType referenceType = event.getEventType();
  for (auto currentEvent : m_eventQueue)
  {
    const event_loops::core::EventType currentType = currentEvent.getEventType();

    if (currentType == type)
    {
      return true;
    }
  }

  return false;
}

} // oop

} // event_loops
