#pragma once

#include <memory>
#include <optional>

#include <BGL/System/types.hpp>
#include <BGL/System/Vector2.hpp>
#include <BGL/Window/WindowEnums.hpp>
#include <BGL/Window/WindowHandle.hpp>

namespace bgl
{
class Cursor;
class String;
class VideoMode;

namespace priv
{
class WindowImpl;
} // namespace priv

class Event;

class WindowBase
{
public:
    WindowBase();
    WindowBase(VideoMode mode, const String& title, u32 style = Style::Default, State state = State::Windowed);
    WindowBase(VideoMode mode, const String& title, State state);
    explicit WindowBase(WindowHandle handle);
    virtual ~WindowBase();
    WindowBase(const WindowBase&) = delete;
    WindowBase& operator=(const WindowBase&) = delete;

    virtual void Create(VideoMode mode,
                        const String& title,
                        u32 style = Style::Default,
                        State state = State::Windowed);
    virtual void Create(WindowHandle handle);
    virtual void Close();
    bool IsOpen() const;
    [[nodiscard]] bool PollEvent(Event& event);
    [[nodiscard]] bool WaitEvent(Event& event);
    V2i GetPosition() const;
    void SetPosition(const V2i& position);
    V2u GetSize() const;
    void SetSize(const V2u& size);
    void SetMinimumSize(const std::optional<V2u>& minimumSize);
    void SetMaximumSize(const std::optional<V2u>& maximumSize);
    void SetTitle(const String& title);
    void SetIcon(const V2u& size, const u8* pixels);
    void SetVisible(bool visible);
    void SetMouseCursorVisible(bool visible);
    void SetMouseCursorGrabbed(bool grabbed);
    void SetMouseCursor(const Cursor& cursor);
    void SetKeyRepeatEnabled(bool enabled);
    void RequestFocus();
    bool HasFocus() const;
    WindowHandle GetNativeHandle() const;
protected:
    virtual void onCreate();
    virtual void onResize();
private:
    friend class Window;
    void create(VideoMode mode, u32& style, State& state);
    void filterEvent(const Event& event);
    void initialize();
    const WindowBase* getFullscreenWindow();
    void setFullscreenWindow(const WindowBase* window);
private:
    std::unique_ptr<priv::WindowImpl> mImpl;
    V2u mSize;
};

}