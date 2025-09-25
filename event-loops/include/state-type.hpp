#ifndef STATE_TYPE_H
#define STATE_TYPE_H

#include <cstdint>
#include <limits>

namespace event_loops
{

namespace core
{

enum class StateType : std::uint16_t
{
  // System States
  None,
  Init,
  Idle,
  Running,
  Paused,
  Stopped,
  Error,
  ShuttingDown,
  Terminated,
  NotScheduled,
  Scheduled,
  Triggered,
  Expired,

  // Input States
  AwaitingInput,
  ProcessingInput,
  InputError,

  // Window States,
  Hidden,
  Visible,
  Focused,
  Minimized,
  Maximized,
  Active,
  Disabled,
  Modal,
  Closed,

  // Network States
  Disconnected,
  Connected,
  Connecting,
  Reconnecting,
  NetworkError,

  // User States
  UserState1,
  UserState2,
  UserState3,
  UserState4,
  UserState5,
  UserState6,
  UserState7,
  UserState8,
  UserState9,
  UserState10,
  UserState11,
  UserState12,
  UserState13,
  UserState14,
  UserState15,
  UserState16,
  UserState17,
  UserState18,
  UserState19,
  UserState20,

  Unknown = std::numeric_limits<std::uint16_t>::max(),
};

} // core

} // event_loops

#endif // !STATE_TYPE_H
