#ifndef LAYER_TYPE_H
#define LAYER_TYPE_H

#include <cstdint>

namespace event_loops
{

namespace core
{

enum class LayerType : std::uint16_t
{
  DeveloperCoreLayer,
  DeveloperCustomLayer,
  CustomerLayer,
};

} // core

} // event_loops

#endif // !LAYER_TYPE_H
