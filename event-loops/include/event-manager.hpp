#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <cstdint>
#include <vector>
#include <memory>
#include <deque>
#include "ievent-receiver.hpp"

namespace event_loops
{

namespace core
{
  enum class EventType : std::uint16_t;
} // core

namespace oop
{

class Event;
class IEventPublisher;
class IEventSubscriber;

class EventManager : public IEventReceiver
{
public:
  EventManager(void);
  ~EventManager(void);

  void publishEvent(const event_loops::oop::Event& event) override;
  bool handleEvents(void);
  void registerSubscriber(std::shared_ptr<IEventSubscriber> subscriber);

  // test functions
  std::size_t getPendingEventCount(void) const;
  std::size_t getRegisteredSubscriberCount(void) const;
  bool hasEventOfType(event_loops::core::EventType type) const;

private:
  std::vector<std::shared_ptr<IEventSubscriber>> m_eventSubscribers;
  std::deque<Event> m_eventQueue;
};

} // oop

} // event_loops

#endif // !EVENT_MANAGER_H
