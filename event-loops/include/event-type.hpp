#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

#include <cstdint>
#include <limits>
#include <string>
#include "event-category.hpp"

namespace event_loops
{

namespace core
{

// enum class EventCategory : std::uint16_t;

constexpr std::uint16_t CATEGORY_MASK           = 0xF000;
constexpr std::uint16_t CODE_MASK               = 0x0FFF;
constexpr std::uint16_t CATEGORY_SHIFT          = 12;
constexpr std::uint16_t CATEGORY_STARTING_CDOE  = 0x0001;

constexpr std::uint16_t makeEventCode(EventCategory category, std::uint16_t id)
{
  return ((static_cast<std::uint16_t>(category) << CATEGORY_SHIFT) | (id & CODE_MASK));
}

constexpr std::uint16_t makeNewCategoryCode(EventCategory category)
{
  return ((static_cast<std::uint16_t>(category) << CATEGORY_SHIFT) | CATEGORY_STARTING_CDOE);
}

enum class EventType : std::uint16_t
{
  // System Events
  Startup       = makeNewCategoryCode(EventCategory::System),
  Shutdown,
  Tick,
  Error,
  ConfigReloaded,

  // Input Events
  KeyDown       = makeNewCategoryCode(EventCategory::Input),
  KeyUp,
  MouseMove,
  MouseDown,
  MouseUp,
  MouseWheel,
  GamepadButtonDown,
  GamepadButtonUp,
  TouchStart,
  TouchEnd,
  TouchMove,

  // Window Events
  Resize        = makeNewCategoryCode(EventCategory::Window),
  FocusGained,
  FocusLost,
  Minimized,
  Maximized,
  Restored,
  Closed,
  Redraw,

  // File Events
  FileOpened    = makeNewCategoryCode(EventCategory::File),
  FileClosed,
  FileRead,
  FileWritten,
  FileError,

  // Network Events
  NetConnected  = makeNewCategoryCode(EventCategory::Network),
  NetDisconnected,
  NetDataReceived,
  NetDataSent,
  NetError,

  // Application Events
  StateChanged  = makeNewCategoryCode(EventCategory::Application),
  ActionTriggered,
  DataUpdated,
  Notification,

  // User Events
  UserEvent1    = makeNewCategoryCode(EventCategory::User),
  UserEvent2,
  UserEvent3,
  UserEvent4,
  UserEvent5,
  UserEvent6,
  UserEvent7,
  UserEvent8,
  UserEvent9,
  UserEvent10,
  UserEvent11,
  UserEvent12,
  UserEvent13,
  UserEvent14,
  UserEvent15,
  UserEvent16,
  UserEvent17,
  UserEvent18,
  UserEvent19,
  UserEvent20,

  Unknown       = std::numeric_limits<std::uint16_t>::max(),
};

constexpr EventCategory getCategory(EventType event)
{
  return static_cast<EventCategory>(
    (static_cast<std::uint16_t>(event) & CATEGORY_MASK) >> CATEGORY_SHIFT
  );
}

constexpr bool isInCategory(EventType event, EventCategory category)
{
  return getCategory(event) == category;
}

inline const std::string categoryToString(EventCategory category)
{
  switch (category)
  {
    case EventCategory::System:
      return "System";
    case EventCategory::Input:
      return "Input";
    case EventCategory::Window:
      return "Window";
    case EventCategory::File:
      return "File";
    case EventCategory::Network:
      return "Network";
    case EventCategory::Application:
      return "Application";
    case EventCategory::User:
      return "User";
    default:
      return "Unknown";
  }
}

} // core

} // event_loops

#endif // !EVENT_TYPE_H
