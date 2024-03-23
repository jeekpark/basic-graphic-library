#pragma once

namespace bgl
{
namespace Style
{

enum
{
    None        = 0,
    Titlebar    = 1 << 0,
    Resize      = 1 << 1,
    Close       = 1 << 2,
    Default     = Titlebar | Resize | Close
};

} // namespalce Style

enum class State
{
    Windowed,
    Fullscreen
};

} // namespace bgl
