#pragma once

#include <Vector>

#include <BGL/System/types.hpp>
#include <BGL/System/Vector2.hpp>

namespace bgl
{

class VideoMode
{
public:
    VideoMode() = default;
    explicit VideoMode(const V2u& modeSize, u32 modeBitsPerPixel = 32);

    static VideoMode GetDesktopMode();
    static const std::vector<VideoMode>& GetFullscreenModes();

    bool IsValid() const;

    V2u size;
    u32 bitsPerPixel{};
};

bool operator==(const VideoMode& left, const VideoMode& right);
bool operator!=(const VideoMode& left, const VideoMode& right);
bool operator<(const VideoMode& left, const VideoMode& right);
bool operator>(const VideoMode& left, const VideoMode& right);
bool operator<=(const VideoMode& left, const VideoMode& right);
bool operator>=(const VideoMode& left, const VideoMode& right);

} //namespace bgl
