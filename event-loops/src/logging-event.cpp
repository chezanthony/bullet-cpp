#include <iostream>
#include "logging-event-subscriber.hpp"
#include "event-type.hpp"

using std::cout;
using std::endl;

namespace event_loops
{

namespace oop
{

bool LoggingEventSubscriber::onEvent(const EventType& event)
{
  cout  << "LoggingEventSubscriber: Event received. Category: "
        << event_loops::core::categoryToString(event_loops::core::getCategory(event))
        << " Event: " << event << endl;
  return true;
}

} // oop

} // event_loops
