#ifndef PLATTIS_WINDOW_HH
#define PLATTIS_WINDOW_HH

/// This class creates SDL2 window and adds SDL2 settings

#include "vector2.hh"

#include <SDL2/SDL.h>

#include <string>

namespace plattis
{

class Window
{
public:
    /// Constructor.
    /// Create window.
    Window(const std::string& title);

    /// Destructor.
    /// Free SDL2 resources.
    ~Window();

    /// Check if SDL2 instance is valid.
    /// \return bool Valid instance.
    bool valid() { return m_window; }

    /// Set new window size and return old size.
    /// \param newSize New size of the window.
    Vec2i swapSize(Vec2i newSize);

    /// Get window size.
    /// \return platis::Vec2i& Window size.
    Vec2i& getSize() { return m_size; }

    /// Get's the width of the window.
    /// \return int Width of the window.
    int getSizeX() { return m_size.x; }

    /// Get's the height of the window.
    /// \return int Height of the window.
    int getSizeY() { return m_size.y; }

    /// Get the window pointer.
    /// \return SDL_Window* The SDL window.
    SDL_Window* getWindow() { return m_window; }

private:
    Vec2i m_size;
    SDL_Window* m_window;
};

}

#endif
