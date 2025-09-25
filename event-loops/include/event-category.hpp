#ifndef EVENT_CATEGORY_H
#define EVENT_CATEGORY_H

#include <cstdint>

namespace event_loops
{

namespace core
{

enum class EventCategory : std::uint16_t {
  System,
  Input ,
  Window,
  File,
  Network,
  Application,
  User,
};

} // core

} // event_loops

#endif // !EVENT_CATEGORY_H
