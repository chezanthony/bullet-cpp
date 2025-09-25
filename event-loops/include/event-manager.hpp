#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <cstdint>
#include <vector>
#include <memory>
#include <deque>
#include "ievent-receiver.hpp"

using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::deque;
using std::size_t;

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

  void publishEvent(event_loops::oop::Event& event) override;
  bool handleEvents(void);
  void registerSubscriber(shared_ptr<IEventSubscriber> subscriber);

  // test functions
  size_t getPendingEventCount(void) const;
  size_t getRegisteredSubscriberCount(void) const;
  bool hasEventOfType(event_loops::core::EventType type) const;

private:
  vector<shared_ptr<IEventSubscriber>> m_eventSubscribers;
  deque<Event> m_eventQueue;
};

} // oop

} // event_loops

#endif // !EVENT_MANAGER_H
